'use strict'

const childProcess = require('child_process')
const processDataEdit = require('../process-data').edit
const getByProcessName = require('../process-data').getByProcessName
const logger = require('../../services/logger.js')

const all = () => {
  const stop = []
  const processData = require('../process-data').getAll()

  return Promise.all(Object.keys(processData).map((processGroupName) => {
    return Promise.all(Object.keys(processData[processGroupName]).map((processName, index) => {
      const processGroupLength = Object.keys(processData[processGroupName]).length
      const _process = processData[processGroupName][processName]

      if (_process.status === 'RUNNING' || _process.status === 'STARTING') {
        processDataEdit({killedByMe: true}, processGroupName, processName)
        const processCopy = {..._process['process']}
        delete _process['process']

        processCopy.send(_process)
        _process['process'] = processCopy
        return new Promise((resolve, reject) => {
          childProcess.exec(`kill -${_process.config.stopsignal} ${_process.pid}`, () => {
            childProcess.exec(`kill -0 ${_process.pid}`, (err, stdout, stderr) => {
              if (!err) {
                logger.write('INFO', `Waiting for the ${processName} with pid: ${_process.pid} to stop`)
                timeout(_process.pid, _process.config.stopwaitsecs)
              } else {
                stop.push(`${processGroupLength === 1 ? '' : processGroupName + ':'}${processName}: STOPPED`)
                logger.write('INFO', `stopped [${processName}] (terminated by ${_process.config.stopsignal})`)
              }
              return resolve()
            })
          })
        })
      } else {
        stop.push(`${processName + ':'} ERROR (already stopped)`)
        return Promise.resolve()
      }
    }))
  }))
  .then(() => Promise.resolve(stop.join('\n')))
}

const one = (processNamesOrGroupName) => {
  const stop = []
  const processData = require('../process-data').getAll()

  return Promise.all(processNamesOrGroupName.map((processNameOrGroupName) => {
    if (processData[processNameOrGroupName]) {
      return Promise.all(Object.keys(processData[processNameOrGroupName]).map((processName, index) => {
        const processGroupLength = Object.keys(processData[processNameOrGroupName]).length
        const _process = processData[processNameOrGroupName][processName]

      	if (_process.status === 'RUNNING' || _process.status === 'STARTING') {
          processDataEdit({killedByMe: true}, processNameOrGroupName, processName)
          const processCopy = _process['process']
          delete _process['process']

          processCopy.send(_process)
          _process['process'] = processCopy
          return new Promise((resolve, reject) => {
            childProcess.exec(`kill -${_process.config.stopsignal} ${_process.pid}`, () => {
              childProcess.exec(`kill -0 ${_process.pid}`, (err, stdout, stderr) => {
                if (!err) {
                  logger.write('INFO', `Waiting for the ${processName} with pid: ${_process.pid} to stop`)
                  timeout(_process.pid, _process.config.stopwaitsecs)
                } else {
                  stop.push(`${processGroupLength === 1 ? '' : processNameOrGroupName + ':'}${processName}: STOPPED`)
                  logger.write('INFO', `stopped [${processName}] (terminated by ${_process.config.stopsignal})`)
                }
                return resolve()
              })
            })
          })
        } else {
          stop.push(`${processName + ':'} ERROR (already stopped)`)
          return Promise.resolve()
        }
      }))
    } else {
      const processInfos = getByProcessName(processNameOrGroupName)

      if (processInfos) {
        const processDataFound = processInfos[1]

      if (processDataFound.status === 'RUNNING' || processDataFound.status === 'STARTING') {
          processDataEdit({killedByMe: true}, processInfos[0], processNameOrGroupName)
          const processCopy = processDataFound['process']
          delete processDataFound['process']

          processCopy.send(processDataFound)
          return new Promise((resolve, reject) => {
            childProcess.exec(`kill -${processDataFound.config.stopsignal} ${processDataFound.pid}`, () => {
              childProcess.exec(`kill -0 ${processDataFound.pid}`, (err, stdout, stderr) => {
                if (!err) {
                  logger.write('INFO', `Waiting for the ${processNameOrGroupName} with pid: ${processDataFound.pid} to stop`)
                  timeout(processDataFound.pid, processDataFound.config.stopwaitsecs)
                } else {
                  stop.push(`${processNameOrGroupName}: STOPPED`)
                  logger.write('INFO', `stopped [${processNameOrGroupName}] (terminated by ${processDataFound.config.stopsignal})`)
                }
                return resolve()
              })
            })
          })
        } else {
          stop.push(`${processNameOrGroupName + ':'} ERROR (already stopped)`)
          return Promise.resolve()
        }
      } else {
        stop.push(`${processNameOrGroupName}: ERROR (no such process)`)
        return Promise.resolve()
      }
    }
  }))
  .then(() => Promise.resolve(stop.join('\n')))
}

const timeout = (pid, stopwaitsecs) => {
  return setTimeout(() => {
    childProcess.spawn(`kill -9 ${pid}`, [], {detached: true, shell: true})
  }, stopwaitsecs * 1000)
}

module.exports = {
  all,
  one
}

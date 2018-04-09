'use strict'

const getByProcessName = require('../process-data').getByProcessName
const _process = require('../process')

const all = (restart) => {
  const start = []
  const processData = require('../process-data').getAll()

  Object.keys(processData).map((processGroupName) => {
    Object.keys(processData[processGroupName]).map((processName, index) => {
      const processStatus = processData[processGroupName][processName].status

      if (processStatus === 'FATAL' || processStatus === 'STOPPED' || processStatus === 'EXITED' || restart) {
        _process.launcher(processData[processGroupName][processName], processGroupName, processData[processGroupName][processName].config.startretries, index)
        start.push(`${processName}: STARTED`)
      } else if (processStatus === 'RUNNING') start.push(`${processName}: is already RUNNING`)
    })
  })
  return Promise.resolve(start.join('\n'))
}

const one = (processNamesOrGroupName, restart) => {
  const start = []
  const processData = require('../process-data').getAll()

  processNamesOrGroupName.map((processNameOrGroupName) => {
    if (processData[processNameOrGroupName]) {
      Object.keys(processData[processNameOrGroupName]).map((processName, index) => {
        const processStatus = processData[processNameOrGroupName][processName].status

        if (processStatus === 'FATAL' || processStatus === 'STOPPED' || processStatus === 'EXITED' || restart) {
					_process.launcher(processData[processNameOrGroupName][processName], processNameOrGroupName, processData[processNameOrGroupName][processName].config.startretries, index)
          start.push(`${processName}: STARTED`)
        } else if (processStatus === 'RUNNING') start.push(`${processName}: is already RUNNING`)
      })
    } else {
      const processInfos = getByProcessName(processNameOrGroupName)

      if (processInfos) {
        const processDataFound = processInfos[1]

        if (processDataFound.status === 'FATAL' || processDataFound.status === 'STOPPED' || processDataFound.status === 'EXITED' || restart) {
          _process.launcher(processDataFound, processInfos[0], processDataFound.config.startretries, processInfos[2])
          start.push(`${processNameOrGroupName}: STARTED`)
        } else if (processDataFound.status === 'RUNNING') start.push(`${processNameOrGroupName}: is already RUNNING`)
      } else start.push(`${processNameOrGroupName}: ERROR (no such process)`)
    }
  })
  return Promise.resolve(start.join('\n'))
}

module.exports = {
  all,
  one
}

'use strict'

const getByProcessName = require('../process-data').getByProcessName

const getUpTime = (time) => {
  const timeDiff = Date.now() - time
  const secondesCalcul = parseInt((timeDiff / 1000) % 60)
  const minutesCalcul = parseInt((timeDiff / (1000 * 60)) % 60)
  const hoursCalcul = parseInt((timeDiff / (1000 * 60 * 60)) % 24)
  const secondes = secondesCalcul >= 10 ? secondesCalcul % 60 : `0${secondesCalcul}`
  const minutes = minutesCalcul >= 10 ? minutesCalcul % 60 : `0${minutesCalcul}`
  const hours = hoursCalcul >= 10 ? hoursCalcul % 60 : `0${hoursCalcul}`

  return [hours, minutes, secondes]
}

const getStatus = (_process, processGroupLength, processGroupName, processName) => {
  const statusName = processGroupLength === 1 ? '' : processGroupName + ':'
  if (_process.status === 'FATAL') return `${statusName}${processName}\t${_process.status}\t\tExited too quickly (process log may have details)`

  const time = _process.status === 'EXITED' || _process.status === 'STOPPED'
  ? new Date(_process.exitdate).toString().split(' ').slice(0, 5).join(' ')
  : getUpTime(_process.time)

  if (_process.status === 'EXITED' || _process.status === 'STOPPED') {
    return `${statusName}${processName}\t${_process.status}\t\t${time}`
  } else if (_process.status === 'STOPPED' && !_process.pid) {
    return `${statusName}${processName}\t${_process.status}\t\tNot started`
  } else if (_process.status === 'STARTING') return `${statusName}${processName}\t${_process.status}`
  else return `${statusName}${processName}\t${_process.status}\t\tpid ${_process.pid}, uptime ${time[0]}:${time[1]}:${time[2]}`
}

const all = () => {
  const status = []
  const processData = require('../process-data').getAll()

  Object.keys(processData).map((processGroupName) => {
    const processGroupLength = Object.keys(processData[processGroupName]).length

    Object.keys(processData[processGroupName]).map((processName) => {
      const _process = processData[processGroupName][processName]
      status.push(getStatus(_process, processGroupLength, processGroupName, processName))
    })
  })
  return Promise.resolve(status.join('\n'))
}

const one = (processNamesOrGroupName) => {
  const status = []
  const processData = require('../process-data').getAll()

  processNamesOrGroupName.map((processNameOrGroupName) => {
    if (processData[processNameOrGroupName]) {
      const processGroupLength = Object.keys(processData[processNameOrGroupName]).length

      Object.keys(processData[processNameOrGroupName]).map((processName) => {
        const _process = processData[processNameOrGroupName][processName]
        status.push(getStatus(_process, processGroupLength, processNameOrGroupName, processName))
      })
    } else {
      const processInfos = getByProcessName(processNameOrGroupName)

      if (processInfos) {
        const processDataFound = processInfos[1]
        status.push(getStatus(processDataFound, 1, null, processNameOrGroupName))
      } else status.push(`${processNameOrGroupName}: ERROR (no such process)`)
    }
  })
  return Promise.resolve(status.join('\n'))
}

module.exports = {
  all,
  one
}

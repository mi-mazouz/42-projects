'use strict'

let processData = {}

const getAll = () => {
  return processData
}

const reload = () => {
  processData = {}
}

const initAll = (processConfig) => {
  Object.keys(processConfig).map((processGroupName) => {
    const numprocs = processConfig[processGroupName].numprocs
    if (!processData[processGroupName]) processData[processGroupName] = {}

    for (let index = 0; index < numprocs; index++) {
      processData[processGroupName][`${numprocs === 1 ? processGroupName : processGroupName + '_' + index}`] = {
        config: processConfig[processGroupName],
        'status': 'STOPPED',
        'killedByMe': false,
        'code': null,
        'signal': null,
        'pid': null,
        'ppid': null,
        'time': null,
        'exitdate': null
      }
    }
  })
}

const getByProcessName = (processName) => {
  for (const processGroupName in processData) {
    const processDataKeys = Object.keys(processData[processGroupName])
    if (processDataKeys.includes(processName)) {
      return [processGroupName, processData[processGroupName][processName], processDataKeys.indexOf(processName)]
    }
  }
  return null
}

const getByPid = (pid) => {
  Object.keys(processData).map((processGroupName) => {
    Object.keys(processData[processGroupName]).map((processName) => {
      if (processData[processGroupName][processName].pid === pid) return processData[processGroupName][processName]
    })
  })
  return null
}

const edit = (dataToEdit, processGroupName, processName) => {
  if (!processData[processGroupName] || !processData[processGroupName][processName]) return
  Object.keys(dataToEdit).map(key => {
    processData[processGroupName][processName][key] = dataToEdit[key]
  })
}

module.exports = {
  getByProcessName,
  getAll,
  getByPid,
  initAll,
  edit,
  reload
}

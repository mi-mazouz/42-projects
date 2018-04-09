'use strict'

const status = require('./status')
const start = require('./start')
const restart = require('./restart')
const stop = require('./stop')
const reload = require('./reload')

module.exports = {
  'status': (processNamesOrGroupName) => {
    return processNamesOrGroupName.length === 0 || processNamesOrGroupName[0] === 'all' ? status.all() : status.one(processNamesOrGroupName)
  },
  'start': (processNamesOrGroupName) => {
    return processNamesOrGroupName[0] === 'all' ? start.all() : start.one(processNamesOrGroupName)
  },
  'stop': (processNamesOrGroupName) => {
    return processNamesOrGroupName[0] === 'all' ? stop.all() : stop.one(processNamesOrGroupName)
  },
  'restart': (processNamesOrGroupName) => {
    return processNamesOrGroupName[0] === 'all' ? restart.all() : restart.one(processNamesOrGroupName)
  },
  'reload': (configFile) => reload(configFile.toString())
}

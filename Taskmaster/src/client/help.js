'use strict'

module.exports = {
  'start': () => {
    console.log('start <name/gname>\tStart a process or group')
    console.log('start all\t\tStart all processes and group')
  },
  'status': () => {
    console.log('status <name/gname>\tGet status for a single or group process')
    console.log('status \t\t\tGet all process status info')
  },
  'restart': () => {
    console.log('restart <name/gname>\tRestart a single or group process')
    console.log('restart all  \t\tRestart all process')
  },
  'stop': () => {
    console.log('stop <name/gname>\tStop a single or group process')
    console.log('stop \t\t\tStop all process')
  },
  'help': () => {
    console.log('\ndefault commands (type help <topic>):')
    console.log('=====================================')
    console.log('status\t\tstart\t\tstop')
    console.log('restart\t\treload\t\tshutdown\n')
  },
  'shutdown': () => {
    console.log('shutdown \t\tShut the remote taskmaster down')
  },
  'reload': () => {
    console.log('reload <config file>\tRestart the remote taskmaster.')
  },
  'error': (str) => {
    console.log(`*** No help on ${str}`)
  }
}

'use strict'

const help = require('./help')

const checkCommand = (command) => {
  if (command.length === 2) return command
  else if (command.length > 2) {
    console.error(`Error: ${command[0]} does not allow multiple arguments`)
    help[command[0]]()
    return null
  } else {
    console.error(`Error: ${command[0]} requires a process name`)
    help[command[0]]()
    return null
  }
}

module.exports = {
  'status': (argv) => argv,
  'exit': (argv) => process.exit(0),
  'start': (argv) => checkCommand(argv),
  'stop': (argv) => checkCommand(argv),
  'restart': (argv) => checkCommand(argv),
  'reload': (argv) => {
    if (argv.length !== 2) {
      console.error(`Error: reload requires a configuration file [JSON]`)
      help[argv[0]]()
      return null
    } else return argv
  },
  'shutdown': (argv) => {
    if (argv[1]) {
      console.error(`Error: ${argv[0]} don't allows any arguments`)
      help[argv[0]]()
      return null
    } else return argv
  },
  'help': (argv) => {
    if (argv.length === 1) help[argv[0]]()
    else if (argv.length > 2) help['error'](argv.join(' '))
    else help[argv[1]] ? help[argv[1]]() : help['error'](argv[1])
  },
  'error': (argv) => {
    console.error(`*** Unknown syntax: ${argv[0]}`)
  }
}

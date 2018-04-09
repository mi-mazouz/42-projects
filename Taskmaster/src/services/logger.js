'use strict'

const fs = require('fs')

const FILEPATH = '/tmp/taskmaster.log'

const getDate = () => {
  return new Date().toISOString().replace(/T/, ' ').replace(/\..+/, '')
}

const log = {
  'INIT': (str) => {
    if (fs.existsSync(FILEPATH) === true) return `\n\x1b[32mNEW INSTANCE\x1b[0m\n`
    else return `\x1b[32mNEW INSTANCE\x1b[0m\n`
  },
  'INFO': (str) => `${getDate()} INFO: ${str}\n`,
  'WARN': (str) => `${getDate()} \x1b[33mWARN\x1b[0m: ${str}\n`,
  'FATAL': (str) => `${getDate()} \x1b[31mFATAL\x1b[0m: ${str}\n`
}

const write = (code, str) => {
  return new Promise((resolve, reject) => {
	  fs.appendFile(FILEPATH, log[code](str), 'utf8', (err) => {
		  if (err) {
			  console.error('taskmaster: error in creation of the logger')
			  process.exit(1)
		  }
		  resolve()
	  })
  })
}

module.exports = {
  write
}

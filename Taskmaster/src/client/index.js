'use strict'

const net = require('net')
const readline = require('readline')

const controller = require('./controller')
const config = require('../config')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  prompt: 'taskmaster> '
})

const client = net.createConnection(config.PORT, config.HOST, () => {
  rl.on('line', (line) => {
    if (line) {
      const argv = line.trim().split(' ')

      if (!controller[argv[0]]) {
        controller['error'](argv)
        rl.prompt()
      } else {
        const commandToSend = controller[argv[0]](argv.filter((item, index) => argv.indexOf(item) === index))

        if (commandToSend) client.write(JSON.stringify(commandToSend))
        else rl.prompt()
      }
    } else rl.prompt()
  })

  rl.on('SIGINT', () => {
    client.destroy()
    process.exit(1)
  })
})

client.on('error', (error) => {
  if (error.errno === 'ECONNREFUSED') {
    console.error('error: ECONNREFUSED Connection refused by the server')
  } else console.log(`error: ${error}`)

  process.exit(1)
})

client.on('data', (data) => {
  if (data.toString() !== 'No result') console.log(data.toString())
  rl.prompt()
})

client.on('end', (end) => {
  readline.clearLine(rl, 0)
  readline.cursorTo(rl, 0)
  process.exit(0)
})

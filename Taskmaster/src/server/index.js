'use strict'

const net = require('net')

const config = require('../config')
const configParser = require('./parser')
const processData = require('./process-data')
const _process = require('./process')
const controller = require('./controllers')
const stopAll = require('./controllers/stop').all
const restartAll = require('./controllers/restart').all
const logger = require('../services/logger')
const status = require('./controllers/status')

if (process.argv.length !== 3) {
  console.error('usage: npm run start:server [configuration file]')
  process.exit(1)
}

logger.write('INIT')
logger.write('INFO', `supervisord started with pid [${process.pid}]`)

configParser(process.argv[2])
.then((configParsed) => {
  processData.initAll(configParsed)
  _process.init()
})
.catch((err) => {
	if (err.details)
		console.error(`error: config.json: ${err.details[0].message}`)
	else
		console.error(`error: ${err.message}`)
	process.exit(1)
})

const server = net.createServer((socket) => {
  socket.server.getConnections((err, numberOfConnections) => {
    if (numberOfConnections > 1) {
      socket.write(`taskmaster: only one connection is allowed on [${socket.remoteAddress}:${socket.remotePort}]`)
      socket.destroy()
    } else if (err) {
      socket.write('taskmaster: error to get number of connections')
      socket.destroy()
    }
    let ping = true

    logger.write('INFO', `new connection from [${socket.remoteAddress}:${socket.remotePort}]`)
    status.all()
    .then((ret) => { if (ping) socket.write(ret) })

    socket.on('data', (data) => {
      const command = JSON.parse(data)

      if (command[0] === 'shutdown') {
        logger.write('INFO', `connection to the server stopped from [${socket.remoteAddress}:${socket.remotePort}]`)
        stopAll()
        .then(() => process.exit(0))
      } else {
        controller[command[0]](command.slice(1))
        .then((resultToSend) => {
          if (ping) {
            if (!resultToSend) socket.write('No result')
            else socket.write(resultToSend)
          }
        })
        .catch((err) => socket.write(err.message))
      }
    })

    socket.on('end', () => {
      ping = false
      logger.write('WARN', `lost connection from [${socket.remoteAddress}:${socket.remotePort}]`)
    })
  })
})

server.listen(8000, () => {
  logger.write('INFO', `server is running on PORT [${config.PORT}]`)
})

server.on("error", (err) => {
	if (err.errno === 'EADDRINUSE')
		console.error('error: EADDRINUSE address already in use')
	else
		console.error(`error: ${err}`)
})

process.on('SIGTERM', () => {
	logger.write("WARN", `received SIGTERM indicating exit request`)
	stopAll()
})

process.on('SIGQUIT', () => {
	logger.write("WARN", `received SIGQUIT indicating exit request`)
	stopAll()
})

process.on('SIGHUP', () => {
	logger.write("WARN", `received SIGHUP indicating restart request`)
	restartAll()
})

process.on('SIGUSR2', () => {
	logger.write("WARN", `received SIGUSR2 indicating log reopen request`)
	logger.write("INFO", `supervisord logreopen`)
})

'use strict'

const childProcess = require('child_process')

const processDataEdit = require('./process-data').edit
const logger = require('../services/logger')

const getSpawnOptions = (processConfig) => ({
  'shell': true,
  'env': processConfig.config.env,
  'cwd': processConfig.config.directory
})

const getIoOptions = (processConfig) => ({
  'stderr_logfile': processConfig.config.stderr_logfile,
  'stdout_logfile': processConfig.config.stdout_logfile
})

const processEventsInit = (_process, processConfig, processGroupName, startRetries, processNum) => {
	const processGroupLength = processConfig.config.numprocs
	const processData = require('./process-data').getAll()

	_process.on('message', (processInfo) => {
		if (startRetries === 0 && processInfo.status === 'FATAL') {
			logger.write("INFO", `gave up [${processConfig.config.command}] after max startretries`)
		}
		
		const autorestart = processConfig.config.autorestart
		const exitcodes = processConfig.config.exitcodes
		
		if (startRetries > 0 && processInfo.status === 'FATAL') launcher(processConfig, processGroupName, startRetries - 1, processNum)
		else if (processInfo.status === 'EXITED' && autorestart === 'always') launcher(processConfig, processGroupName, startRetries, processNum)
		else if (processInfo.status === 'EXITED' && autorestart === 'unexpected' && !exitcodes.includes(processInfo.code)) {
			launcher(processConfig, processGroupName, startRetries, processNum)
		} else {
			if (!processData[processGroupName]) processData[processGroupName] = {}
			
			const processDataInfo = processData[processGroupName][`${processGroupLength === 1 ? processGroupName : processGroupName + '_' + processNum}`]
			processDataEdit(processInfo, processGroupName, `${processGroupLength === 1 ? processGroupName : processGroupName + '_' + processNum}`)
			
			delete processDataInfo['process']
			_process.send(processDataInfo)
			processDataInfo['process'] = _process
		}
	})
}

const launcher = (processConfig, processGroupName, startRetries, processNum) => {
	const spawnOptions = JSON.stringify(getSpawnOptions(processConfig))
	const ioOptions = JSON.stringify(getIoOptions(processConfig))

	const _process = childProcess.fork('./src/server/child-process', [
		processConfig.config.command,
		spawnOptions,
		ioOptions,
		processConfig.config.umask,
		processConfig.config.startsecs
	])
	processEventsInit(_process, processConfig, processGroupName, startRetries, processNum)
}

const init = () => {
	const processData = require('./process-data').getAll()
	
	Object.keys(processData).map((processGroupName) => {
		Object.keys(processData[processGroupName]).map((processName, index) => {
			const config = processData[processGroupName][processName].config
			
			if (config.autostart) {
				launcher(processData[processGroupName][processName], processGroupName, config.startretries, index)
			}
		})
	})
}

module.exports = {
	init,
	launcher
}

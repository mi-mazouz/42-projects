const jsonfile = require('jsonfile')
const joi = require('joi')

const signalCode = require('../signal-codes')

const schema = joi.object().keys({
  command: joi.string().required(),
  numprocs: joi.number().integer().min(1).default(1),
  autostart: joi.boolean().default(true),
  autorestart: joi.string().valid(['always', 'never', 'unexpected']).default('unexpected'),
  stopwaitsecs: joi.number().integer().min(0).default(10),
  exitcodes: joi.array().items(joi.number().integer()).min(1).default([0, 2]),
  startretries: joi.number().integer().min(0).default(3),
  startsecs: joi.number().integer().min(0).default(1),
  stdout_logfile: joi.string().default(null),
  stderr_logfile: joi.string().default(null),
  umask: joi.string().regex(/^[0-7]{1,3}$/).default('022'),
  directory: joi.string().default(null),
  env: joi.object().default(null),
  stopsignal: joi.number().integer().valid([
    signalCode.SIGTERM,
    signalCode.SIGINT,
    signalCode.SIGQUIT,
    signalCode.SIGHUP,
    signalCode.SIGUSR2
  ]).default(signalCode.SIGTERM)
})

module.exports = (filePath) => {
	return new Promise((resolve, reject) => {
		jsonfile.readFile(filePath, (err, config) => {
			if (err) return reject(err)
			
			joi.validate(config, joi.object().min(1))
			.then(() => {
				const configParsed = {}
				
				Promise.all(Object.keys(config).map((processName) => {
					return joi.validate(config[processName], schema)
					.then((value) => {
						configParsed[processName] = value
						return Promise.resolve(configParsed)
					})
				.catch((err) => reject(err))
				}))
				.then(([configParsed]) => resolve(configParsed))
				.catch((err) => reject(err))
			})
			.catch((err) => reject(err))
		})
	})
}

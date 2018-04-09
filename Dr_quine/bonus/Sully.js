const fs=require('fs')
var i=5
if (i<=0) process.exit()
try {
fs.openSync('Sully_'+i+'.js', 'r')
i--
}catch(err){}
const main=() => {
try {
fs.writeFile('Sully_' + i + '.js', `const fs=require('fs')
var i=` + i + `
if (i<=0) process.exit()
try {
fs.openSync('Sully_'+i+'.js', 'r')
i--
}catch(err){}
const main=` + main.toString() +`
main()
`, ()=>{
const { exec } = require('child_process')
exec('node ./Sully_'+i+'.js', () => {})
})}catch(err){process.exit()}
}
main()

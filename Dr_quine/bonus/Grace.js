/*
	A comment.
*/
const FILE='Grace_kid.js'
const FS=require('fs')
const MAIN=()=>{
try{
FS.writeFile(FILE, `/*
	A comment.
*/
const FILE='Grace_kid.js'
const FS=require('fs')
const MAIN=` + MAIN.toString() + `
MAIN()
`, () => {})}
catch(err){process.exit()}
}
MAIN()

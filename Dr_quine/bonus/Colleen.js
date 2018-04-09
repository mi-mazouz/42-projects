/*
	You're outside of any functions.
*/
const toCall=()=>{};const main=()=>{
/*
	You're in the main function.
*/
toCall();const s = `/*
	You're outside of any functions.
*/
const toCall=` + toCall.toString() + `;const main=` + main.toString() + `;main()`
console.log(s)
};main()

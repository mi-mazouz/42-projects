const navMenu = document.querySelector('#navMenu')
const navBurger = document.querySelector('#navBurger')
const navDropDown = document.querySelector('#navDropDown')

navBurger.addEventListener('click', () => {
    if (navBurger.classList.contains('is-active')) {
        navMenu.classList.remove('is-active')
        navBurger.classList.remove('is-active')        
    } else {
        navMenu.classList.add('is-active')
        navBurger.classList.add('is-active')
    }
})

if (navDropDown) {
    navDropDown.addEventListener('mouseover', () => {
        navDropDown.classList.add('is-active')
    })
    navDropDown.addEventListener('mouseout', () => {
        navDropDown.classList.remove('is-active')
    })
}

const facesDropDown = document.querySelector('#facesDropDown')

facesDropDown.addEventListener('click', () => {
  if (facesDropDown.classList.contains('is-active')) {
    facesDropDown.classList.remove('is-active')
  } else {
    facesDropDown.classList.add('is-active')
    glassesDropDown.classList.remove('is-active')
    fruitsDropDown.classList.remove('is-active')
  }
})

const glassesDropDown = document.querySelector('#glassesDropDown')
glassesDropDown.addEventListener('click', () => {
  if (glassesDropDown.classList.contains('is-active')) {
    glassesDropDown.classList.remove('is-active')
  } else {
    glassesDropDown.classList.add('is-active')
    facesDropDown.classList.remove('is-active')
    fruitsDropDown.classList.remove('is-active')
  }
})

const fruitsDropDown = document.querySelector('#fruitsDropDown')
fruitsDropDown.addEventListener('click', () => {
  if (fruitsDropDown.classList.contains('is-active')) {
    fruitsDropDown.classList.remove('is-active')
  } else {
    fruitsDropDown.classList.add('is-active')
    facesDropDown.classList.remove('is-active')
    glassesDropDown.classList.remove('is-active')
  }
})
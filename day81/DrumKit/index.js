// alert("Hello Bhanu!");

// document.querySelector('button.w').addEventListener("click", handleClick);
// document.querySelector('button.a').addEventListener("click", handleClick);
// document.querySelector('button.s').addEventListener("click", handleClick);
// document.querySelector('button.d').addEventListener("click", handleClick);
// document.querySelector('button.j').addEventListener("click", handleClick);
// document.querySelector('button.k').addEventListener("click", handleClick);
// document.querySelector('button.l').addEventListener("click", handleClick);

let numberofDrumButtons = document.querySelectorAll(".drum").length;
for (let i = 0; i < numberofDrumButtons; i++) {
    document.querySelectorAll(".drum")[i].addEventListener("click", handleClick);
}

function handleClick() {
    // alert('I am clicked');
    let buttonEvent = this.innerHTML;
    console.log(buttonEvent);
    let audio;
    switch (buttonEvent) {
        case 'w':
            audio = new Audio('./sounds/snare.mp3');
            audio.play();
            break;
        case 'a':
            audio = new Audio('./sounds/tom-1.mp3');
            audio.play();
            break;
        case 's':
            audio = new Audio('./sounds/tom-2.mp3');
            audio.play();
            break;
        case 'd':
            audio = new Audio('./sounds/tom-3.mp3');
            audio.play();
            break;
        case 'j':
            audio = new Audio('./sounds/tom-4.mp3');
            audio.play();
            break;
        case 'k':
            audio = new Audio('./sounds/crash.mp3');
            audio.play();
            break;
        case 'l':
            audio = new Audio('./sounds/kick-bass.mp3');
            audio.play();
            break;

        default:
            console.log("No event")

    }

    // let audio = new Audio('./sounds/tom-2.mp3');
    // audio.play();

    // animate button now
    buttonAnimation(buttonEvent);
    console.log(":hi")
}

document.addEventListener("keypress", function(event) {
    makeSound(event.key);
    buttonAnimation(event.key);
});

function makeSound(key) {

    console.log(key);
    let audio;
    switch (key) {
        case 'w':
            audio = new Audio('./sounds/snare.mp3');
            audio.play();
            break;
        case 'a':
            audio = new Audio('./sounds/tom-1.mp3');
            audio.play();
            break;
        case 's':
            audio = new Audio('./sounds/tom-2.mp3');
            audio.play();
            break;
        case 'd':
            audio = new Audio('./sounds/tom-3.mp3');
            audio.play();
            break;
        case 'j':
            audio = new Audio('./sounds/tom-4.mp3');
            audio.play();
            break;
        case 'k':
            audio = new Audio('./sounds/crash.mp3');
            audio.play();
            break;
        case 'l':
            audio = new Audio('./sounds/kick-bass.mp3');
            audio.play();
            break;

        default:
            console.log("No event")

    }

    // let audio = new Audio('./sounds/tom-2.mp3');
    // audio.play();
}

function buttonAnimation(actionKey) {
    console.log(actionKey);
    let activeButton = document.querySelector("." + actionKey);
    console.log(activeButton)
    activeButton.classList.add('pressed');
    setTimeout(function() {
        activeButton.classList.remove('pressed');
    }, 100);
}
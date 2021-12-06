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
    alert('I am clicked');
}
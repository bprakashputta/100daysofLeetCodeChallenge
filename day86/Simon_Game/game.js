let buttonColours = ["red", "blue", "green", "yellow"]
let gamePattern = [];
let userClickedPattern = [];

let level = 0;
let started = false;
$(document).on('keypress', function() {
    // start game
    if (!started) {
        started = true;
        $("h1").text("Level " + level);
        nextSequence();
        // initialFlash(gamePattern[gamePattern.length - 1]);
        playGame();
    }
});

$(".btn").on("click", function() {
    let userChoosenColour = this.id;
    userClickedPattern.push(userChoosenColour);
    playGame(userClickedPattern.length - 1);
});


function playGame(currentLevel) {
    // Step 2: User should remember the Entire pattern
    // and should click them in order
    if (userClickedPattern[currentLevel] == gamePattern[currentLevel]) {
        if (userClickedPattern.length == gamePattern.length) {
            playSound(this.id);
            animatePress(this.id);
            setTimeout(function() {
                nextSequence();
            }, 500);
        }
    } else {
        playSound("wrong");
        $("body").addClass("game-over");
        $("#level-title").text("Game Over, Press Any Key to Restart");

        setTimeout(function() {
            $("body").removeClass("game-over");
        }, 200);

        startOver();
    }
}

function initialFlash(flashButton) {
    $("." + flashButton).addClass("pressed");
    setTimeout(function() { $("." + flashButton).removeClass("pressed") }, 50);
    $("." + flashButton).fadeOut(100).fadeIn(50);
}

function nextSequence() {
    userClickedPattern = [];
    level++;
    $("h1").text("Level " + level);
    let randomSequence = Math.floor(Math.random() * 4);
    // console.log(randomSequence);
    let randomChoosenColour = buttonColours[randomSequence];
    // console.log(randomChoosenColour);
    gamePattern.push(randomChoosenColour);
    // console.log(gamePattern);

    initialFlash(randomChoosenColour);
}

function playSound(buttonClicked) {
    let audio = new Audio("./sounds/" + buttonClicked + ".mp3");
    audio.play();
}

function animatePress(buttonClicked) {
    $("." + buttonClicked).addClass("pressed");
    setTimeout(function() { $("." + buttonClicked).removeClass("pressed") }, 100);
    $("." + buttonClicked).fadeOut(100).fadeIn(50);
}

function startOver() {
    level = 0;
    gamePattern = [];
    started = false;
}
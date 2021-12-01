/**
 * Welcome to the Stanford Karel IDE.
 * This is a free space for you to 
 * write any Karel program you want.
 **/
function main() {
    //your code here
    while (frontIsClear() && leftIsClear()) {
        putBeeper();
        move();
        turnLeft();
        move();
        turnRight();
    }
    putBeeper();
}
function SumofMarks() {
    let marks = [];
    for (let i = 0; i < 10; i++) {
        marks.push(1 + Math.floor(Math.random * 30));
    }
    let i = 0;
    let sum = 0;
    while (i < 10) {
        sum += marks[i];
        i++;
    }
    console.log(sum);
    return sum;
}
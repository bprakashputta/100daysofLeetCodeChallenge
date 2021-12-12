function CompoundInterest() {
    let P = 1000,
        r = 10,
        t = 2,
        n = 3;

    let A = P * Math.pow(1 + (r / n), n * t);
    console.log(A);
    return A;
}
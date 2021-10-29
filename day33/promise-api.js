const p1 = new Promise(resolve => {
    setTimeout(()=>{
        console.log("Process p1");
        resolve(1);
    },2000);
});
console.log("help")
const p2 = new Promise(resolve => {
    setTimeout(()=>{
        console.log("Process p2");
        resolve(2);
    },2000);
});

Promise.all([p1,p2])
    .then(result => console.log(result));


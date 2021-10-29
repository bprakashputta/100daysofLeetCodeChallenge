const p = new Promise((resolve, reject) => {
    console.log("Putta");
    setTimeout(()=>{
        // resolve("Bhanu");
        reject(new Error("message"));
    }, 2000);
    console.log("Prakash");
});

p.then(result => {
   console.log("Result: ", result);
}).catch(error => {
    console.log("Error: ", error);
});
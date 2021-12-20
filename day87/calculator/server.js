const express = require('express');
const bodyparser = require('body-parser');
const { request, response } = require('express');
const app = express();
const PORT = 3000;

app.use(bodyparser.urlencoded({ extended: true }));

app.get('/', (request, response) => {
    return response.sendFile(__dirname + "/index.html");
});

app.get('/bmi', (request, response) => {
    return response.sendFile(__dirname + "/bmi.html");
});

app.post('/bmi', (request, response) => {
    let weight = Number(request.body.weight);
    let height = Number(request.body.height) / 100;
    let BMI = weight / (height * height);
    return response.send("Your BMI is " + BMI);
})

app.post('/', (request, response) => {
    let num1 = request.body.num1;
    let num2 = request.body.num2;
    return response.send("Thanks for posting, sum of num1 and num2 is " + (Number(num1) + Number(num2)));
})

app.listen(PORT, () => {
    console.log("Server is listening on PORT 3000");
})
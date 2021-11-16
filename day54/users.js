const mongoose = require('mongoose');
const express = require('express');
const {request, response} = require("express");
const userRouter = express.Router();
const {User, userschema, validate} = require('../models/user');
// User route to bring list of all Users
userRouter.get('/', async (request, response)=>{

});

userRouter.post('/signup', async (request, response)=>{
    // Step 1: Check if the request body contains a valid user object
    const { error } = await validate(request.body);
    if(error){
       return response.status(400).send(error.message);
    }

    // Step 2: Check if a user with that particular username already exists
    let user = await User.findOne({username: request.body.username});
    if(user){
        return response.status(400).send("User with given username already exists");
    }else{
        try {
            user = await new User({
                username: request.body.username,
                email: request.body.email,
                password: request.body.password,
                gender: request.body.gender,
                dateofbirth: request.body.dateofbirth,
                phonenumber: request.body.phonenumber
            });
            console.log("New User: ", user);
            await user.save();
        }catch (ex){
            console.log(ex.error);
        }
    }
    return response.send(user);
});

module.exports = userRouter;
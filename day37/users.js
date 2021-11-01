const mongoose = require('mongoose');
const bcryt = require('bcrypt');
const express = require('express');
const Joi = require("joi");
const userRouter = express.Router();
const {User, validate} =require('../models/user');




// GET METHOD to READ list of users
userRouter.post('/',async (request, response)=>{
    const {error} =await validate(request.body);
    if(error){
        return response.status(400).send(error.details[0].message);
    }

    let user = User.findOne({email: request.body.email});
    if(!user){
        return response.status(400).send("User already exists");
    }
    user = new User({
        name: request.body.name,
        email: request.body.email,
        password: request.body.password
    });
    const salt = await bcryt.genSalt(10);
    user.password = await bcryt.hash(user.password, salt);
    try {
        await user.save();
    }catch (ex){
        console.log(ex.error);
    }

    return response.send({
        name: request.body.name,
        email: request.body.email,
    });
});

module.exports = userRouter;
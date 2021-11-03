const jwt = require('jsonwebtoken');
const mongoose = require('mongoose');
const bcryt = require('bcrypt');
const express = require('express');
const Joi = require("joi");
const userRouter = express.Router();
const {User} =require('../models/user');
const config = require('config');


// POST METHOD to login users
userRouter.post('/',async (request, response)=>{
    const {error} = await validate(request.body);
    if(error){
        return response.status(400).send(error.details[0].message);
    }

    let user = await User.findOne({email: request.body.email});
    if(!user){
        return response.status(400).send("Invalid email or password");
    }

    const validPassword = await bcryt.compare(request.body.password, user.password);
    if(!validPassword){
        return response.status(400).send("Invalid email or password");
    }

    // const tk = config.valueOf().get("jwtPrivateKey");
    // const token = jwt.sign({_id: user._id}, process.env.vidly_jwtPrivateKey);
    const token = user.generateAuthToken();
    return response.send(token);
});


async function validate(request){
    const schema = Joi.object({
        email: Joi.string().max(255).required().email(),
        password: Joi.string().min(5).max(20).required()
    });
    return schema.validate(request);
}

module.exports = userRouter;
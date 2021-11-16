const mongoose = require('mongoose');
const Joi = require('joi');
const {json} = require("express");
const {now} = require("mongoose");
const {format} = require("morgan");

const userschema = new mongoose.Schema({
    username: {
        type: String,
        required: true,
        minlength: 6,
        maxlength: 20,
        unique: true
    },
    email:{
        type: String,
        required: true,
        minlength: 10,
        maxlength: 255,
        unique: true
    },
    password:{
        type: String,
        required: true,
        minlength: 6,
        maxlength: 255
    },
    gender:{
        type: String,
        enum: ['male', 'female', 'others'],
        required: true
    },
    dateofbirth:{
        type: Date,
        required: true,
        trim: true,
        format: Date
    },
    phonenumber:{
        type: String,
        minlength: 6,
        maxlength: 255,
        // required: true
    },
    role:{
        type: String,
        enum: ['user', 'admin'],
        default: "user"
    },
    createdAt:{
        type: Date,
        default: Date.now()
    },
    modifiedAt:{
        type: Date,
        default: Date.now()
    }
});

const User = new mongoose.model('User', userschema);

async function validateUser(user){
    const schema = Joi.object({
        username: Joi.string().required().min(6).max(20),
        email: Joi.string().email().required().min(10).max(255),
        password: Joi.string().required().min(6).max(255),
        gender: Joi.string().required(),
        dateofbirth: Joi.date().required(),
        phonenumber: Joi.string().min(6).max(255)
    });
    return schema.validate(user);
}

module.exports.User = User;
module.exports.userschema = userschema;
module.exports.validate = validateUser;
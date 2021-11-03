const mongoose = require('mongoose');
const Joi = require('joi');
const {func} = require("joi");
JoiObjectId = require('joi-objectid')(Joi);

const loginWIthUsernameSchema = new mongoose.Schema({
    username: {
        type: String,
        minlength: 5,
        maxlength: 20,
        unique: true,
        required: true
    },
    password: {
        type: String,
        required: true,
        minlength: 5,
        maxlength: 20
    }
});

const loginWIthEmailSchema = new mongoose.Schema({
    email: {
        type: String,
        unique: true,
        required: true
    },
    password: {
        type: String,
        required: true,
        minlength: 5,
        maxlength: 20
    }
});

const Login = mongoose.model('Login', loginSchema);

async function validateUserLogin(userId){
    const schema = Joi.object({
        userId: JoiObjectId().require()
    });
    return schema.validate(userId);
}

module.exports.loginWIthUsernameSchema = loginWIthUsernameSchema;
module.exports.loginWIthEmailSchema = loginWIthEmailSchema;
module.exports.Login = Login;
module.exports.validate = validateUserLogin;
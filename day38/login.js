const mongoose = require('mongoose');
const express = require('express');
const {request, response} = require("express");
const loginRouter = express.Router();
const {loginWIthUsernameSchema, loginWIthEmailSchema, Login, validate} = require('../models/login');

loginRouter.post('/api/login', async (request, response)=>{
    // Step 1: Validate User Schema shared in request body
    // const validateUser =
})
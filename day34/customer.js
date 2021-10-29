const mongoose = require('mongoose');
const Joi = require('joi');


const Customer = mongoose.model('Customer', new mongoose.Schema({
    isGold: {
        type: Boolean,
        default: false
    },
    name: {
        type: String,
        required: true,
        minlength: 5,
        maxlength: 50
    },
    phone: {
        type: Number,
        required: true,
        minlength: 10,
        maxlength: 12
    }
}));


// Validate Customer Details/Schema
async function validateCustomer(customer){
    const schema = Joi.object({
        isGold: Joi.boolean().default(true),
        name: Joi.string().min(5).max(50).required(),
        phone: Joi.number().min(10).max(12).required()
    });
    return schema.validate(customer);
}

module.exports.Customer = Customer;
module.exports.validate = validateCustomer;
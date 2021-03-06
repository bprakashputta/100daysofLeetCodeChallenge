const Joi = require("joi");
const mongoose = require("mongoose");


const Genre = mongoose.model('Genre',new mongoose.Schema({
    name:{
        type: String,
        required: true,
        minlength: 5,
        maxlength: 50
    }
}));


function validateSchema(genre){
    const schema = Joi.object({
        name: Joi.string().min(3).required()
    });

    return schema.validate(genre);
}


module.exports.Genre = Genre;
module.exports.validate = validateSchema;
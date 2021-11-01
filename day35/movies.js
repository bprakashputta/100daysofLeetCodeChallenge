const express = require('express');
const Joi = require('joi');
const mongoose = require('mongoose');
const {request, response} = require("express");
const moviesLog = require('debug')('movies:log');
const movieRouter = express.Router();
const {Movies, validate, movieSchema} = require('../models/movies');
const {Genre} = require("../models/genres");



// Get List of All Movies
movieRouter.get('/',async (request, response)=>{
    const movies = await Movies.find().sort('name');
    moviesLog(movies);
    return response.send(movies);
});

// Get Movie with Given ID
movieRouter.get('/:id',async (request, response)=>{
    const movies = await Movies.find().sort('name');
    moviesLog(movies);
    return response.send(movies);
});

// Add Movie to Database
movieRouter.post('/', async (request, response)=>{
    const {error} =await validate(request.body);
    if(error){
        return response.status(400).send(error.details[0].message);
    }
    const genre = await Genre.findById(request.body.genreId);
    if(!genre){
        return response.status(400).send('Genre is Invalid, please update genre');
    }

    let movie = await new Movies({
        title: request.body.title,
        genre: {
            _id: genre._id,
            name: genre.name
        },
        numberInStock: request.body.numberInStock,
        dailyRentalRate: request.body.dailyRentalRate
    });

    movie = await movie.save();
    moviesLog("Successfully Added Movie: ", movie);
    return response.send(movie);
});

// Update Movie in Database
// But it's highly unlikely that we'll update a movie that's already existing
movieRouter.put('/:id', async (request, response)=>{
    const {error} =await validate(request.body);
    if(error){
        return response.status(400).send(error.details[0].message);
    }

    const genre = await Genre.findById(request.body.genreId);
    if(!genre){
        return response.status(400).send('Invalid Genre');
    }

    const movie = await Movies.findByIdAndUpdate(request.params.id,{
        title: request.body.title,
        genre: {
            _id: genre._id,
            name: genre.name
        },
        numberInStock: request.body.numberInStock,
        dailyRentalRate: request.body.dailyRentalRate
    }, {new: true});

    if(!movie){
        return response.status(400).send('The movie with given ID was not found');
    }

    return response.send(movie);
});


// Delete Movie from Database
movieRouter.delete('/:id', async (request, response)=>{
   const movie = await Movies.findByIdAndRemove(request.params.id);
   if(!movie){
       return response.status(400).send('Movie with given ID does not exist');
   }
   moviesLog("Successfully Removed: ", movie);
   return response.send(movie);
});

module.exports = movieRouter;
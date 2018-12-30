//
//  rotor.cpp
//  Enigma
//
//  Created by Jad Ghadry on 1/1/19.
//  Copyright © 2019 Jad Ghadry. All rights reserved.
//

#include <iostream>

#include "errors.h"
#include "rotor.hpp"

Rotor::Rotor() {
    
    /* Initialize all the notches to false. */
    for (int i = 0; i < ALPHABET_COUNT; i++)
        isNotch[i] = false;
    
}



bool Rotor::didHitNotch() {
    return isNotch[rotation];
}



void Rotor::rotate() {
    
    /* Increment rotation. */
    rotation = (rotation + 1) % 26;
    
    /* Check if the notch was hit. */
    if (didHitNotch())
        next->rotate();
    
}



int Rotor::validateFile(std::ifstream &file) {
    
    int status = NO_ERROR;
    
    /* Check whether the file is empty or not. */
    if (isEmpty(file))
        return INVALID_ROTOR_MAPPING;
    
    /* Validate input numbers. */
    status = validateNumbers(file);
    if (status)
        return status;
    
    /* Check if a number repeats. */
    if (numberDoesRepeat(file))
        return INVALID_ROTOR_MAPPING;
    
    return status;
    
}



int Rotor::configure(const char *configFileName, const char *positionFileName, int rotorNumber) {
    
    int status;
    int notch = 0;
    int rotorCount = 0;
    
    std::ifstream configurationFile(configFileName);
    std::ifstream positionFile(positionFileName);
    
    /* Check if the position file opened. */
    if (!positionFile)
        return ERROR_OPENING_CONFIGURATION_FILE;
    
    /* Validate the mapping file. */
    status = validateFile(configurationFile);
    if (status)
        return status;
    
    /* Configure mapping array using the mapping file. */
    for (int i = 0; i < ALPHABET_COUNT; i++)
        configurationFile >> mapping[i];
    
    /* Configure notches using the mapping file. */
    while (configurationFile >> notch)
        isNotch[notch] = true;
    
    /* Get the rotation of the current rotor. */
    while (positionFile >> rotation && rotorCount < rotorNumber)
        rotorCount++;
    
    /* Check if the previous loop terminated early. */
    if (rotorCount != rotorNumber)
        return NO_ROTOR_STARTING_POSITION;
    
    return NO_ERROR;
    
}

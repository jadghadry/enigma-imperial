//
//  plugboard.cpp
//  Enigma
//
//  Created by Jad Ghadry on 12/30/18.
//  Copyright © 2018 Jad Ghadry. All rights reserved.
//

#include <iostream>

#include "errors.h"
#include "plugboard.hpp"

int Plugboard::checkPairs(std::ifstream &file) {
    
    int firstNumber = 0;
    int secondNumber = 0;
    
    while (file >> firstNumber) {
        
        /* Check if, after getting the first number, we can still get another number. */
        if (!(file >> secondNumber))
            return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
        
        /* Check if numbers in the pair are the same. */
        if (firstNumber == secondNumber)
            return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
        
    }
    
    /* Set the cursor back to the beginning of the file. */
    file.clear();
    file.seekg(file.beg);
    
    /* Check if a number in the series of pairs repeats. */
    if (numberDoesRepeat(file))
        return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
    
    return NO_ERROR;
    
}



int Plugboard::validateFile(std::ifstream &file) {
    
    int status;
    
    /* Check whether the file is empty or not. */
    if (isEmpty(file))
        return NO_ERROR;
    
    /* Validate input numbers. */
    status = validateNumbers(file);
    if (status)
        return status;
    
    /* Check if the plugboard configuration is valid. */
    status = checkPairs(file);
    if (status)
        return status;
    
    return NO_ERROR;
    
}

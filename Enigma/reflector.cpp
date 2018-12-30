//
//  reflector.cpp
//  Enigma
//
//  Created by Jad Ghadry on 1/1/19.
//  Copyright © 2019 Jad Ghadry. All rights reserved.
//

#include <iostream>

#include "errors.h"
#include "reflector.hpp"

int Reflector::checkPairs(std::ifstream &file) {
    
    int firstNumber = 0;
    int secondNumber = 0;
    int count = 0;
    
    while (file >> firstNumber) {
        
        /* Check if, after getting the first number, we reached the end of the file. */
        if (!(file >> secondNumber))
            return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
        
        /* Check if numbers in the pair are the same. */
        if (firstNumber == secondNumber)
            return INVALID_REFLECTOR_MAPPING;
        
        count++;
        
    }
    
    /* Set the cursor back to the beginning of the file. */
    file.clear();
    file.seekg(file.beg);
    
    /* Check if a number in the series of pairs repeats. */
    if (numberDoesRepeat(file))
        return INVALID_REFLECTOR_MAPPING;
    
    /* Check if there are exactly ALPHABET_COUNT/2 present pairs. */
    if (count != ALPHABET_COUNT/2)
        return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
    
    return NO_ERROR;
    
}



int Reflector::validateFile(std::ifstream &file) {
    
    int status;
    
    /* Check whether the file is empty or not. */
    if (isEmpty(file))
        return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
    
    /* Validate input numbers. */
    status = validateNumbers(file);
    if (status)
        return status;
    
    /* Check if the reflector configuration is valid. */
    status = checkPairs(file);
    if (status)
        return status;
    
    return NO_ERROR;
    
}

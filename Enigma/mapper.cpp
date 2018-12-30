//
//  mapper.cpp
//  Enigma
//
//  Created by Jad Ghadry on 12/30/18.
//  Copyright © 2018 Jad Ghadry. All rights reserved.
//

#include <iostream>
#include <set>

#include "errors.h"
#include "mapper.hpp"

Mapper::Mapper() {
    
    /* Initialize next mapper to null. */
    next = nullptr;
    
    /* Initialize rotation to 0. */
    rotation = 0;
    
    /* Initialize default mappings. */
    for (int i = 0; i < ALPHABET_COUNT; i++)
        mapping[i] = i;
    
}



bool Mapper::isEmpty(std::ifstream &file) {
    return file.peek() == std::ifstream::traits_type::eof();    
}



bool Mapper::numberDoesRepeat(std::ifstream &file) {
    
    int number = 0;
    int counter = 0;
    
    std::set<int> retrievedNumbers;
        
    /* Loop through the sequence of numbers in the file. */
    while (file >> number && counter < ALPHABET_COUNT) {
        
        /* Loop through the sequence of retrieved numbers. */
        if (std::find(retrievedNumbers.begin(), retrievedNumbers.end(), number) != retrievedNumbers.end())
            return true;
        
        /* Push the number into the retrieved numbers set. */
        retrievedNumbers.insert(number);
        
        /* Increment the counter. */
        counter++;
        
    }
    
    /* Set the cursor back to the beginning of the file. */
    file.clear();
    file.seekg(file.beg);
    
    return false;
    
}


int Mapper::validateNumbers(std::ifstream &file) {
    
    /* Loop through the potential sequence of numbers. */
    int number = 0;
    while (file >> number)
        if (number < 0 || number > ALPHABET_COUNT)
            return INVALID_INDEX;
    
    /* Check if we are at the end of the file. */
    if (!file.eof())
        return NON_NUMERIC_CHARACTER;
    
    /* Set the cursor back to the beginning of the file. */
    file.clear();
    file.seekg(file.beg);
    
    return NO_ERROR;
    
}



int Mapper::configure(char *&fileName) {
    
    int status;
    
    std::ifstream configurationFile(fileName);
    
    /* Validate the configuration file. */
    status = validateFile(configurationFile);
    if (status)
        return status;
    
    /* Perform double mapping. */
    int first;
    int second;
    
    while (configurationFile >> first && configurationFile >> second) {
        mapping[first] = second;
        mapping[second] = first;
    }
    
    /* Close file. */
    configurationFile.close();
    
    return NO_ERROR;
    
}



int Mapper::map(int &input) {
    
    input = (mapping[(input + rotation) % ALPHABET_COUNT] - rotation + ALPHABET_COUNT) % ALPHABET_COUNT;
    
    /* Recursive mapping calls. */
    if (next != nullptr) {
        
        input = (next->map(input) + rotation) % ALPHABET_COUNT;
        
        for (int i = 0; i < ALPHABET_COUNT; i++){
            if (mapping[i] == input) {
                input = (i - rotation + ALPHABET_COUNT) % ALPHABET_COUNT;
                break;
            }
        }
        
    }
    
    return input;
    
}

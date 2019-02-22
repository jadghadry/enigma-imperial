//
//  enigma.cpp
//  Enigma
//
//  Created by Jad Ghadry on 1/3/19.
//  Copyright © 2019 Jad Ghadry. All rights reserved.
//

#include <iostream>

#include "errors.h"
#include "enigma.hpp"

Enigma::Enigma() {
    
    /* No rotors connected initially. */
    numberOfRotors = 0;
    
    /* Initialize empty components */
    plugboard = nullptr;
    reflector = nullptr;
    
}



Enigma::~Enigma() {
    
    /* Deallocate heap memory of the rotors. */
    for (auto &iterator: rotors)
        delete iterator;
    
    /* Deallocate heap memory of the plugboard. */
    delete plugboard;
    
    /* Deallocate heap memory of the reflector. */
    delete reflector;
    
}



void Enigma::connectMappers() {
    
    if (numberOfRotors != 0) {
        
        /* Link the leftmost rotor to the plugboard. */
        plugboard->next = rotors[numberOfRotors - 1];
        
        /* Link the rotors with themselves. */
        for(int i = numberOfRotors - 1; i > 0; i--)
            rotors[i]->next = rotors[i-1];
        
        /* Link the rightmost rotor to the reflector. */
        rotors[0]->next = reflector;
        
    }
    
    else
        /* No rotors were provided, link the plugboard directly to the reflector. */
        plugboard->next = reflector;
    
}




int Enigma::configure(int argc, char **argv) {
    
    int status;
    int positionFileIndex = argc - 1;
    
    if (argc > 3)
        numberOfRotors = argc - 4;
    
    /* Configure the plugboard. */
    plugboard = new Plugboard;
    status = plugboard->configure(argv[1]);
    if (status)
        return status;
    
    /* Configure the reflector. */
    reflector = new Reflector;
    status = reflector->configure(argv[2]);
    if (status)
        return status;
    
    /* Configure potential rotors. */
    for (int i = 0; i < numberOfRotors; i++) {
        
        Rotor *rotor = new Rotor;
        status = rotor->configure(argv[i+3], argv[positionFileIndex], i+1);
        if (status)
            return status;
        
        /* Push the rotor into the vector of rotors. */
        rotors.push_back(rotor);
        
    }
    
    /* Link all of the extracted components together. */
    connectMappers();
    
    return NO_ERROR;
    
}



int Enigma::encrypt(char &input) {
    
    /* Check if input character is invalid. */
    if (input - ASCII_UPPERCASE_A > ALPHABET_COUNT - 1 || input - ASCII_UPPERCASE_A < 0)
        return INVALID_INPUT_CHARACTER;
    
    /* Rotate the rotor(s). */
    if (numberOfRotors)
        rotors[numberOfRotors - 1]->rotate();
    
    int absoluteIndex = Helpers::toggleASCII(input);
        absoluteIndex = plugboard->map(absoluteIndex);
    
    input = Helpers::toggleASCII(absoluteIndex);
    
    return NO_ERROR;
    
}

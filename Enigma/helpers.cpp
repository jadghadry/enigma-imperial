//
//  helpers.cpp
//  Enigma
//
//  Created by Jad Ghadry on 1/6/19.
//  Copyright © 2019 Jad Ghadry. All rights reserved.
//

#include "helpers.hpp"

const char* Helpers::errorDescriptionForCode(int code) {

    switch(code) {
        case ERROR_OPENING_CONFIGURATION_FILE:
            return "There was an error opening the configuration file.";
        case INVALID_INPUT_CHARACTER:
            return "An invalid input character was provided.";
        case IMPOSSIBLE_PLUGBOARD_CONFIGURATION:
            return "Impossible plugboard configuration.";
        case INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS:
            return "Plugboard configuration file has an incorrect number of parameters.";
        case INVALID_INDEX:
            return "Configuration file contains an illegal number.";
        case NON_NUMERIC_CHARACTER:
            return "Configuration file contains a non-numeric character.";
        case INVALID_ROTOR_MAPPING:
            return "Invalid rotor mapping.";
        case NO_ROTOR_STARTING_POSITION:
            return "An insufficient number of rotor starting positions was provided.";
        case INVALID_REFLECTOR_MAPPING:
            return "Invalid reflector mapping.";
        case INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS:
            return "Reflector configuration file has an incorrect number of parameters.";
    }
    
    return "Unknown error";
    
}



int Helpers::toggleASCII(int input) {
    return (input > ALPHABET_COUNT && input < ALPHABET_COUNT + ASCII_UPPERCASE_A) ? (input - ASCII_UPPERCASE_A) : (input + ASCII_UPPERCASE_A);
}

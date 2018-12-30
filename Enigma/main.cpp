//
//  main.cpp
//  Enigma
//
//  Created by Jad Ghadry on 12/30/18.
//  Copyright © 2018 Jad Ghadry. All rights reserved.
//

#include <iostream>

#include "constants.h"
#include "errors.h"
#include "enigma.hpp"

using namespace std;



int main(int argc, char **argv) {
    
    int status;
    
    /* Check main function arguments. */
    if (argc < 3) {
        cout << "An insufficient number of parameters was provided." << endl;
        return INSUFFICIENT_NUMBER_OF_PARAMETERS;
    }
    
    
    
    /* Configure Enigma using the retrieved argument files. */
    Enigma *enigmaMachine = new Enigma;
    status = enigmaMachine->configure(argc, argv);
    
    
    
    /* Check for potential errors after configuration. */
    if (status) {
        cout << Helpers::errorDescriptionForCode(status) << endl;
        return status;
    }
    
    
    
    /* Prompt message. */
    cout << "Please enter your text followed by the return key." << endl;
    
    
    
    /* Retrieve the plaintext to encrypt. */
    string input;
    getline(cin, input);
    
    
    
    /* Perform encryption. */
    for (auto &character: input) {
        
        if (ispunct(character) || character == ASCII_SPACE_CHARACTER)
            cout << character;
        
        else {
            status = enigmaMachine->encrypt(character);
            if (status) {
                cout << endl << Helpers::errorDescriptionForCode(status) << endl;
                return status;
            }
            cout << character;
        }
        
    }
    
    
    
    /* Deallocate heap memory of the enigma machine. */
    delete enigmaMachine;
    
    cout << endl;
    return NO_ERROR;
    
}

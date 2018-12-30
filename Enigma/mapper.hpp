//
//  mapper.hpp
//  Enigma
//
//  Created by Jad Ghadry on 12/30/18.
//  Copyright © 2018 Jad Ghadry. All rights reserved.
//

#ifndef mapper_hpp
#define mapper_hpp

#include <fstream>

#include "constants.h"

class Mapper {
    
protected:
    /* Internal parameters. */
    int mapping[ALPHABET_COUNT];
    int rotation;
    
    /* Helper function to check whether a file is empty or not. */
    bool isEmpty(std::ifstream &);
    
    /* Helper function to check if a file contains repeated numbers. */
    bool numberDoesRepeat(std::ifstream &);
    
    /* Helper function to validate the numbers in a configuration file. */
    int validateNumbers(std::ifstream &);
    
    /* Virtual helper function implemented only in the plugboard and reflector. */
    virtual int checkPairs(std::ifstream &) { return 0; };
    
    /* Virtual helper function to validate the entire state of the file. */
    virtual int validateFile(std::ifstream &) = 0;
    
public:
    /* Pointer to the next letter mapper. */
    Mapper *next;
    
    /* Default constructor. */
    Mapper();
    
    /* Virtual destructor. */
    virtual ~Mapper() {};
    
    /* Rotate function used in the Rotor only. */
    virtual void rotate() {};
    
    /* Configuration function. */
    virtual int configure(char *&);
    
    /* Common mapping algorithm. */
    int map(int &);
    
    
    
};

#endif /* mapper_hpp */

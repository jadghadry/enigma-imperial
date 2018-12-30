//
//  rotor.hpp
//  Enigma
//
//  Created by Jad Ghadry on 1/1/19.
//  Copyright © 2019 Jad Ghadry. All rights reserved.
//

#ifndef rotor_hpp
#define rotor_hpp

#include "mapper.hpp"

class Rotor: public Mapper {
    
private:
    /* Internal parameters. */
    bool isNotch[ALPHABET_COUNT];

public:
    /* Default constructor. */
    Rotor();
    
    /* Helper function to determine whether the notch is hit. */
    bool didHitNotch();
    
    /* Increments rotation. */
    void rotate();
    
    /* Helper function to validate the entire state of the file. */
    int validateFile(std::ifstream &);
    
    /* Configures a rotor according to input files. */
    int configure(const char *, const char *, int);
    
};

#endif /* rotor_hpp */

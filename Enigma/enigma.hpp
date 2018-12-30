//
//  enigma.hpp
//  Enigma
//
//  Created by Jad Ghadry on 1/3/19.
//  Copyright © 2019 Jad Ghadry. All rights reserved.
//

#ifndef enigma_hpp
#define enigma_hpp

#include <vector>

#include "helpers.hpp"
#include "plugboard.hpp"
#include "reflector.hpp"
#include "rotor.hpp"

class Enigma {
    
private:
    /* Top level components. */
    Plugboard *plugboard;
    Reflector *reflector;
    std::vector<Rotor *> rotors;
    
    int numberOfRotors;
    
    /* Helper function used to link components internally. */
    void connectMappers();
    
public:
    /* Constructor. */
    Enigma();
    
    /* Destructor. */
    ~Enigma();
    
    /* Configures a full enigma machine using the main() function arguments. */
    int configure(int, char **);
    
    /* Function that encrypts an input. */
    int encrypt(char &);
    
};

#endif /* enigma_hpp */

//
//  plugboard.hpp
//  Enigma
//
//  Created by Jad Ghadry on 12/30/18.
//  Copyright © 2018 Jad Ghadry. All rights reserved.
//

#ifndef plugboard_hpp
#define plugboard_hpp

#include <fstream>

#include "mapper.hpp"

class Plugboard: public Mapper {
    
public:
    /* Helper function that checks the plugboard comfiguration. */
    int checkPairs(std::ifstream &);
    
    /* Helper function to validate the entire state of the file. */
    int validateFile(std::ifstream &);
    
};

#endif /* plugboard_hpp */

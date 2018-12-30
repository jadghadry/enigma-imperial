//
//  reflector.hpp
//  Enigma
//
//  Created by Jad Ghadry on 1/1/19.
//  Copyright © 2019 Jad Ghadry. All rights reserved.
//

#ifndef reflector_hpp
#define reflector_hpp

#include "mapper.hpp"

class Reflector: public Mapper {
    
public:
    /* Helper function that checks the plugboard comfiguration. */
    int checkPairs(std::ifstream &);
    
    /* Helper function to validate the entire state of the file. */
    int validateFile(std::ifstream &);
    
};

#endif /* reflector_hpp */

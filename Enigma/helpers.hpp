//
//  helpers.hpp
//  Enigma
//
//  Created by Jad Ghadry on 1/6/19.
//  Copyright © 2019 Jad Ghadry. All rights reserved.
//

#ifndef helpers_hpp
#define helpers_hpp

#include "constants.h"
#include "errors.h"

class Helpers {
    
public:
    /* Helper function to report the errors that might occur. */
    static const char *errorDescriptionForCode(int);
    
    /* Helper function to map between ASCII codes and mapping indices. */
    static int toggleASCII(int);
    
};

#endif /* helpers_hpp */

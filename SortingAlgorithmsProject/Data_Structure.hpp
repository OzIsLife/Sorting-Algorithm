#ifndef Data_Structure_hpp
#define Data_Structure_hpp

#include <iostream>

class Data_Structure // prototype
{
public:
    Data_Structure() {}
    virtual ~Data_Structure() {} // deconstructor
    
    virtual Data_Structure* clone() = 0; // cloning an object
    
    virtual void start() = 0; // will pick the types of array
};

#endif /* Data_Structure_hpp */

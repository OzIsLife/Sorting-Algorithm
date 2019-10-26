#ifndef One_Array_hpp
#define One_Array_hpp

#include <stdio.h>
#include "Data_Structure.hpp"
#include <iostream>

template <class T>
class One_Array : public Data_Structure
{
public:
    One_Array(T*, int);
    virtual ~One_Array();
    
    virtual Data_Structure* clone()
    {
        return new One_Array(vIndex, length); // will return a cloned array with the vIndex and size of it
    }
    
    //Creating four different array type
    void sortedArray(); // array is already sorted
    void reverseArray(); // array will be reverse
    void shuffleArray(); // array is shuffled
    void mixArray(); // 10% shuffled
    
    void start();
    void print();
    
private: //private variables
    int length;
    T* vIndex;
    T* oneArray;
};







#endif /* One_Array_hpp */

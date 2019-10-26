#include "Data_Structure.hpp"
#include "One_Array.hpp"
#include "Sorting_Algorithm.h"

#include <iostream>
#include <ctime>
#include <cmath>
#include <ratio>
#include <chrono>

using namespace std::chrono;

int chooseSize();

int main()
{
    //5 different types of array to copy for
    int numInt[5] = {1, 2, 3, 4, 5};
    double numDouble[5] = {1.4, 2.5, 3.3, 4.9, 5.1};
    float numFloat[5] = {1.343f, 2.641f, 3.967f, 4.834f, 5.123f};
    std::string name[5] = {"Connor", "David", "John", "Miranda", "Abigail"};
    char alphabet[5] = {'A', 'B', 'C', 'D', 'E'};
    
    
    
    
    
    while(true)
    {
        unsigned int dT;
        while(true)
        {
            std::cout << "\n\t --------Five choices--------\n";
            std::cout << "\t Please choose one of the five data types:\n";
            
            std::cout << "\t\t 1. Int\n";
            std::cout << "\t\t 2. Double\n";
            std::cout << "\t\t 3. Float\n";
            std::cout << "\t\t 4. String\n";
            std::cout << "\t\t 5. Char\n";
            std::cout << "\t --------Five choices--------\n";
            
            std::cout << "\t Input: ";
            std::cin >> dT;
            
            if(dT > 5)
                std::cout << "\t Invalid choice!\n";
            else
                break;
        }
        
        Data_Structure* a;
        switch(dT)
        {
            case 1:
            {
                Data_Structure* aInt = new One_Array<int>(numInt, chooseSize());
                a = aInt->clone();
                delete aInt;
            }
                break;
            case 2:
            {
                Data_Structure* aDouble = new One_Array<double>(numDouble, chooseSize());
                a = aDouble->clone();
                delete aDouble;
            }
                break;
            case 3:
            {
                Data_Structure* aFloat = new One_Array<float>(numFloat, chooseSize());
                a = aFloat->clone();
                delete aFloat;
            }
                break;
            case 4:
            {
                Data_Structure* aString = new One_Array<std::string>(name, chooseSize());
                a = aString->clone();
                delete aString;
            }
                break;
            case 5:
            {
                Data_Structure* aChar = new One_Array<char>(alphabet, chooseSize());
                a = aChar->clone();
                delete aChar;
            }
                break;
        }
        delete a;
    }
    return 0;
}

int chooseSize()
{
    int sT;
    std::cout << "\n\t --------Five choices--------\n";
    std::cout << "\t Choose size:\n";
    
    std::cout << "\t\t 1. 100\n";
    std::cout << "\t\t 2. 1000\n";
    std::cout << "\t\t 3. 10000\n";
    std::cout << "\t\t 4. 100000\n";
    std::cout << "\t\t 5. 1000000\n";
    
    std::cout << "\t --------Five choices--------\n";
    std::cout << "\t Input: ";
    std::cin >> sT;
    
    switch(sT)
    {
        case 1: return 100; break;
        case 2: return 1000; break;
        case 3: return 10000; break;
        case 4: return 100000; break;
        case 5: return 1000000; break;
    }
    return sT;
}

/*
 used this to conduct the mean and standard deviation in main
 Data_Structure* aInt = new One_Array<int>(numInt, chooseSize());
 Data_Structure* a = aInt->clone();
 
 
 long long mean = 0;
 long long add = 0;
 long long stdDev[100];
 for(int i = 0; i < 100; ++i)
 {
 auto start = std::chrono::high_resolution_clock::now();
 a->start();
 auto end = std::chrono::high_resolution_clock::now() - start;
 long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end).count();
 stdDev[i] = microseconds;
 mean += microseconds;
 }
 
 mean = mean / 100;
 std::cout << mean << "\n";
 
 for(int i = 0; i < 100; ++i)
 {
 stdDev[i] = pow(stdDev[i] - mean, 2);
 add += stdDev[i];
 }
 add /= 100;
 
 std::cout << sqrt(add) << "\n";
 */


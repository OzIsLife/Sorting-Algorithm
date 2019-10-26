#include "One_Array.hpp"
#include "Sorting_Algorithm.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

template <class T>
One_Array<T>::One_Array(T* arr, int s) //overloaded constructor
{
    length = s;
    oneArray = new T [length];
    vIndex = arr;
}

template <class T>
One_Array<T>::~One_Array() // deconstructor
{
    delete oneArray;
    delete vIndex;
}

template <class T>
void One_Array<T>::sortedArray()
{
    int limit = length / 5, index = 0; // length will get the first 20 percent of the elements
    
    for(int i = 0; i < length; ++i) // will go through for loop to put elements into the array
    {
        oneArray[i] = vIndex[index];
        if(i == limit - 1) // check if i hits the limit then the limit will increment itself by 20%
        {
            limit += length / 5;
            ++index;
        }
    }
}

template <class T>
void One_Array<T>::reverseArray()
{
    int limit = length / 5, index = 4; // will get the first 20 percent of the elements
    
    for(int i = 0; i < length; ++i) // will go through for loop to put elements into the array
    {
        oneArray[i] = vIndex[index];
        if(i == limit - 1) // the vIndex will start from the last element to get to the first one
        {
            limit += length / 5;
            --index;
        }
    }
}

template <class T>
void One_Array<T>::shuffleArray()
{
    srand(time(NULL));
    
    int limit = length / 5, index = 0; // will get the first 20 percent of the elements
    
    for(int i = 0; i < length; ++i) // will go through for loop to put elements into the array
    {
        oneArray[i] = vIndex[index]; // check if i hits the limit then the limit will increment itself by 20%
        if(i == limit - 1)
        {
            limit += length / 5;
            ++index;
        }
    }
    // this will randomize/shuffle our array
    for(int i = length - 1; i > 0; --i) //start from the last element
        swaps(oneArray, i, rand() % i + 1); // will pick an element from the array and swap where i is
}

template <class T>
void One_Array<T>::mixArray()
{
    srand(time(NULL)); //Need to fix
    int limit = length / 5, index = 0;
    for(int i = 0; i < length; ++i)
    {
        oneArray[i] = vIndex[index];
        if(i == limit - 1)
        {
            limit += length / 5;
            ++index;
        }
    }
    // will swap the first half by the second half by every 10 elements
    int tenPercent = length * .1;
    for(int i = 0; i < tenPercent / 2; ++i)
        swaps(oneArray, rand() % 10 + (10 * i), rand() % 10 + 10 * (tenPercent / 2 + i));
}

template <class T>
void One_Array<T>::start()
{
    
    
    // will pick the types of array
    int aT;
    std::cout << "\n\t --------Four choices--------\n";
    std::cout << "\t Pick a type of Array:\n";
    std::cout << "\t\t 1. Sorted Array\n";
    std::cout << "\t\t 2. Reverse Array\n";
    std::cout << "\t\t 3. Shuffle Array\n";
    std::cout << "\t\t 4. 10% Shuffle\n";
    std::cout << "\t --------Four choices--------\n";
    std::cout << "\t Input: ";
    std::cin >> aT;
    
    switch(aT)
    {
        case 1:
            sortedArray();
            break;
        case 2:
            reverseArray();
            break;
        case 3:
            shuffleArray();
            break;
        case 4:
            mixArray();
            break;
    }
    // will pick a sorting algorithm
    int soT;
    std::cout << "\n\t --------Five choices--------\n";
    std::cout << "\t Pick a Sorting Algorithm:\n";
    
    std::cout << "\t\t 1. Selection Sort\n";
    std::cout << "\t\t 2. Insertion Sort\n";
    std::cout << "\t\t 3. Bubble Sort\n";
    std::cout << "\t\t 4. Merge Sort\n";
    std::cout << "\t\t 5. Quick Sort\n";
    
    std::cout << "\t --------Five choices--------\n";
    std::cout << "\t Input: ";
    std::cin >> soT;
    
    switch(soT)
    {
        case 1:
            selectionSort(oneArray, length);
            break;
        case 2:
            insertionSort(oneArray, length);
            break;
        case 3:
            bubbleSort(oneArray, length);
            break;
        case 4:
            mergeSort(oneArray, 0, length - 1);
            break;
        case 5:
            quickSort(oneArray, 0, length - 1);
            break;
    }
}

template <class T>
void One_Array<T>::print() // will print the array
{
    for(int i = 0; i < length; ++i)
        std::cout << oneArray[i] << " ";
    std::cout << "\n";
}
// without this template isn't usable
template class One_Array <int>;
template class One_Array <double>;
template class One_Array <float>;
template class One_Array <std::string>;
template class One_Array <char>;

#ifndef Sorting_Algorithm_h
#define Sorting_Algorithm_h
#include <iostream>


template<class T>
inline void swaps(T* arr, int i, int j) // function to swap the elements in the array
{
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <class T>
void selectionSort(T* arr, int s)
{
    
    for(int i = 0; i < s; ++i)
    {
        int mins = i;
        for(int j = i+1; j < s; ++j) // the value of j and min will compare to each other to find the min, if so the index will the be the min val
        {
            if(arr[mins] > arr[j])
            {
                mins = j;
            }
        }
        swaps(arr, i, mins); // it will swap
    }
}

template<class T>
void insertionSort(T* arr, int s)
{
    for(int i = 1; i < s; ++i)
    {
        for(int j = i; j > 0; --j)
        {
            if(arr[j] < arr[j - 1]) // each j loop will compare j and it's preview elementl, if so the elements will swap
            {
                swaps(arr, j, j - 1);
            }
            else
            {
                break;
            }
        }
    }
}

template<class T>
void bubbleSort(T* arr, int s)
{
    for(int i = 0; i < s; ++i)
    {
        for(int j = 0; j < s - i - 1; ++j) // each j loop will compare with the next element and swap if the current element is greater than next element
        {
            if(arr[j] > arr[j + 1])
            {
                swaps(arr, j, j + 1);
            }
        }
    }
}

template<class T>
void merges(T* arr, int lo, int mid, int hi) // function will split the array into two subarrays and compare to merge into one array
{
    int sizeLeft = mid - lo + 1, sizeRight = hi - mid; // predefine the size to know the size of the array
    T* arrLeft = new T[sizeLeft],* arrRight = new T[sizeRight]; // will make the two subarrays
    
    for(int i = 0; i < sizeLeft; ++i) // copy array
    {
        arrLeft[i] = arr[lo + i];
    }
    
    for(int i = 0; i < sizeRight; ++i) // copy array for the right side
    {
        arrRight[i] = arr[mid + 1 + i];
    }
    
    int leftIndex = 0, rightIndex = 0, index = lo; // new index variables
    
    while(leftIndex < sizeLeft && rightIndex < sizeRight) // until LIndex and RIndex is less than the size of designated array
    {
        if(arrLeft[leftIndex] < arrRight[rightIndex]) // if these conditions are met
        {
            arr[index++] = arrLeft[leftIndex++];
        }
        else
        {
            arr[index++] = arrRight[rightIndex++]; // the final array will contain elements from both Left and Right array
        }
    }
    
    while(leftIndex < sizeLeft) // if there are any left over elements in the left array, the remaining elements will be copied into the sorted array
    {
        arr[index++] = arrLeft[leftIndex++];
    }
    
    while(rightIndex < sizeRight) // if there are any left over elements in the left array, the remaining elements will be copied into the sorted array
    {
        arr[index++] = arrRight[rightIndex++];
    }
}

template<class T>
void mergeSort(T* arr, int lo, int hi) // merge function that will call to the sorting function
{
    if(lo >= hi)
    {
        return;
    }
    int mid = (hi + lo) / 2;  // equation to find mid
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid + 1, hi);
    merges(arr, lo, mid, hi); // invokes merge function and will merge the two sorted arrays into one big sorted one
}

template<class T>
int partitions(T* arr, int lo, int hi) //partition function will find the pivot
{
    int p = lo, i = lo + 1, j = hi;
    
    while(true)
    {
        while(arr[i] <= arr[p]) // i will go through the array if it's value is smaller than the pivot's value
        {
            if(i == hi) //purpose is to find a value greater than the pivot
                break;
            ++i;
        }
        
        while(arr[j] >= arr[p]) // j will go through the array if it's value is greater than the pivot's value
        {
            if(j == lo) // purpose is to find a value smaller than the pivot
                break;
            --j;
        }
        
        if(i >= j)
            break;
        
        swaps(arr, i, j);
    }
    
    swaps(arr, j, p);
    return j; // j is the new pivot
}

template <class T>
void quickSort(T* arr, int lo, int hi)
{
    if(lo >= hi)
    {
        return;
    }
    int pivot = partitions(arr, lo, hi); // pivot will call partition
    quickSort(arr, lo, pivot - 1);
    quickSort(arr, pivot + 1, hi);
}

#endif /* Sorting_Algorithm_h */

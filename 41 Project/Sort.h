#ifndef MY_SORT
#define MY_SORT
#include <vector>

using namespace std;

void shellSortA(vector<int>&);
void shellSortB(vector<int>&);

void mergeSortA(vector<int>&, int, int);
void mergeSortB(vector<int>&, int, int);
void insertionSort(vector<int>&, int, int);

void quickSortA(vector<int>&, int, int);
void quickSortB(vector<int>&, int, int);
void quickSortC(vector<int>&, int, int);

void heapSortA(vector<int>&);

#endif

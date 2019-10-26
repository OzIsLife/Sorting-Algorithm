#include "HelperFunction.h"
#include "Sort.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <cmath>

using namespace std;

void creatingVector(vector<vector<int> >& v)
{
	int limitValue = 4;
	
	cout << "\t\tCreating Three Vectors!" << endl;
	for(int i = 0; i < v.size(); ++i)
	{
		for(int j = 0; j < limitValue; ++j)
			v[i].push_back(rand() % 10 + 1);
		limitValue *= 2;
	}
	print(v);
	cout << endl; 
}

void clear(vector<vector<int> >& v)
{
	cout << endl << "\t\tClearing ALL Vectors!" << endl;
	for(int i = 0; i < v.size(); ++i)
		v[i].clear();
	print(v);
}

int compare(vector<int> v, int i, int j, int k)
{
	if(v[i] > v[j] && v[i] < v[k] || v[i] < v[j] && v[i] > v[k])
    	return i;
    else if(v[j] > v[i] && v[j] < v[k] || v[j] < v[i] && v[j] > v[k] )
		return j;
    else 
    	return k;
}

void line()
{
	cout << "\t";
	for(int i = 0; i < 40; ++i)
		cout << "_";
	cout << endl;
}

void menu()
{
	cout << "\n\n\n\tWelcome to Khai 41 Project!" << endl;
	line();
	cout << "\t1. Shell Sort (Pratt 1971, OEIS A003462)" << endl;
	cout << "\t2. Shell Sort (Gonnet & Baeza-Yates)" << endl;
	cout << "\t3. Normal Merge Sort" << endl;
	cout << "\t4. Three-Way Merge Sort" << endl;
	cout << "\t5. Normal Quick Sort" << endl;
	cout << "\t6. Ninth Median Quick Sort" << endl;
	cout << "\t7. Dijkstra's Three-Way Quick Sort" << endl;
	cout << "\t8. Top-Down Heap Sort" << endl;
	cout << "\t9. Bottom-Up Heap Sort" << endl;
	cout << "\t0. The Whole." << endl;
	cout << "\t-1. Exit." << endl;
	line();
}

void print(vector<vector<int> > v)
{
	for(int i = 0; i < v.size(); ++i) 
	{
		cout << "\tVector " << i + 1 << ": ";
		if(v[i].empty())
			cout << "Empty Vector!";
		else
			for(int j = 0; j < v[i].size(); ++j)
				cout << v[i][j] << " ";
		cout << endl;
	}
}

void swap(vector<int>& v, int i, int j)
{
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void theWhole(vector<vector<int> >& v)
{
	line();
	
	creatingVector(v);
	cout << "\tSorting ALL Vectors by Shell Sort(Pratt 1971, OEIS A003462)!" << endl; 
	for(int i = 0; i < v.size(); ++i)
		shellSortA(v[i]); 
	print(v);
	clear(v);
	
	line();
	
	//Shell Sort B
	creatingVector(v);
	cout << "\tSorting ALL Vectors by Shell Sort(Gonnet & Baeza-Yates)!" << endl; 
	for(int i = 0; i < v.size(); ++i)
		shellSortA(v[i]); 
	print(v);
	clear(v);
	
	line();
	
	//Merge Sort A
	creatingVector(v); 
	cout << "\tSorting All Vectors by Normal Merge Sort!" << endl;
	for(int i = 0; i < v.size(); ++i)
		mergeSortA(v[i], 0, v[i].size() - 1);	
	print(v);	
	clear(v);
	
	line();
	
	//Merge Sort B
	creatingVector(v); 
	cout << "\tSorting All Vectors by the Three-Way Merge Sort!" << endl;
	for(int i = 0; i < v.size(); ++i)
		mergeSortB(v[i], 0, v[i].size() - 1);	
	print(v);	
	clear(v);
	
	line();
	
	creatingVector(v);
	cout << "\tSorting All Vectors by Normal Quick Sort!" << endl;
	for(int i = 0; i < v.size(); ++i)
		quickSortA(v[i], 0, v[i].size() - 1);	
	print(v);	
	clear(v);
	
	line();
			
	creatingVector(v); 
	cout << "\tSorting All Vectors by the Ninth Median Quick Sort!" << endl;
	for(int i = 0; i < v.size(); ++i)
		quickSortB(v[i], 0, v[i].size() - 1);	
	print(v);	
	clear(v);
	
	line();

	creatingVector(v); 
	cout << "\tSorting All Vectors by the Dijkstra's Three-Way Quick Sort!" << endl;
	for(int i = 0; i < v.size(); ++i)
		quickSortB(v[i], 0, v[i].size() - 1);	
	print(v);	
	clear(v);
	
	line();
	
	creatingVector(v); 
	cout << "\tSorting All Vectors by Top-Down Heap Sort!" << endl;
	for(int i = 0; i < v.size(); ++i)
		heapSortA(v[i]);	
	print(v);	
	clear(v);
	line();
}



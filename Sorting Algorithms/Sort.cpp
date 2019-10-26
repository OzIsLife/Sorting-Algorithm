#include "HelperFunction.h"
#include "Sort.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void shellSortA(vector<int>& v)
{
	int h = 1, limit = 1;
	for(int j = 1; h < v.size() / 3; ++j)
		h = (pow(3, limit++) - 1) / 2;
			
	while(h > 0)
	{
		for(int i = h; i < v.size(); ++i)
			for(int j = i; j >= h; j -= h)
				if(v[j - h] > v[j])
					swap(v, j - h, j);
				else 
					break;
		h = (pow(3, --limit) - 1) / 2;
	}	
	
}			

void shellSortB(vector<int>& v)
{
	int h = (5 * v.size()) / 11;
	while(h > 0)
	{
		for(int i = h; i < v.size(); ++i)
			for(int j = i; j >= h; j -= h)
				if(v[j - h] > v[j])
					swap(v, j - h, j);
				else 
					break;
		h = (5 * h) / 11;
	}
}

void mergeA(vector<int>& v, int lo, int mid, int hi)
{
	int i = lo, j = mid + 1;
	
	vector<int> aux;
	for(int i = 0; i < v.size(); ++i) 
		aux.push_back(v[i]);
	
	if(hi - lo + 1 < 20)
	{
		insertionSort(v, lo, hi);
		return;
	}
	
	for(int k = lo; k <= hi; ++k)
		if(i > mid)
			v[k] = aux[j++];
		else if(j > hi)
			v[k] = aux[i++];
		else if(aux[i] > aux[j])
			v[k] = aux[j++];
		else 
			v[k] = aux[i++];
}

void mergeSortA(vector<int>& v, int lo, int hi)
{
	if(lo >= hi)
		return;
	int mid = (lo + hi) / 2;
	mergeSortA(v, lo, mid);
	mergeSortA(v, mid + 1, hi);
	mergeA(v, lo, mid, hi);
}

void mergeB(vector<int>& v, int mid, int mid2, int lo, int hi)
{
	int i = lo, j = mid + 1, l = mid2 + 1;
	
	vector<int> aux;
	for(int i = 0; i < v.size(); ++i)
		aux.push_back(v[i]);
	
	if(hi - lo + 1 < 20)
	{
		insertionSort(v, lo, hi);
		return;
	}
	for(int k = lo; k <= hi; ++k)
		if(i > mid)
			if(j > mid2)
				v[k] = aux[l++];
			else if(l > hi)
				v[k] = aux[j++];
			else if(aux[j] > aux[l])
				v[k] = aux[l++];
			else
				v[k] = aux[j++];	
		else if(j > mid2)
			if(l > hi)
				v[k] = aux[i++];
			else if(i > mid)
				v[k] = aux[l++];
			else if(aux[l] > aux[i])
				v[k] = aux[i++];
			else
				v[k] = aux[l++];
		else if(l > hi)
			if(i > mid)
				v[k] = aux[j++];
			else if(j > mid2)
				v[k] = aux[i++];
			else if(aux[i] > aux[j])
				v[k] = aux[j++];
			else 
				v[k] = aux[i++];		
		else if(aux[i] > aux[j] && aux[l] > aux[j])
			v[k] = aux[j++];
		else if(aux[j] > aux[i] && aux[l] > aux[i])
			v[k] = aux[i++];
		else 
			v[k] = aux[l++];
}

void mergeSortB(vector<int>& v, int lo, int hi)
{
	if (lo >= hi)
        return;
        
	int mid1 = lo + ((hi - lo) / 3);
    int mid2 = lo + 1 + 2 * ((hi - lo) / 3);
	
	mergeSortB(v, lo, mid1); //Left Side
	mergeSortB(v, mid1 + 1, mid2); //Middle Side
	mergeSortB(v, mid2 + 1, hi); //Right Side
	
	mergeB(v, mid1, mid2, lo, hi);
}

void insertionSort(vector<int>& v, int lo, int hi)
{
	for(int i = lo + 1; i <= hi; ++i)
		for(int j = i; j > lo; --j)
			if(v[j] < v[j - 1])
				swap(v, j, j - 1);
			else 
				break;	
}

int partitionA(vector<int>& v, int lo, int hi)
{
	int p = lo, i = lo + 1, j = hi;
	
	while(true)
	{
		while(v[i] <= v[p])
		{
			if(i == hi)
				break;
			++i;
		}
		
		while(v[j] >= v[p])
		{
			if(j == lo)
				break;
			--j;
		}
		
		if(i >= j)
			break;
		
		swap(v, i, j);
	}
	
	swap(v, p, j);
	return j;
}

void quickSortA(vector<int>& v, int lo, int hi)
{
	if(lo >= hi)
		return;
	int pivot = partitionA(v, lo, hi);
	quickSortA(v, lo, pivot - 1);
	quickSortA(v, pivot + 1, hi);
}

int ninthMedian(vector<int> v, int lo, int hi)
{
	int mid1 = lo + ((hi - lo) / 3); //3 sub array
    int mid2 = lo + 1 + 2 * ((hi - lo) / 3);
    
    int i = compare(v, lo, (lo + mid1) / 2, mid1); //middle between lo and mid1
    int j = compare(v, mid1+1, (mid1+1 + mid2) / 2, mid2); 
    int k = compare(v, mid2+1, (mid2+1 + hi) / 2, hi);
    
    return compare(v, i, j, k);
}

int partitionB(vector<int>& v, int lo, int hi)
{
	int median = ninthMedian(v, lo, hi);
	int pivot = lo, i = lo + 1, j = hi;
	swap(v, pivot, median);
	
	while(true)
	{
		while(v[i] <= v[pivot])
		{
			if(i == hi)
				break;
			++i;
		}
		
		while(v[j] >= v[pivot])
		{
			if(j == lo)
				break;
			--j;
		}
		
		if(i >= j)
			break;
		
		swap(v, i, j);
	}
	
	swap(v, pivot, j);
	return j;
}

void quickSortB(vector<int>& v, int lo, int hi)
{
	if(lo >= hi)
		return;
	int pivot = partitionB(v, lo, hi);
	quickSortB(v, lo, pivot - 1);
	quickSortB(v, pivot + 1, hi);
}

int partitionC(vector<int>& v, int lo, int hi)
{
	int p = lo, i = lo + 1, j = hi;
	
	while(true)
	{
		if(v[p] > v[i])
		{
			swap(v, p, i);
			++i;
			++p;
		}
		else if(v[p] < v[i])
		{
			swap(v, i, j);
			--j;
		}
		else
			++i;
		
		if(i > j)
			break;
	}
	
	return j;
}

void quickSortC(vector<int>& v, int lo, int hi)
{
	if(lo >= hi)
		return;
	int pivot = partitionC(v, lo, hi);
	quickSortC(v, lo, pivot - 1);
	quickSortC(v, pivot + 1, hi);
}

void sinkA(vector<int>& v, int parent, int size)
{
	while(2 * parent <= size)
	{
		int kid = 2 * parent;
		if(kid < size && v[kid] < v[kid + 1])
			++kid;
		if(v[kid] > v[parent])
			swap(v, kid, parent);
		parent = kid;
	}
}

void heapSortA(vector<int>& v)
{
	int N = v.size() - 1;
	for(int i = N/2; i > 0; --i)
		sinkA(v, i, N);
	while(N > 0)
	{
		swap(v, 1, N--);
		sinkA(v, 1, N);
	}
}

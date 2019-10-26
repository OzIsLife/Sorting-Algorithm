#include "HelperFunction.h"
#include "Sort.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main() {
	srand(time(NULL)); 
	vector<vector<int> > numTree(3); 
	int input;
	
	while(true)
	{
		menu();
		cout << "\n\tEnter your Selection: ";
		cin >> input;
		system("CLS");
		
		switch(input)
		{
			case 1: //Shell Sort A
				cout << "\n\n\n\tShell Sort(Pratt 1971, OEIS A003462)" << endl;
				line();
				creatingVector(numTree);
				cout << "\tSorting ALL Vectors by Shell Sort(Pratt 1971, OEIS A003462)!" << endl; 
				for(int i = 0; i < numTree.size(); ++i)
					shellSortA(numTree[i]); 
				print(numTree);
				clear(numTree);
				line();
			break;
			case 2: //Shell Sort B
				cout << "\n\n\n\tShell Sort(Gonnet & Baeza-Yates)" << endl;
				line();
				creatingVector(numTree);
				cout << "\tSorting ALL Vectors by Shell Sort(Gonnet & Baeza-Yates)!" << endl; 
				for(int i = 0; i < numTree.size(); ++i)
					shellSortA(numTree[i]); 
				print(numTree);
				clear(numTree);
				line();
			break;
			case 3:	//Merge Sort A
				cout << "\n\n\n\tNormal Merge Sort" << endl;
				line();
				creatingVector(numTree); 
				cout << "\tSorting All Vectors by Normal Merge Sort!" << endl;
				for(int i = 0; i < numTree.size(); ++i)
					mergeSortA(numTree[i], 0, numTree[i].size() - 1);	
				print(numTree);	
				clear(numTree);
				line();
			break;
			case 4:	//Merge Sort B
				cout << "\n\n\n\tThree-Way Merge Sort" << endl;
				line();
				creatingVector(numTree); 
				cout << "\tSorting All Vectors by the Three-Way Merge Sort!" << endl;
				for(int i = 0; i < numTree.size(); ++i)
					mergeSortB(numTree[i], 0, numTree[i].size() - 1);	
				print(numTree);	
				clear(numTree);
				line();
			break;
			case 5:
				cout << "\n\n\n\tNormal Quick Sort" << endl;
				line();
				creatingVector(numTree);
				cout << "\tSorting All Vectors by Normal Quick Sort!" << endl;
				for(int i = 0; i < numTree.size(); ++i)
					quickSortA(numTree[i], 0, numTree[i].size() - 1);	
				print(numTree);	
				clear(numTree);
				line();
			break;
			case 6:
				cout << "\n\n\n\tNinth Median Quick Sort" << endl;
				line();
				creatingVector(numTree); 
				cout << "\tSorting All Vectors by the Ninth Median Quick Sort!" << endl;
				for(int i = 0; i < numTree.size(); ++i)
					quickSortB(numTree[i], 0, numTree[i].size() - 1);	
				print(numTree);	
				clear(numTree);
				line();
			break;
			case 7:
				cout << "\n\n\n\tDijkstra's Three-Way Quick Sort" << endl;
				line();
				creatingVector(numTree); 
				cout << "\tSorting All Vectors by the Dijkstra's Three-Way Quick Sort!" << endl;
				for(int i = 0; i < numTree.size(); ++i)
					quickSortB(numTree[i], 0, numTree[i].size() - 1);	
				print(numTree);	
				clear(numTree);
				line();
			break;
			case 8:
				cout << "\n\n\n\tTop-Down Heap Sort" << endl;
				line();
				creatingVector(numTree); 
				cout << "\tSorting All Vectors by Top-Down Heap Sort!" << endl;
				for(int i = 0; i < numTree.size(); ++i)
					heapSortA(numTree[i]);	
				print(numTree);	
				clear(numTree);
				line();
			break;
			case 9:
				cout << "\n\n\n\tBottom-Up Heap Sort" << endl;
				line();
				cout <<"\tBottom-Up Heap Sort currently not working..." << endl;
				line();
			break;
			case 0:
				cout << "\n\n\n\tThe Whole";
				theWhole(numTree);
			break;
			case -1:
				return 0;
			break;
			default:
				line();
				cout << "\tInvalid! Try again." << endl;
				line();
			break;
		}
		cout << "\n\t";
		system("pause");
		system("CLS");
	}
	
	return 0;
}

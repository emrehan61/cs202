#include <iostream>

#include "sorting.h"
/*
* Title: Sorting and Algorithm Efficiency
* Author: Emrehan Hoşver
* ID: 21903488
* Section: 1
* Assignment: 1
* Description: Homework
*/
using namespace std;
int main() {
	int testarray[16] = { 9,6,7,16,18,5,2,12,20,1,16,17,4,11,13,8 };
	int cc = 0;
	int mc = 0;
	
	insertionSort(testarray, 16, cc, mc);
	displayArray(testarray, 16);
	cout << "    Compare Count:" << cc << "    Move Count: " << mc << "\n";
	cc = 0;
	mc = 0;
	int testarray2[16] = { 9,6,7,16,18,5,2,12,20,1,16,17,4,11,13,8 };
	bubbleSort(testarray2, 16, cc, mc);
	displayArray(testarray2, 16);
	cout << "    Compare Count:" << cc << "    Move Count: " << mc << "\n";
	cc = 0;
	mc = 0;
	int testarray3[16] = { 9,6,7,16,18,5,2,12,20,1,16,17,4,11,13,8 };
	mergeSort(testarray3, 16, cc, mc);
	displayArray(testarray3, 16);
	cout <<"    Compare Count:" << cc << "    Move Count: " << mc << "\n";
	cc = 0;
	mc = 0;
	int testarray4[16] = { 9,6,7,16,18,5,2,12,20,1,16,17,4,11,13,8 };
	int array[30000];
	
	quickSort(testarray4, 16, cc, mc);
	displayArray(testarray4, 16);
	cout << "    Compare Count:" << cc << "    Move Count: " << mc << "\n";
	cout << "\n";
	//cout << cc << " " << mc << "\n";
	//int* xx = new int[4];
	//int* mes = new int[8];
	//calcASorted(40000,xx,mes);
	//
	//
	//for (int i = 0; i < 4; i++) {
	//	cout<< xx[i] <<" ";

	//}
	//cout << "\n";
	//for (int i = 0; i < 8; i++) {
	//	if (i % 2 == 0) cout << "mc: ";
	//	else cout << "cc: ";
	//	cout << mes[i] << " ";
	//}
	//int* x1= new int[20];
	//int* x2 = new int[20];
	//int* x3 = new int[20];
	//int* x4 = new int[20];
	//createAlmostUnsortedArrays(x1, x2, x3, x4, 20);
	//displayArray(x1, 20);
	//displayArray(x2, 20);
	//displayArray(x3, 20);
	//displayArray(x4, 20);
	performanceAnalysis();
	//delete[] xx;
	//delete[] mes;
	return 0;
}
#pragma once
#include <iostream>
#include <stdlib.h>   //for random 
#include <ctime>  
//#include <chrono>
/*
* Title: Sorting and Algorithm Efficiency
* Author: Emrehan Hoþver
* ID: 21903488
* Section: 1
* Assignment: 1
* Description: Homework
*/

using namespace std;

void insertionSort(int* arr, const int size, int& compCount, int& moveCount);
void bubbleSort(int* arr, const int size, int& compCount, int& moveCount);
void mergeSort(int* arr, const int size, int& compCount, int& moveCount);
void quickSort(int* arr, const int size, int& compCount, int& moveCount);
void quickSort(int* arr, int start, int end, int& compCount, int& moveCount);
void partition(int* arr, int first, int& piv, int last, int& compCount, int& moveCount); // to use in quick sort 
void mergeSort(int* arr, int start, int end, int& compCount, int& moveCount);
void merge(int* arr, int start, int mid, int end, int& compCount, int& moveCount);
void displayArray(int* arr, int size);
void createRandomArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);
void createAlmostSortedArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);
void createAlmostUnsortedArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);
void print1(string s);
double measureTime(int* arr, int size, string s, int* mes);
void performanceAnalysis();
void calcRandom(int size, int*& ress, int*& mes);
void calcASorted(int size, int*& ress, int*& mes);
void calcUSorted(int size, int*& ress, int*& mes);
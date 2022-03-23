#include "sorting.h"
/*
* Title: Sorting and Algorithm Efficiency
* Author: Emrehan Hoþver
* ID: 21903488
* Section: 1
* Assignment: 1
* Description: Homework 
*/


using namespace std;
//swap to use in sorting algorithm 
// it has 3 moves 
void swap(int& a, int& b) {
	int x = a;//move 0 , move += 1
	a = b;//move +=1
	b = x;//move += 1 , move == 3 
	
}
/* double duration;
  clock_t startime = clock();

  duration = 1000* double(clock()-startime)/CLOCKS_PER_SEC ; in milisecond*/// got from cs201 hw2 
void insertionSort(int* arr, const int size, int& compCount, int& moveCount) {
	for (int unsorted = 1; unsorted < size; unsorted++) {

		int next = arr[unsorted];
		moveCount++;
		int loc = unsorted;
		while ((loc > 0) && (arr[loc - 1] > next)) {
			arr[loc] = arr[loc - 1];//move ++
			loc--;
			moveCount++;//arr loc = arr loc-1
			compCount++;//while loop comparison
		}
		arr[loc] = next;
		moveCount++;//arr loc = next
	}
	compCount++;//since we compare it at the end of while loop but due to false return value, we dont increment it 
}

void bubbleSort(int* arr, const int size, int& compCount, int& moveCount) {
	int check = size - 2;

	while (check >= 0) {
		for (int i = 0; i <= check; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				//swap mc += 3
				moveCount += 3;
			}
			
			compCount++;//in if statement
		}
		check -= 1;
	}
}

void mergeSort(int* arr, const int size, int& compCount, int& moveCount) {
	mergeSort(arr, 0, size - 1, compCount, moveCount);// we need start and end variables (0,size-1) as it is in the book 
}

void mergeSort(int* arr, int start, int end, int& compCount, int& moveCount) {
	if (start != end) {
		int middle = (start + end)  / 2;
		mergeSort(arr, start, middle, compCount, moveCount);
		mergeSort(arr, middle + 1, end, compCount, moveCount);
		merge(arr, start, middle, end, compCount, moveCount);// to merge sorted sub arrays 

	}

}

void merge(int* arr, int start, int middle, int end, int& compCount, int& moveCount) {

	int* temparr = new int[end - start + 1];
	int f1 = start;
	
	int f2 = middle + 1;


	int index = 0;
	while ((f1 <= middle) && (f2 <= end)) {

		if (arr[f2] < arr[f1]) {
			temparr[index++] = arr[f2];
			f2+=1;
		}
		else {
			temparr[index++] = arr[f1];
			f1+=1;
		}
	
		moveCount++;//assignment +1
		compCount++;// arr comparison

	}
	while (f1 <= middle) {

		temparr[index++] = arr[f1];
		
		f1+=1;
		moveCount++; // assignment +1
	}

	while (f2 <= end) {

		temparr[index++] = arr[f2];
		
		f2 += 1;
		moveCount++;//assignment + 1 

	}
	for (int i = 0; i < index; i++) {

		arr[i + start] = temparr[i];
		moveCount++;//assignment + 1 for every step of for loop 
	}
	delete[] temparr; // deallocation of dynamic memeory which was allocated for merge
}
void quickSort(int* arr, const int size, int& compCount, int& moveCount) {

	quickSort(arr, 0, size - 1, compCount, moveCount);

}

void quickSort(int* arr, int first, int last, int& compCount, int& moveCount) {

	int piv;

	if (first < last) {// check if there is a array to be sorted 

		partition(arr, first, piv, last, compCount, moveCount);
		quickSort(arr, first, piv - 1, compCount, moveCount);
		quickSort(arr, piv + 1, last, compCount, moveCount);

	}

}

void partition(int* arr, int first, int& piv, int last, int& compCount, int& moveCount) {

	int pivot = arr[first];
	piv = first;
	
	moveCount++;

	int endq1 = first;
	int fu = first + 1;

	
	for (; fu <= last; ++fu)
	{
		compCount++;
		if (arr[fu] < pivot)
		{
			endq1++;
			swap(arr[fu], arr[endq1]);
			moveCount += 3;
		}
	}
	
	swap(arr[first], arr[endq1]);
	

	moveCount += 3;
	piv = endq1;
}


void displayArray( int* arr,  int size) {
	cout << "Array is: ";
	if (arr != NULL) {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << ", ";
		}
	}
	else {
		cout << "empty \n";
	}
}

void createRandomArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {
	
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		int randomNumber = rand() % size + 1; // betwenn 0 and 15 to get wanted index 
		arr1[i] = randomNumber;
		arr2[i] = randomNumber;
		arr3[i] = randomNumber;
		arr4[i] = randomNumber;
	}
}

void createAlmostSortedArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {

	int start = 0;
	srand(time(NULL));
	int size2 = (int)(size / 10);
	for (int i = 0; i <size; i++) {
		 
		arr1[i] = i;
		arr2[i] = i;
		arr3[i] = i;
		arr4[i] = i;
	}
	// to sort random array that are created by given numbers
	
	
	
	for (; start < size2; start++) {
	int randomm1 = rand() % size ;
	int randomm2 = rand() % size;
	
	swap(arr1[randomm1], arr1[randomm2]);
	swap(arr2[randomm1], arr2[randomm2]);
	swap(arr3[randomm1], arr3[randomm2]);
	swap(arr4[randomm1], arr4[randomm2]);

	}
	
	/*displayArray(arr1, size);
	displayArray(arr2, size);
	displayArray(arr3, size);

	displayArray(arr4, size);*/


	
	
}

void createAlmostUnsortedArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {

	int start = 0;
	srand(time(NULL));
	int size2 = (int)(size / 10);

	for (int i = 0; i < size; i++) {
		 
		arr1[i] = size-i;
		arr2[i] = size-i;
		arr3[i] = size-i;
		arr4[i] = size-i;
	}
	for (; start < size2; start++) {
		int randomm1 = rand() % size;
		int randomm2 = rand() % size;

		swap(arr1[randomm1], arr1[randomm2]);
		swap(arr2[randomm1], arr2[randomm2]);
		swap(arr3[randomm1], arr3[randomm2]);
		swap(arr4[randomm1], arr4[randomm2]);

	}
	// swap elements of sorted array with their symetrics 
	// by that we are creating a near reverse array 
	// nearly unsorted
	/*for (; start < last; start ++) {
		if (start < last) {
			swap(arr1[start], arr1[last]);
			swap(arr2[start], arr2[last]);
			swap(arr3[start], arr3[last]);
			swap(arr4[start], arr4[last]);
		}
		
		last -= 1;
	}*/

}



void print1(string s) {
	if (s == "insertion") {
		cout << "--------------------------------------\n";
		cout << "Insertion Sort \n";
		cout << "Array Size\tElapsed Time\tcompCount\tmoveCount\t \n";

	}
	else if (s == "bubble") {
		cout << "--------------------------------------\n";
		cout << "Bubble Sort \n";
		cout << "Array Size\tElapsed Time\tcompCount\tmoveCount\t \n";
	}
	else if (s == "quick") {
		cout << "--------------------------------------\n";
		cout << "Quick Sort \n";
		cout << "Array Size\tElapsed Time\tcompCount\tmoveCount\t \n";
	}

	else if (s == "merge") {
		cout << "--------------------------------------\n";
		cout << "Merge Sort \n";
		cout << "Array Size\tElapsed Time\tcompCount\tmoveCount\t \n";
	}
	else
		cout << "INVALID ALGORITHM!!!!!!\n";
}

double measureTime(int* arr, int size, string s, int* mes) {

	
	int mc = 0;//move count
	int cc = 0;// compare count

	if (s == "insertion") {
		double duration;
		clock_t startime = clock();
		//cout << startime << " ";
		//insertionSort(arr, size, cc, mc);
		/*std::chrono::time_point< std::chrono::system_clock > startTime;
		std::chrono::duration< double, milli > elapsedTime;*/
		//Store the starting time
		//startTime = std::chrono::system_clock::now();
	
			insertionSort(arr, size, cc, mc);
			//Compute the number of seconds that passed since the starting
		
		//elapsedTime = std::chrono::system_clock::now() - startTime;
		//cout << "Execution took " << elapsedTime.count() << "milliseconds." << endl;
	
		duration =  (double)(clock()-startime)*10000/ CLOCKS_PER_SEC;
	//	double duration = elapsedTime.count();

		mes[0] = mc;
		mes[1] = cc;
		return duration;

	}
	else if (s == "bubble") {
		double duration;
		clock_t startime = clock();
		bubbleSort(arr, size, cc, mc);
		duration = 1000 * double(clock() - startime) / CLOCKS_PER_SEC;
	
		
		//std::chrono::time_point< std::chrono::system_clock > startTime;
		//std::chrono::duration< double, milli  > elapsedTime;
		////Store the starting time
		//startTime = std::chrono::system_clock::now();

		//bubbleSort(arr, size, cc, mc);
		////Compute the number of seconds that passed since the starting

		//elapsedTime = std::chrono::system_clock::now() - startTime;
		//cout << "Execution took " << elapsedTime.count() << "milliseconds." << endl;

		////	double duration =  (double)(clock()-startime)*10000/ CLOCKS_PER_SEC;
		////double duration = elapsedTime.count() ;

		
		mes[0] = mc;
		mes[1] = cc;
		return duration;



	}
	else if (s == "quick") {
		//std::chrono::time_point< std::chrono::system_clock > startTime;
		//std::chrono::duration< double, milli > elapsedTime;
		////Store the starting time
		//startTime = std::chrono::system_clock::now();
		//cout << "debugging2 \n";
		//quickSort(arr, size, cc, mc);
		////Compute the number of seconds that passed since the starting

		//elapsedTime = std::chrono::system_clock::now() - startTime;
		//cout << "Execution took " << elapsedTime.count() << "milliseconds." << endl;

		////	double duration =  (double)(clock()-startime)*10000/ CLOCKS_PER_SEC;
		//double duration = elapsedTime.count();
		double duration;
		clock_t startime = clock();
		quickSort(arr, size, cc, mc);
		duration = 1000 * double(clock() - startime) / CLOCKS_PER_SEC;


		mes[0] = mc;
		mes[1] = cc;
		return duration;


	}

	else if (s == "merge") {
		//std::chrono::time_point< std::chrono::system_clock > startTime;
		//std::chrono::duration< double, milli > elapsedTime;
		////Store the starting time
		//startTime = std::chrono::system_clock::now();

		//mergeSort(arr, size, cc, mc);
		////Compute the number of seconds that passed since the starting

		//elapsedTime = std::chrono::system_clock::now() - startTime;
		//cout << "Execution took " << elapsedTime.count() << "milliseconds." << endl;

		////	double duration =  (double)(clock()-startime)*10000/ CLOCKS_PER_SEC;
		//double duration = elapsedTime.count() * 1000;
		double duration;
		clock_t startime = clock();
		mergeSort(arr, size, cc, mc);
		duration = 1000 * double(clock() - startime) / CLOCKS_PER_SEC;


		mes[0] = mc;
		mes[1] = cc;
		return duration;



	}
	else {
		cout << "INVALID ALGORITHM!!!!!!\n";
		mes[0] = mc;
		mes[1] = cc;
		return 0;

	}


}
void performanceAnalysis() {
	int params[8] = { 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000 };
	int results[4][24];// rows for algo colunms for data 24(0,7 random 8,15 almostSorted 15,23 amnotUnsorted)
	int moveCountss[4][24];
	int compCountss[4][24];
	int* results1 = new int[4];
	int* mes = new int[8];

	for (int i = 0; i < 24; i++) {

		if (i < 8) {
			calcRandom(params[i %8], results1, mes);
			results[0][i] = results1[0];
			results[1][i] = results1[1];
			results[2][i] = results1[2];
			results[3][i] = results1[3];
			moveCountss[0][i] = mes[0];
			moveCountss[1][i] = mes[2];
			moveCountss[2][i] = mes[4];
			moveCountss[3][i] = mes[6];
			compCountss[0][i] = mes[1];
			compCountss[1][i] = mes[3];
			compCountss[2][i] = mes[5];
			compCountss[3][i] = mes[7];
			//cout << "\n bum " << i << "\n";
		}

	
		
		else if (i >= 8 && i < 16) {
			calcASorted(params[i % 8], results1, mes);
			//calcRandom(params[i % 8], results1, mes);
			results[0][i] = results1[0];
			results[1][i] = results1[1];
			results[2][i] = results1[2];
			results[3][i] = results1[3];
			moveCountss[0][i] = mes[0];
			moveCountss[1][i] = mes[2];
			moveCountss[2][i] = mes[4];
			moveCountss[3][i] = mes[6];
			compCountss[0][i] = mes[1];
			compCountss[1][i] = mes[3];
			compCountss[2][i] = mes[5];
			compCountss[3][i] = mes[7];
			//cout << "\n bum " << i << "\n";
			
		}

	

		else if (i >= 16 && i < 24) {
			calcUSorted(params[i % 8], results1, mes);

			results[0][i] = results1[0];
			results[1][i] = results1[1];
			results[2][i] = results1[2];
			results[3][i] = results1[3];
			moveCountss[0][i] = mes[0];
			moveCountss[1][i] = mes[2];
			moveCountss[2][i] = mes[4];
			moveCountss[3][i] = mes[6];
			compCountss[0][i] = mes[1];
			compCountss[1][i] = mes[3];
			compCountss[2][i] = mes[5];
			compCountss[3][i] = mes[7];
			//cout << "\n bum " << i << "\n";
		
		}




	}
	//cout << "\n bum bum bum :   \n";
	delete[] results1;
	delete[] mes;
	// buradan devam et yazdýrmak için 
	cout << "ANALYSIS FOR RANDOM ARRAYS !!!!!!!! \n \n ";
	print1("insertion");
	for (int i = 0; i < 8; i++) {
		cout << params[i % 8] << "\t\t" << results[0][i] << "\t\t" << moveCountss[0][i] << "\t\t" << compCountss[0][i] << "\n";
	}
	print1("bubble");
	for (int i = 0; i < 8; i++) {
		cout << params[i % 8] << "\t\t" << results[1][i] << "\t\t" << moveCountss[1][i] << "\t\t" << compCountss[1][i] << "\n";
	}
	print1("merge");
	for (int i = 0; i < 8; i++) {
		cout << params[i % 8] << "\t\t" << results[2][i] << "\t\t" << moveCountss[2][i] << "\t\t" << compCountss[2][i] << "\n";
	}
	print1("quick");
	for (int i = 0; i < 8; i++) {
		cout << params[i % 8] << "\t\t" << results[3][i] << "\t\t" << moveCountss[3][i] << "\t\t" << compCountss[3][i] << "\n";
	}
	cout << "ANALYSIS FOR ALMOST SORTED ARRAYSSS !!!!!!!!!!!!!!!! \n \n ";
	print1("insertion");
	for (int i = 8; i < 16; i++) {
		cout << params[i % 8] << "\t\t" << results[0][i] << "\t\t" << moveCountss[0][i] << "\t\t" << compCountss[0][i] << "\n";
	}
	print1("bubble");
	for (int i = 8; i < 16; i++) {
		cout << params[i % 8] << "\t\t" << results[1][i] << "\t\t" << moveCountss[1][i] << "\t\t" << compCountss[1][i] << "\n";
	}
	print1("merge");
	for (int i = 8; i < 16; i++) {
		cout << params[i % 8] << "\t\t" << results[2][i] << "\t\t" << moveCountss[2][i] << "\t\t" << compCountss[2][i] << "\n";
	}
	print1("quick");
	for (int i = 16; i < 24; i++) {
		cout << params[i % 8] << "\t\t" << results[3][i] << "\t\t" << moveCountss[3][i] << "\t\t" << compCountss[3][i] << "\n";
	}
	cout << "ANALYSIS FOR ALMOST UNSORTED ARRAYSS !!!!! \n \n";
	print1("insertion");
	for (int i = 16; i < 24; i++) {
		cout << params[i % 8] << "\t\t" << results[0][i] << "\t\t" << moveCountss[0][i] << "\t\t" << compCountss[0][i] << "\n";
	}
	print1("bubble");
	for (int i = 16; i < 24; i++) {
		cout << params[i % 8] << "\t\t" << results[1][i] << "\t\t" << moveCountss[1][i] << "\t\t" << compCountss[1][i] << "\n";
	}
	print1("merge");
	for (int i = 16; i < 24; i++) {
		cout << params[i % 8] << "\t\t" << results[2][i] << "\t\t" << moveCountss[2][i] << "\t\t" << compCountss[2][i] << "\n";
	}
	print1("quick");
	for (int i = 16; i < 24; i++) {
		cout << params[i % 8] << "\t\t" << results[3][i] << "\t\t" << moveCountss[3][i] << "\t\t" << compCountss[3][i] << "\n";
	}
}
void calcRandom(int size, int*& ress, int*& mes) {
	int* temp1 = new int[size];
	int* temp2 = new int[size];
	int* temp3 = new int[size];
	int* temp4 = new int[size];
	int* temp6 = new int[2];
	int* temp5 = new int[8];

	createRandomArrays(temp1, temp2, temp3, temp4, size);


	int r1 = measureTime(temp1, size, "insertion", temp6);
	
	temp5[0] = temp6[0];
	temp5[1] = temp6[1];

	int r2 = measureTime(temp2, size, "bubble", temp6);
	temp5[2] = temp6[0];
	temp5[3] = temp6[1];
	int r3 = measureTime(temp3, size, "merge", temp6);
	
	temp5[4] = temp6[0];
	temp5[5] = temp6[1];
	int r4 = measureTime(temp4, size, "quick", temp6);
 	temp5[6] = temp6[0];
	temp5[7] = temp6[1];

	for (int i = 0; i < 8; i++) {
		mes[i] = temp5[i];

	}

	ress[0] = r1;
	ress[1] = r2;
	ress[2] = r3;
	ress[3] = r4;

	delete[] temp1;
	delete[] temp2;
	delete[] temp3;
	delete[] temp4;
	delete[] temp5;
	delete[] temp6;

}
void calcASorted(int size, int*& ress, int*& mes) {
	int* temp1 = new int[size];
	int* temp2 = new int[size];
	int* temp3 = new int[size];
	int* temp4 = new int[size];
	int* temp6 = new int[2];
	int* temp5 = new int[8];

	createAlmostSortedArrays(temp1, temp2, temp3, temp4, size);


	int r1 = measureTime(temp1, size, "insertion", temp6);

	temp5[0] = temp6[0];
	temp5[1] = temp6[1];

	int r2 = measureTime(temp2, size, "bubble", temp6);
	temp5[2] = temp6[0];
	temp5[3] = temp6[1];
	int r3 = measureTime(temp3, size, "merge", temp6);
	temp5[4] = temp6[0];
	temp5[5] = temp6[1];
	
	int r4 = measureTime(temp4, size, "quick", temp6);
	temp5[6] = temp6[0];
	temp5[7] = temp6[1];

	for (int i = 0; i < 8; i++) {
		mes[i] = temp5[i];

	}

	ress[0] = r1;
	ress[1] = r2;
	ress[2] = r3;
	ress[3] = r4;

	delete[] temp1;
	delete[] temp2;
	delete[] temp3;
	delete[] temp4;
	delete[] temp5;
	delete[] temp6;

}
void calcUSorted(int size, int*& ress, int*& mes) {
	int* temp1 = new int[size];
	int* temp2 = new int[size];
	int* temp3 = new int[size];
	int* temp4 = new int[size];
	int* temp6 = new int[2];
	int* temp5 = new int[8];

	createAlmostUnsortedArrays(temp1, temp2, temp3, temp4, size);


	int r1 = measureTime(temp1, size, "insertion", temp6);

	temp5[0] = temp6[0];
	temp5[1] = temp6[1];

	int r2 = measureTime(temp2, size, "bubble", temp6);
	temp5[2] = temp6[0];
	temp5[3] = temp6[1];
	int r3 = measureTime(temp3, size, "merge", temp6);
	temp5[4] = temp6[0];
	temp5[5] = temp6[1];
	int r4 = measureTime(temp4, size, "quick", temp6);
	temp5[6] = temp6[0];
	temp5[7] = temp6[1];

	for (int i = 0; i < 8; i++) {
		mes[i] = temp5[i];

	}

	ress[0] = r1;
	ress[1] = r2;
	ress[2] = r3;
	ress[3] = r4;

	delete[] temp1;
	delete[] temp2;
	delete[] temp3;
	delete[] temp4;
	delete[] temp5;
	delete[] temp6;

}
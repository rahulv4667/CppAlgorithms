#pragma once
#include<iostream>
#include<vector>


template<typename T>
void print(std::vector<T>& vec) {
	std::cout << std::endl;
	for (int i = 0; i < vec.size(); i++) {
		std::cout << " " << vec[i] << " ";
	}
	std::cout << std::endl;
}

////////////////////////
///////// SWAP /////////
////////////////////////
template<typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

////////////////////////
////////////////////////
//// INSERTION SORT ////
////////////////////////
////////////////////////

template<typename T>
void insertionSort(std::vector<T>& vec) {

	for (int i = 1; i < vec.size(); i++) {
		T temp = vec[i];
		int j = i - 1;
		while (j > 0 && vec[j] > temp) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = temp;
	}

}

/////////////////////////
/////////////////////////
////// MERGE SORT ///////
/////////////////////////
/////////////////////////

template<typename T>
void merge(std::vector<T>& vec, int beg, int mid, int end) {

	int i = beg, j = mid + 1;
	std::vector<T> temp(end - beg + 1,0);
	int k = 0;

	while (i <= mid && j <= end) {
		if (vec[i] < vec[j]) {
			temp[k] = vec[i];
			i++;
		}
		else {
			temp[k] = vec[j];
			j++;
		}
		k++;
	}

	while (i <= mid) {
		temp[k++] = vec[i];
		i++;
	}

	while (j <= end) {
		temp[k++] = vec[j];
		j++;
	}

	for (k = 0; beg + k <= end; k++) {
		vec[beg + k] = temp[k];
	}

}
	

template<typename T>
void mSort(std::vector<T>& vec, int beg, int end) {
	if (beg < end) {
		int mid = beg + ((end - beg) / 2);
		mSort(vec, beg, mid);
		mSort(vec, mid + 1, end);
		merge(vec, beg, mid, end);
	}
}


template<typename T>
void mergeSort(std::vector<T>& vec) {
	mSort(vec, 0, vec.size() - 1);
}




///////////////////////////
///////////////////////////
/////// BUBBLE SORT ///////
///////////////////////////
///////////////////////////

template<typename T>
void bubbleSort(std::vector<T>& vec) {
	int lastUnsorted = vec.size()-1;
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < lastUnsorted; i++) {
			if (vec[i] > vec[i + 1]) {
				swap(vec[i], vec[i + 1]);
				/*vec[i] = vec[i] + vec[i + 1];
				vec[i + 1] = vec[i] - vec[i + 1];
				vec[i] = vec[i] - vec[i + 1];*/
				swapped = true;
			}
		}
		lastUnsorted--;
		
	} while (swapped);
}




//////////////////////////////////
//////////////////////////////////
////////// QUICK SORT ////////////
//////////////////////////////////
//////////////////////////////////

template<typename T>
int partition(std::vector<T>& vec, int beg, int end) {

	int pIndex = beg;
	T pivotElem = vec[beg];

	for (int i = beg + 1; i < end + 1; i++) {
		if (vec[i] <= pivotElem) {

			pIndex++;
			swap(vec[pIndex], vec[i]);
		
		}
	}

	swap(vec[pIndex], vec[beg]);

	return pIndex;
}

template<typename T>
void qSort(std::vector<T>& vec, int beg, int end) {
	if (beg < end) {
		int p = partition(vec, beg, end);
		qSort(vec, beg, p - 1);
		qSort(vec, p + 1, end);
	}
}

template<typename T>
void quickSort(std::vector<T>& vec) {
	qSort(vec, 0, vec.size() - 1);
}


////////////////////////////////////
////////////////////////////////////
///////// SELECTION SORT ///////////
////////////////////////////////////
////////////////////////////////////
template<typename T>
void selectionSort(std::vector<T>& vec) {
	int minIndex;
	for (int i = 0; i < vec.size(); i++) {
		minIndex = i;
		for (int j = i + 1; j < vec.size(); j++) {
			if (vec[j] < vec[minIndex])
				minIndex = j;
		}
		swap(vec[i], vec[minIndex]);
	}

}



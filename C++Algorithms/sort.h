#pragma once
#include<iostream>
#include<vector>

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



template<typename T>
void merge(std::vector<T>& vec, int beg, int mid, int end) {

	int i = beg, j = mid + 1;
	std::vector<T> temp(end - beg + 1);
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

	while (i++ <= mid) {
		temp[k++] = vec[i];
	}

	while (j++ <= end) {
		temp[k++] = vec[j];
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






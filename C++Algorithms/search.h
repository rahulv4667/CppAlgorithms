#pragma once
#include<vector>

template<typename T>
int linear_search(const std::vector<T>& vec, T elem) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == elem) {
			return i;
		}
	}
	return -1;
}


template<typename T>
int binary_search(const std::vector<T>& vec, T elem) {
	int beg = 0, end = vec.size() - 1;
	while (beg < end) {
		int mid = beg + ((end - beg) / 2);
		if (vec[mid] == elem) return mid;
		if (vec[mid] < elem) beg = mid + 1;
		if (vec[mid] > elem) end = mid - 1;
	}
	if (beg == end && vec[beg] == elem) return beg;
	return -1;
}
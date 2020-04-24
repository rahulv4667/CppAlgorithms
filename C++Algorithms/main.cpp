#include<iostream>
#include<vector>
#include"sort.h"

int main(void) {
	std::vector<int> v;
	int n;
	std::cout << "Enter number of elements:";
	std::cin >> n;
	std::cout << std::endl << "Enter elements:";
	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;
		v.push_back(temp);
	}
	/*v.push_back(5);
	v.push_back(4);
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);*/
	//insertionSort(v);
	mergeSort(v);
	std::cout << std::endl << "Elements after sorting:";
	for (int i = 0; i < n; i++)
		std::cout << v[i] << "\t";
	char c;
	std::cin >> c;
}
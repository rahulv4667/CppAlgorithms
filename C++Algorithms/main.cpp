#include<iostream>
#include<vector>
#include"sort.h"
#include"search.h"

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
	std::cout << std::endl << "Enter search element:";
	int elem;
	std::cin >> elem;
	std::cout << std::endl << "Index of search element before sorting:" << linear_search(v, elem) << std::endl;
	/*v.push_back(5);
	v.push_back(4);
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);*/
	//insertionSort(v);
	//mergeSort(v);
	count_sort(v);
	std::cout << std::endl << "Elements after sorting:";
	for (int i = 0; i < n; i++)
		std::cout << v[i] << "\t";
	std::cout << std::endl << "Index of search element after sorting:" << binary_search(v, elem) << std::endl;
	
}
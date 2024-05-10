#pragma once
#include <vector>

using namespace std;

int SearchIntInterpolation(vector<int> vect, int key) {
	int l_index = 0;
	int r_index = vect.size() - 1;
	int mid_index = 0;

	do {

		mid_index = l_index + 
			((key - vect[l_index]) * (r_index - l_index)) / 
			(vect[r_index] - vect[l_index]);
		
		if (vect[mid_index] < key) {
			l_index = mid_index + 1;
		}
		else if (vect[mid_index] > key) {
			r_index = mid_index - 1;
		}

	} while (vect[mid_index] != key && l_index < r_index);


	if (vect[mid_index] == key) {
		return mid_index;
	}
	else {
		return -1;
	}
}
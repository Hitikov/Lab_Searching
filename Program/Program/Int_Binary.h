#pragma once
#include <vector>

using namespace std;

int SearchIntBinary(vector<int> vect, int key) {
	int r_index = vect.size();
	int l_index = 0;
	int mid_index;
	do {
		mid_index = (l_index + r_index) / 2;
		if (vect[mid_index] < key) {
			l_index = mid_index + 1;
		}
		else if (vect[mid_index] > key) {
			r_index = mid_index - 1;
		}
	} while (vect[mid_index] != key && (l_index < r_index));

	if (vect[mid_index] == key) {
		return mid_index;
	}
	else {
		return -1;
	}
}

#pragma once
#include <vector>

using namespace std;

int SearchIntLinear(vector<int> vect, int key) {
	int index = 0;
	for (; index < vect.size() && vect[index] != key; index++);
	if (vect[index] == key) {
		return index;
	}
	else {
		return -1;
	}
}
#pragma once
#include <string>

using namespace std;

int SearchStrLinear(string base_str, string key_str) {
	int index = 0;
	int sub_index;
	bool isFind = false;
	for (; index < base_str.size() - key_str.size() && isFind == false; index++) {
		sub_index = 0;
		for (; sub_index < key_str.size() && 
			base_str[index + sub_index] == key_str[sub_index]; sub_index++);
		if (sub_index == key_str.size()) {
			isFind = true;
		}
	}

	if (isFind) {
		return index - 1;
	}
	else {
		return -1;
	}

}
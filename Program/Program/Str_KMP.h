#pragma once
#include <string>

using namespace std;

void prefix_func(string key_str, int* table) {
	table[0] = 0;
	int l_index = 0; 
	int r_index = 1;

	while (r_index < key_str.size()) {
		if (key_str[r_index] == key_str[l_index]) {
			table[r_index] = l_index + 1;
			l_index++;
			r_index++;
		}
		else if (l_index == 0) {
			table[r_index] = 0;
			r_index++;
		}
		else {
			l_index = table[l_index - 1];
		}
	}
}

int SearchStrKMP(string base_str, string key_str) {
	int subSize = key_str.size();
	int* table = new int[subSize] {};
	
	prefix_func(key_str, table);

	bool isFind = false;
	int index = 0;
	int sub_index;

	while (index < base_str.size() - subSize + 1 && !isFind){
		sub_index = 0;
		
		for (; sub_index < subSize && 
			base_str[index + sub_index] == key_str[sub_index]; sub_index++);

		if (sub_index == subSize) {
			isFind = true;
		}
		else if (sub_index == 0) {
			index++;
		}
		else {
			if (table[sub_index - 1] != 0) {
				index += table[sub_index - 1];
			}
			else {
				index += sub_index;
			}
		}
	}

	if (isFind) {
		return index;
	}
	else {
		return -1;
	}

}
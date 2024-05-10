#pragma once
#include <string>

using namespace std;

int SearchStrBoyerMoore(string base_str, string key_str) {
	int subSize = key_str.size();
	int table[256];
	bool isFind = false;
	
	int index = subSize - 1;
	int sub_index;

	for (int i = 0; i < 256; i++) {
		table[i] = subSize;
	}

	for (int i = subSize - 2; i > -1; i--) {
		if (table[(int)(unsigned char)key_str[i]] == subSize) {
			table[(int)(unsigned char)key_str[i]] = subSize - 1 - i;
		}
	}
	
	while (index < base_str.size() && isFind == false) {
		sub_index = 0;
		for (; sub_index < subSize &&
			base_str[index - sub_index] == key_str[subSize - 1 - sub_index]; sub_index++);
		if (sub_index == subSize) {
			isFind = true;
		}
		else {
			index += table[(int)(unsigned char)key_str[subSize - sub_index]];
		}
	}

	if (isFind) {
		return index - subSize + 1;
	}
	else {
		return -1;
	}
}
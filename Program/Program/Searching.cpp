#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Int_Linear.h"
#include "Int_Binary.h"
#include "Int_Interpolation.h"
#include "Str_Linear.h"
#include "Str_Boyer_Moore.h"
#include "Str_KMP.h"

typedef int(*ptr_int)(vector<int> vect, int key);
typedef int(*ptr_str)(string base_str, string key_str);

int main() {
	ptr_int func_search_int_ptr[] = { &SearchIntLinear, &SearchIntBinary, &SearchIntInterpolation };
	vector<int> vect[] = {
		{ 34, 55, 19, 87, 43, 4343, 73, -95, 49, 32, 100, 87, 346, 12, 3, -76, -32, 89, 109, 41, 85, 293, 44, 21, 743, 202 },
		{ -77, 2, 4, 7, 12, 19, 20, 23, 29, 30, 30, 32, 33, 33, 34, 43, 45, 49, 54, 55, 73, 75, 83, 83, 87, 89, 99, 99},
		{ 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6 }		
	};
	int key[] = { 346, 75, 5 };

	ptr_str func_search_str_ptr[] = { &SearchStrLinear, &SearchStrBoyerMoore, &SearchStrKMP };
	string base_str = "abcdansdsnfddm";
	string key_str = "ansdsn";

	for (int i = 0; i < 3; i++) {
		cout << "Index of key: " << func_search_int_ptr[i](vect[i], key[i]) << endl;
	}

	for (int i = 0; i < 3; i++) {
		cout << "Index of enterance of substring in string: " << func_search_str_ptr[i](base_str, key_str) << endl;
	}

	return 0;
}
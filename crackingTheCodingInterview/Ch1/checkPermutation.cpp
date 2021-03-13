#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <bitset>
#include <algorithm>
using namespace std;

// Assuming ASCII (only 128 chars)
bool checkPermutation(string str1, string str2) {

	if(str1.length() != str2.length()) return false;

	vector<int> countChar(128, 0);

	for(int i=0; i<str1.length(); ++i) {

		countChar[(int) str1[i]]++;
		countChar[(int) str2[i]]--;
	}

	for(int count: countChar) {

		if(count) return false;
	}

	return true;
}

bool checkPermutationSort(string str1, string str2) {

	if(str1.length() != str2.length()) return false;
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	return str1 == str2;
}

int main() {

	cout<<"Check Permutation"<<endl;

	string str1 = "abccccd";
	string str2 = "abc";
	string str3 = "ccccdab";
	string str4 = "abd";

	assert(!checkPermutation(str1, str2));
	assert(checkPermutation(str1, str3));
	assert(!checkPermutation(str2, str4));

	assert(!checkPermutationSort(str1, str2));
	assert(checkPermutationSort(str1, str3));
	assert(!checkPermutationSort(str2, str4));

	cout<<"All check passed"<<endl;
}
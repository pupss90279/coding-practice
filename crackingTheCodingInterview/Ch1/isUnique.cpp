#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <bitset>
#include <algorithm>
using namespace std;

// Assuming ASCII (only 128 chars)
bool isUniqueBasic(string str) {

	if(str.length() > 128) return false;

	vector<bool> charExist(128, false);

	for(char s: str) {

		if(charExist[(int) s]) return false;
		charExist[(int) s] = true;
	}

	return true;
}

// bool takes up a byte so using bit will reduce space by a factor of 8
bool isUniqueBitManipulation(string str) {

	if(str.length() > 128) return false;

	int checker = 0;

	for(char s: str) {

		int curVal = 1 << ((int) s);

		if(checker & curVal) return false;
		checker |= curVal;
	}

	return true;
}

bool isUniqueBitSet(string str) {

	if(str.length() > 128) return false;

	bitset<128> charExist;

	for(char s: str) {

		int pos = (int) s;

		if(charExist.test(pos)) return false;
		charExist.set(pos);
	}

	return true;
}

bool isUniqueBruteForce(string str) {

	for(int i=0; i<str.length()-1; ++i) {

		for(int j=i+1; j<str.length(); ++j) {

			if(str[i] == str[j]) return false;
		}
	}

	return true;
}

bool isUniqueSort(string str) {

	sort(str.begin(), str.end());
	for(int i=0; i<str.length()-1; ++i) {
		if(str[i] == str[i+1]) return false;
	}

	return true;
}

int main() {

	string test1 = "abcddd";
	string test2 = "acfgrjlk";

	assert(!isUniqueBasic(test1));
	assert(isUniqueBasic(test2));

	assert(!isUniqueBitManipulation(test1));
	assert(isUniqueBitManipulation(test2));

	assert(!isUniqueBitSet(test1));
	assert(isUniqueBitSet(test2));

	assert(!isUniqueBruteForce(test1));
	assert(isUniqueBruteForce(test2));

	assert(!isUniqueSort(test1));
	assert(isUniqueSort(test2));
}
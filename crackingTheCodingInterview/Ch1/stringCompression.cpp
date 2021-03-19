#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;

string compressRepeatedChars(char c, int count) {

	string result{c};
	return c + to_string(count);
}

string stringCompression(string str) {

	if(str.length() <= 2) return str;

	string compressionResult = "";
	int count = 0;

	for(int i=0; i<str.length(); ++i) {

		count++;

		if((i+1) == str.length() || str[i] != str[i+1]) {
			compressionResult += compressRepeatedChars(str[i], count);
			count = 0;
		}
	}

	return str.length() > compressionResult.length() ? compressionResult:str;
} 

int main() {

	string test1 = "aabcccccaaa";
	string test2 = "abc";
	string test3 = "aaabc";
	string test4 = "aaaaaaaaaaabc";

	assert("a2b1c5a3" == stringCompression(test1));
	assert("abc" == stringCompression(test2));
	assert("aaabc" == stringCompression(test3));
	assert("a11b1c1" == stringCompression(test4));
}
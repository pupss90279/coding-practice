#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <bitset>
#include <algorithm>
using namespace std;

bool notLetter(char s) {

	return s > 'Z' || s < 'A';
}

bool palindromePermutation(string str) {

	vector<int> countChar(26, 0);

	for(char s: str) {

		s = toupper(s);

		if(notLetter(s)) continue;

		countChar[s - 'A']++;
	}

	bool hasOdd = false;

	for(int count: countChar) {

		if(count % 2 != 0) {

			if(hasOdd) return false;
			hasOdd = true;
		}
	}

	return true;
}

int main() {

	string test1 = "Tact Coa";
	string test2 = "Tac Coa";
	string test3 = "AbcBa   ";

	assert(palindromePermutation(test1));
	assert(!palindromePermutation(test2));
	assert(palindromePermutation(test3));
}
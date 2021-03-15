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

bool palindromePermutationBitSet(string str) {

	bitset<32> charIndicator;

	for(char s: str) {

		s = toupper(s);

		if(notLetter(s)) continue;

		charIndicator.flip(s - 'A');
	}

	return charIndicator.count() < 2;
}

int main() {

	string test1 = "Tact Coa";
	string test2 = "Tac Coa";
	string test3 = "AbcBa   ";

	assert(palindromePermutation(test1));
	assert(!palindromePermutation(test2));
	assert(palindromePermutation(test3));

	assert(palindromePermutationBitSet(test1));
	assert(!palindromePermutationBitSet(test2));
	assert(palindromePermutationBitSet(test3));
}
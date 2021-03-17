#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;

bool oneReplacement(string str1, string str2) {

	bool replacement = false;

	for(int i=0; i<str1.length(); ++i) {

		if(str1[i] != str2[i]) {

			if(replacement) return false;
			replacement = true;
		}
	}

	return true;
}

bool oneRemoval(string str1, string str2) {

	bool removal = false;

	int j = 0;

	for(int i=0; i<str1.length(); ++i) {

		if(str1[i] != str2[j]) {

			if(removal) return false;
			removal = true;
			continue;
		}

		++j;
	}

	return true;
}

bool checkOneAway(string str1, string str2) {

	int lenDiff = str1.length() - str2.length();
	if(lenDiff == 0) {

		if(str1 == str2) return true;
		return oneReplacement(str1, str2);
	}

	if(abs(lenDiff) == 1) {

		if(str1.length() > str2.length()) return oneRemoval(str1, str2);
		return oneRemoval(str2, str1);
	}

	return false;
}

int main() {

	assert(checkOneAway("pale", "ple"));
	assert(checkOneAway("pale", "pale"));
	assert(checkOneAway("pales", "pale"));
	assert(checkOneAway("pale", "bale"));
	assert(!checkOneAway("pale", "bake"));
	assert(!checkOneAway("pale", "paless"));
	assert(!checkOneAway("pale", "lape"));
}
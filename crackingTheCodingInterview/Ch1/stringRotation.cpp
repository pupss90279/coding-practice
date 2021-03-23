#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;

bool isSubStr(string str1, string str2) {

	return (str1.find(str2) != string::npos);
}

bool isStringRotation(string str1, string str2) {

	if(str1.length() != str2.length()) return false;

	return isSubStr(str1 + str1, str2);
}

int main() {

	string str1 = "waterbottle";
	string str2 = "erbottlewat";

	assert(isStringRotation(str1, str2));
}
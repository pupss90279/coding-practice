#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <bitset>
#include <algorithm>
using namespace std;

void urlify(char* str, int length) {

	int numSpace = 0;

	for(int i=0; i<length; ++i) {

		if(str[i] == ' ') numSpace++;
	}

	int j = length + 2*numSpace -1;

	for(int i = length - 1; i >= 0; --i) {

		if(str[i] == ' ') {

			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';

		} else {

			str[j--] = str[i];
		}
	}
}

int main() {

	//String with extended length ( true length + 2* spaces)
    char str[] = "Mr John Smith    ";
    std::cout << "Actual string   : " << str << std::endl;
    //Length of "Mr John Smith" = 13
    urlify(str, 13);
    std::cout << "URLified string : " << str << std::endl;
    return 0;
}
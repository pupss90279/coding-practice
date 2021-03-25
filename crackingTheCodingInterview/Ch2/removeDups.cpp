#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <bitset>
#include <algorithm>
#include <cmath>
#include "node.h"
using namespace std;

int main() {

	vector<int> test1{1, 2, 3, 4, 5};
	Node* head = createLinkedList(test1);
	printLinkedList(head);
}


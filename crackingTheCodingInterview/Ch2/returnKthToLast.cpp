#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include "node.h"
using namespace std;

Node* returnKthToLast(Node* head, int k) {

	Node* iter = head;

	for(int i=0; i<k; ++i) {

		if(!iter) return NULL;
		iter = iter->next;
	}

	Node* kth = head;

	while(iter) {

		iter = iter->next;
		kth = kth->next;
	}

	return kth;
}

Node* recurHelper(Node* iter, int k, int& curIndex) {

	if(!iter) return NULL;

	Node* node = recurHelper(iter->next, k, curIndex);
	curIndex++;

	if(curIndex == k) return iter;
	return node;
}

Node* returnKthToLastRecursive(Node* head, int k) {

	int index = 0;
	return recurHelper(head, k, index);
}

int main() {

	vector<int> test1{5, 4, 3, 2, 1};
	Node* head = createLinkedList(test1);

	assert((returnKthToLast(head, 1)->data) == 5);
	assert((returnKthToLast(head, 2)->data) == 4);
	assert((returnKthToLast(head, 3)->data) == 3);
	assert((returnKthToLast(head, 4)->data) == 2);
	assert((returnKthToLast(head, 5)->data) == 1);
	assert(returnKthToLast(head, 6) == NULL);
	assert(returnKthToLast(head, 1000) == NULL);
	assert(returnKthToLast(NULL, 1000) == NULL);

	assert((returnKthToLastRecursive(head, 1)->data) == 5);
	assert((returnKthToLastRecursive(head, 2)->data) == 4);
	assert((returnKthToLastRecursive(head, 3)->data) == 3);
	assert((returnKthToLastRecursive(head, 4)->data) == 2);
	assert((returnKthToLastRecursive(head, 5)->data) == 1);
	assert(returnKthToLastRecursive(head, 6) == NULL);
	assert(returnKthToLastRecursive(head, 1000) == NULL);
	assert(returnKthToLastRecursive(NULL, 1000) == NULL);
}
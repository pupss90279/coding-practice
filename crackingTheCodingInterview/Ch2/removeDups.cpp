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

void removeDups(Node* head) {

	unordered_set<int> existValue;
	Node* iter = head;
	Node* prev = NULL;

	while(iter) {

		if(existValue.count(iter->data) == 0) {

			existValue.insert(iter->data);
			prev = iter;
			iter = iter->next;

		} else {

			prev->next = iter->next;
			Node* temp = iter;
			iter = iter->next;
			delete temp;
		}
	}
}

void removeDupsWithNoBuffer(Node* head) {

	Node* iter = head;
	
	while(iter->next) {

		Node* toCompare = iter->next;
		Node* prev = iter;

		while(toCompare) {

			if(toCompare->data == iter->data) {

				prev->next = toCompare->next;
				Node* temp = toCompare;
				toCompare = toCompare->next;
				delete temp;

			} else {

				prev = toCompare;
				toCompare = toCompare->next;
			}
		}

		iter = iter->next;
	}
}

int main() {

	vector<int> test1{1, 2, 3, 4, 5};
	Node* head = createLinkedList(test1);
	removeDups(head);
	printLinkedList(head);

	vector<int> test2{1, 1, 2, 3, 4, 5, 6, 4};
	head = createLinkedList(test2);
	removeDups(head);
	printLinkedList(head);

	vector<int> test3{1, 2, 3, 4, 5, 6, 4, 6, 6, 7, -4};
	head = createLinkedList(test3);
	removeDups(head);
	printLinkedList(head);

	vector<int> test4{1, 2, 3, 4, 5, 6, 4, 6, 6, 7, -4};
	head = createLinkedList(test4);
	removeDupsWithNoBuffer(head);
	printLinkedList(head);

	vector<int> test5{5, 4, 3, 2, 1};
	head = createLinkedList(test5);
	removeDupsWithNoBuffer(head);
	printLinkedList(head);
}


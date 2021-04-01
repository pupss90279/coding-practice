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

void deleteMiddleNode(Node* head, Node* nodeToDelete) {

	if(!head || !nodeToDelete) return;

	Node* iter = head;

	while(iter) {

		if(iter->next == nodeToDelete) {

			iter->next = iter->next->next;
			delete nodeToDelete;
			break;
		}

		iter = iter->next;
	}
}

int main() {

	vector<int> test1{5, 4, 3, 2, 1};
	Node* head = createLinkedList(test1);
	printLinkedList(head);

	deleteMiddleNode(head, head->next->next);
	printLinkedList(head);

	Node* newNode = new Node;
	deleteMiddleNode(head, newNode);
	printLinkedList(head);

	deleteMiddleNode(head, head);
	printLinkedList(head);

	deleteMiddleNode(head, NULL);
	printLinkedList(head);

	deleteMiddleNode(head, head->next);
	printLinkedList(head);
}
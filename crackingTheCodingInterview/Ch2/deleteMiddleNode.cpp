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

void deleteMiddleNodeNoAccessToHead(Node* nodeToDelete) {

	assert(nodeToDelete != NULL);
	assert(nodeToDelete->next != NULL);


	Node* temp = nodeToDelete->next;
	nodeToDelete->data = nodeToDelete->next->data;
	nodeToDelete->next = nodeToDelete->next->next;
	delete temp;
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

	cout<<"-----------------------------"<<endl;

	head = createLinkedList(test1);
	printLinkedList(head);

	deleteMiddleNodeNoAccessToHead(head->next);
	printLinkedList(head);

	deleteMiddleNodeNoAccessToHead(head->next->next);
	printLinkedList(head);
}
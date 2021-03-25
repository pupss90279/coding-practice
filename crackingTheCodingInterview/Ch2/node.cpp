#include "node.h"
using namespace std;

Node* createLinkedList(vector<int> data) {

	Node* head = NULL;

	for(int d: data) {

		Node* newNode = new Node;
		newNode->data = d;
		newNode->next = head;
		head = newNode;
	}

	return head;
}

void printLinkedList(Node* head) {

	Node* iter = head;

	while(iter) {

		cout<<iter->data<<" -> ";
		iter = iter->next;
	}

	cout<<"end"<<endl;
}


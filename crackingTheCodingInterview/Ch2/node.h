#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int data = 0;
	Node* next = NULL;
};

Node* createLinkedList(vector<int> data);

void printLinkedList(Node* head);

#pragma once
#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H
#include <stddef.h>

class Single_Linked_List
{
public:
	Single_Linked_List();

	void push_front(const int& value);
	void push_back(const int& value);
	int pop_front();
	int pop_back();
	int front();
	int back();
	bool empty();
	size_t size();

	void insert(size_t index, const int& item);
	bool remove(size_t index);
	size_t find(const int& value);

private:
	struct Node
	{
		int data;
		Node* next;
		Node* prev;
	};

	Node* Head;
	Node* Tail;
	size_t numItems;
};

#endif

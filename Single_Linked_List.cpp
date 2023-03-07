/*****************************************************************//**
 * \file   Single_Linked_List.cpp
 * \brief  Assignment 2
 * 
 * \author Mike McDonough
 * \date   March 2023
 *********************************************************************/
#include "Single_Linked_List.h"
#include <iostream>
#include <stdlib.h>

Single_Linked_List::Single_Linked_List()
{
	//Create initial values
	Head = NULL;
	Tail = NULL;
	numItems = 0;
}

void Single_Linked_List::push_front(const int& value)
{
	//make a new node
	Node* newNode = new Node();
	newNode->data = value;
	//if the list is empty, just set the head and tail to the new node
	if (Head == NULL)
	{
		Head = newNode;
		Tail = newNode;
	}
	// if not, then shift the list over to the right.
	else
	{
		newNode->next = Head;
		newNode->next->prev = newNode;
		Head = newNode;
	}
	numItems++;
}

void Single_Linked_List::push_back(const int& value)
{
	// make a new node
	Node *newNode = new Node();
	newNode->data = value;
	//if the list is empty, just set the head and tail to the new node
	if (Tail == NULL)
	{
		Head = newNode;
		Tail = newNode;
	}
	//if not, then shift the tail to accomodate
	else
	{
		newNode->prev = Tail;
		newNode->prev->next = newNode;
		Tail = newNode;
	}
	numItems++;
}

int Single_Linked_List::pop_front()
{
	//if empty, then just return 0
	if (numItems == 0)
	{
		return 0;
	}
	//if only one item, then remove and don't bother trying to check for other pointers
	if (numItems == 1)
	{
		int value = Head->data;
		delete Head;
		Head = NULL;
		Tail = NULL;
		numItems--;
		return value;
	}
	//remove head and assign a new one
	Node* newHead = Head->next;
	int value = Head->data;
	delete Head;
	Head = newHead;
	Head->prev = NULL;
	numItems--;
	return value;

}

int Single_Linked_List::pop_back()
{
	//if empty, then just return 0
	if (numItems == 0)
	{
		return 0;
	}
	//if only one item, then remove and don't bother trying to check for other pointers
	if (numItems == 1)
	{
		int value = Head->data;
		delete Head;
		Head = NULL;
		Tail = NULL;
		numItems--;
		return value;
	}
	//remove the current tail and assign a new one
	Node* newTail = Tail->prev;
	int value = Tail->data;
	delete Tail;
	Tail = newTail;
	numItems--;
	return value;

}

int Single_Linked_List::front()
{
	//if empty, return zero
	if (Head == NULL)
	{
		return 0;
	}
	//return data without modifying the list
	else
	{
		return Head->data;
	}
}

int Single_Linked_List::back()
{
	//if empty, return zero
	if (Tail == NULL)
	{
		return 0;
	}
	//return data without modifying the list
	else
	{
		return Tail->data;
	}
}

bool Single_Linked_List::empty()
{
	//check if any items
	return (numItems == 0);
}

size_t Single_Linked_List::size()
{
	//return the number of items
	return numItems;
}

void Single_Linked_List::insert(size_t index, const int& item)
{
	//if index is negative, just return
	if (index < 0)
		return;
	//if the index is too high, just put at the end
	if (index >= numItems)
	{
		push_back(item);
		return;
	}
	//if the first index, just push to the front
	if (index == 0)
	{
		push_front(index);
		return;
	}
	//make a new node
	Node* newNode = new Node();
	newNode->data = item;
	Node* currentNode = Head;
	//move through the list to the desired index
	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->next;
	}
	//splice the list and insert the node
	newNode->prev = currentNode;
	newNode->next = currentNode->next;
	currentNode->prev->next = currentNode;
	newNode->next->prev = newNode;
	//increment the number of items
	numItems++;
}

bool Single_Linked_List::remove(size_t index)
{
	//if empty, a negative index, or too high of an index, fail
	if (Head == NULL || index < 0 || index >= numItems)
		return false;
	
	Node* currentNode = Head;
	if (index == 0)
	{
		//if there is only one item, we'll get null pointer issues
		if (numItems != 1)
		{
			Head->next->prev = NULL;
			Head = Head->next;
		}
		delete currentNode;
		numItems--;
		return true;
	}
	//removing the tail
	if (index == numItems - 1)
	{
		currentNode = Tail; 
		Tail->prev->next = NULL;
		Tail = Tail->prev;
		delete currentNode;
		numItems--;
		return true;
	}
	//shift to desired index
	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->next;
	}
	//splice the list and remove a node
	currentNode->prev->next = currentNode->next;
	currentNode->next->prev = currentNode->prev;
	if (currentNode->prev == NULL)
		Head = currentNode;
	if (currentNode)
	delete currentNode;
	//increment number of items
	numItems--;
}

size_t Single_Linked_List::find(const int& value)
{
	//start at the front
	Node* currentNode = Head;
	//shift through the list
	for (int i = 0; i < numItems; i++)
	{
		if (currentNode->data == value) return i;
		//if the next node isn't defined, just return
		if (currentNode->next == NULL) return numItems;
		currentNode = Head->next;
	}
}

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
	Head = NULL;
	Tail = NULL;
	numItems = 0;
}

void Single_Linked_List::push_front(const int& value)
{
	Node* newNode = new Node();
	newNode->data = value;
	if (Head == NULL)
	{
		Head = newNode;
		Tail = newNode;
	}
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
	Node *newNode = new Node();
	newNode->data = value;
	if (Tail == NULL)
	{
		Head = newNode;
		Tail = newNode;
	}
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
	if (numItems == 0)
	{
		return 0;
	}
	if (numItems == 1)
	{
		int value = Head->data;
		delete Head;
		Head = NULL;
		Tail = NULL;
		numItems--;
		return value;
	}

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
	if (numItems == 0)
	{
		return 0;
	}
	if (numItems == 1)
	{
		int value = Head->data;
		delete Head;
		Head = NULL;
		Tail = NULL;
		numItems--;
		return value;
	}

	Node* newTail = Tail->prev;
	int value = Tail->data;
	delete Tail;
	Tail = newTail;
	numItems--;
	return value;

}

int Single_Linked_List::front()
{
	if (Head == NULL)
	{
		return 0;
	}
	else
	{
		return Head->data;
	}
}

int Single_Linked_List::back()
{
	if (Tail == NULL)
	{
		return 0;
	}
	else
	{
		return Tail->data;
	}
}

bool Single_Linked_List::empty()
{
	return (numItems == 0);
}

size_t Single_Linked_List::size()
{
	return numItems;
}

void Single_Linked_List::insert(size_t index, const int& item)
{
	if (index < 0)
		return;
	if (index >= numItems)
	{
		push_back(item);
		return;
	}
	if (index == 0)
	{
		push_front(index);
		return;
	}

	Node* newNode = new Node();
	newNode->data = item;
	Node* currentNode = Head;
	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->next;
	}
	newNode->prev = currentNode;
	newNode->next = currentNode->next;
	currentNode->prev->next = currentNode;
	newNode->next->prev = newNode;
	numItems++;
}

bool Single_Linked_List::remove(size_t index)
{
	if (Head == NULL || index < 0 || index >= numItems)
		return false;
	
	Node* currentNode = Head;
	if (index == 0)
	{
		if (numItems != 1)
		{
			Head->next->prev = NULL;
			Head = Head->next;
		}
		delete currentNode;
		numItems--;
		return true;
	}
	if (index == numItems - 1)
	{
		currentNode = Tail; 
		Tail->prev->next = NULL;
		Tail = Tail->prev;
		delete currentNode;
		numItems--;
		return true;
	}
	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->next;
	}
	currentNode->prev->next = currentNode->next;
	currentNode->next->prev = currentNode->prev;
	if (currentNode->prev == NULL)
		Head = currentNode;
	if (currentNode)
	delete currentNode;
	numItems--;
}

size_t Single_Linked_List::find(const int& value)
{
	Node* currentNode = Head;
	for (int i = 0; i < numItems; i++)
	{
		if (currentNode->data == value) return i;
		if (currentNode->next == NULL) return numItems;
		currentNode = Head->next;
	}
}

//void Single_Linked_List::displayListContents()
//{
//	Node* temp = Head;
//	int i = 0;
//	while (temp != NULL) {
//		std::cout << "index " << i++ << ": " << temp->data << std::endl;
//		if (temp->next == NULL) break;
//		temp = temp->next;
//	}
//	std::cout << std::endl;
//}

#pragma once
#ifndef DNODE_H_
#define DNODE_H_
#define NULL
template <class Item_Type>

struct DNode 
{ 
	Item_Type data; 
	DNode* next;
	DNode* prev; 
};


#endif


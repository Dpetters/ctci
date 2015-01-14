#ifndef __LinkedList_h__
#define __LinkedList_h__

struct Node
{
	int data;
	Node* next;
};

class LinkedList {
public:
	LinkedList();
	~LinkedList();

	void display();
	void insert(int value);
	void createCycle();
	Node* head;
private:
	Node* tail;
};

#endif //__LinkedList_h__
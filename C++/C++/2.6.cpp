#include "LinkedList.h"
#include "2.6.h"
#include <iostream>
#include <string>

using namespace std;


Node* Question_2_6::findCycleBegin(Node* head)
{
	Node* fast = head;
	Node* slow = head;

	while (fast->next != NULL && fast->next->next != NULL && fast != slow)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	
	// No cycle
	if (fast != slow)
	{
		return NULL;
	}

	fast = head;

	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}

/*
I suppose the below implementation would be a bit too easy
Node* findCycleBegin(Node* head)
{
	if (head == NULL) return NULL;
	Node* current = head;
	while (current->visited != true)
	{
		current->visited = true;
		current = current->next;
	}
	return current;
}*/


int Question_2_6::run()
{
	LinkedList* list1 = new LinkedList();
	list1->insert(5);
	list1->insert(3);
	list1->insert(6);
	list1->insert(8);
	list1->insert(1);
	list1->insert(2);

	std::cout << "For the list: ";
	list1->display();
	std::cout << "A cycle begins at value: ";

	// create a cycle in the list
	list1->createCycle();

	Node* beginCycle = findCycleBegin(list1->head);
	std::cout << beginCycle->data << std::endl;

	string s;
	cin >> s;

	return 0;

}
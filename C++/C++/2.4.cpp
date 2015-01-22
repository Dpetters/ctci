#include "LinkedList.h"
#include "2.4.h"
#include <string>
#include <iostream>

using namespace std;

Node* Question_2_4::partition(Node* head, int x)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	Node* r = head;
	while (r->next != NULL)
	{
		if (r->next->data < x)
		{
			Node* tmp = r->next;
			r->next = r->next->next;
			tmp->next = head;
			head = tmp;
		}
		else
		{
			r = r->next;
		}
	}
	return head;
}

int Question_2_4::run()
{

	LinkedList* myList = new LinkedList();
	myList->insert(5);
	myList->insert(14);
	myList->insert(17);
	myList->insert(22);
	myList->insert(16);
	myList->insert(18);
	myList->insert(2);
	myList->insert(1);
	myList->insert(5);

	std::cout << "The original list is: ";
	myList->display();

	Node* newHead = partition(myList->head, 13);
	//delete myList;

	LinkedList* newList = new LinkedList();
	newList->head = newHead;

	std::cout << "The list partitioned around value 13 is: ";
	newList->display();
	delete newList;

	string s;
	cin >> s;

	return 0;
}
#include "2.3.h"
#include <iostream>
#include <string>

using namespace std;

int Question_2_3::run()
{
	LinkedList* myList = new LinkedList();
	myList->insert(5);
	myList->insert(7);
	myList->insert(12);
	myList->insert(7);
	myList->insert(16);
	myList->insert(16);
	myList->insert(25);
	myList->insert(11);
	myList->insert(5);

	cout << "The original list is: ";
	myList->display();

	removeNode(myList ->head->next->next->next);

	cout << "The modified list is: ";
	myList->display();
	delete myList;

	string s;
	cin >> s;
	return 0;
}

void Question_2_3::removeNode(Node* n)
{
	if (n == nullptr || n->next == nullptr)
	{
		return;
	}
	Node* tmp = n->next;
	n->data = n->next->data;
	n->next = n->next->next;
	delete(tmp);
}

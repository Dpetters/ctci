#include "LinkedList.h"
#include "2.2.h"
#include <iostream>
#include <string>

using namespace std;

Node* Question_2_2::getKthToLastNode(Node* head, int k)
{
	Node* current = head;
	int length = 0;
	while (current->next)
	{
		length++;
		current = current->next;
	}
	if (k > length)
	{
		return NULL;
	}
	current = head;
	for (int i = 0; i < length - k; i++)
	{
		current = current->next;
	}
	return current;
}

int Question_2_2::run()
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

	int k = 3;

	// change to removeDuplicates_2 to run that implementation
	Node* kthToLastNode = getKthToLastNode(myList->head, k);

	cout << "The " << k << "th to last node is: " << kthToLastNode->data << endl;
	delete myList;

	string s;
	cin >> s;
	return 0;
}
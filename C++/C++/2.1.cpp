#include <iostream>
#include "LinkedList.h"
#include <unordered_map>
#include <string>

using namespace std;

void removeDuplicates_1(Node* head) 
{
	if (head == NULL) 
	{
		return;
	}
	unordered_map<int, bool> map;
	Node* current = head;
	map[current->data] = 1;
	while (current->next) 
	{
		if (map[current->next->data] == 1) 
		{
			Node* temp = current->next;
			current->next = current->next->next;
			cout << "Duplicate found: " << temp->data << " removed" << endl;
			delete(temp);
		}
		else 
		{
			map[current->next->data] = 1;
			current = current->next;
		}
		
	}
}

int main()
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

	std::cout << "The original list is: ";
	myList->display();

	// change to removeDuplicates_2 to run that implementation
	removeDuplicates_1(myList->head);

	std::cout << "The list with duplicated removed is: ";
	myList->display();
	delete myList;

	string s;
	cin >> s;
	return 0;
}
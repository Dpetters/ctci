#include "LinkedList.h"
#include "2.5.h"
#include <string>
#include <iostream>

using namespace std;

Node* Question_2_5::sumLinks(Node* x, Node* y)
{
	LinkedList* result = new LinkedList();
	int sum, c = 0;
	while (x != NULL || y != NULL || c != 0)
	{
		sum = 0;
		if (x != NULL)
		{
			sum += x->data;
			x = x->next;
		}
		if (y != NULL)
		{
			sum += y->data;
			y = y->next;
		}
		sum += c;
		result->insert(sum % 10);
		c = sum / 10;
	}
	return result->head;
}

// helper function to display to list value normally
int listValue(Node* head)
{
	int value = 0;
	double digit = 0;
	Node* temp = head;

	// I did this implementation because I wanted to avoid O(n) space
	while (temp)
	{
		value += pow(10.0, digit) * temp->data;
		digit++;
		temp = temp->next;
	}

	return value;

}
int Question_2_5::run()
{
	LinkedList* list1 = new LinkedList();
	list1->insert(5);
	list1->insert(3);
	list1->insert(6);

	LinkedList* list2 = new LinkedList();
	list2->insert(2);
	list2->insert(1);
	list2->insert(6);

	std::cout << listValue(list1->head) << " + " << listValue(list2->head) << " = ";
	Node* sum = sumLinks(list1->head, list2->head);
	std::cout << listValue(sum) << std::endl;
	delete list1;
	delete list2;
	std::cout << std::endl;

	LinkedList* list3 = new LinkedList();
	list3->insert(7);
	list3->insert(4);
	list3->insert(2);
	list3->insert(8);
	list3->insert(9);

	LinkedList* list4 = new LinkedList();
	list4->insert(2);
	list4->insert(6);

	std::cout << listValue(list3->head) << " + " << listValue(list4->head) << " = ";
	sum = sumLinks(list3->head, list4->head);
	std::cout << listValue(sum) << std::endl;
	delete list3;
	delete list4;
	
	string s;
	cin >> s;
	/*
	LinkedList* list5 = new LinkedList();
	list5->insert(7);
	list5->insert(4);
	list5->insert(2);
	list5->insert(8);
	list5->insert(9);

	LinkedList* list6 = new LinkedList();
	list6->insert(2);
	list6->insert(6);

	std::cout << std::endl << "-- Now with lists that are originally in forward order --" << std::endl;
	list5->head = reverse(list5->head);
	list6->head = reverse(list6->head);
	std::cout << listValue(list5->head) << " + " << listValue(list6->head) << " = ";
	sumLinks(list5->head, list6->head);
	std::cout << listValue(list5->head) << std::endl;
	delete list5;
	delete list6;
	*/

	return 0;
}
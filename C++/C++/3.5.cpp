#include "3.5.h"
#include <iostream>
#include <string>

using namespace std;

void MyQueue::push(int d)
{
	pushStack.push(d);
}

int MyQueue::size()
{
	return pushStack.size() + popStack.size();
}

bool MyQueue::isEmpty()
{
	return size() == 0;
}

int MyQueue::pop()
{
	if (popStack.empty())
	{
		while (!pushStack.empty()) 
		{
			popStack.push(pushStack.top());
			pushStack.pop();
		}
	}
	int tmp = popStack.top();
	popStack.pop();
	return tmp;
}

int Question_3_5::run()
{
	MyQueue q;
	for (int i = 0; i < 10; i++)
	{
		q.push(i);
	}
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	for (int i = 10; i<20; i++)
	{
		q.push(i);
	}
	cout << q.pop() << endl;
	cout << q.pop() << endl;

	string s;
	cin >> s;
	return 0;
}
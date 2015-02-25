#ifndef __Question_3_5__
#define __Question_3_5__

#include <stack>

using namespace std;

class MyQueue
{
public:
	void push(int d);
	int pop();
	int size();
	bool isEmpty();
private:
	stack<int> pushStack, popStack;
};

class Question_3_5
{
public:
	int run();
};

#endif //__Question_3_5__
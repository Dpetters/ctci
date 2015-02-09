#ifndef __Question_3_4__
#define __Question_3_4__

#include <stack>

using namespace std;

class Question_3_4
{
public:
	int run();
	void towersOfHanoi(stack<int>& primary, stack<int>& buffer, stack<int>& destination, int n);
};

#endif
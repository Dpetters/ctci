#include "3.4.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int Question_3_4::run()
{
	stack<int> primary, buffer, destination;
	int n = 10;
	for (int i = n; i>0; i--)
		primary.push(i);
	towersOfHanoi(primary, buffer, destination, 10);
	while (!destination.empty())
	{
		cout << destination.top() << " ";
		destination.pop();
	}
	string s;
	cin >> s;
	return 0;
}

void Question_3_4::towersOfHanoi(stack<int>& primary, stack<int>& buffer, stack<int>& destination, int n)
{
	if (n == 0)
	{
		return;
	}
	towersOfHanoi(primary, destination, buffer, n - 1);
		
	destination.push(primary.top());
	primary.pop();
		
	towersOfHanoi(buffer, primary, destination, n - 1);
}
#include <stack>
#include <iostream>
#include <string>
#include "3.6.h"

using namespace std;

void Question_3_6::sortStack(stack<int> &s)
{
	int size = s.size();
	if (size == 0 || size == 1)
	{
		return;
	}
	stack<int> temp;

	int numLeftToSort = size;

	for (int i = numLeftToSort; i > 0; i--)
	{
		int max = s.top();
		s.pop();
		while (!s.empty())
		{
			int tmp = s.top();
			if (tmp > max)
			{
				temp.push(max);
				max = tmp;
			}
			else
			{
				temp.push(tmp);
			}
			s.pop();
		}
		for (int j = 0; j < i-1; j++)
		{
			int tmp = temp.top();
			temp.pop();
			s.push(tmp);
		}
		temp.push(max);
	}

	while (!temp.empty())
	{
		int tmp = temp.top();
		temp.pop();
		s.push(tmp);
	}
}

int Question_3_6::run()
{
	stack<int> my;
	int arr[] = { 6, 4, 8, 9, 10, 99, 7, 1, 0 };
	for (int i = 0; i<sizeof(arr) / sizeof(arr[0]); i++)
	{
		my.push(arr[i]);
	}
	sortStack(my);
	while (!my.empty())
	{
		cout << my.top() << '\n';
		my.pop();
	}

	string s;
	cin >> s;
	return 0;
}
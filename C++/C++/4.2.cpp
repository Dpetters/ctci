#define _CRT_SECURE_NO_WARNINGS 1 

#include "4.2.h"
#include <queue>
#include <string>
#include <iostream>

using namespace std;

bool Question_4_2::isRoute(int a, int b, bool graph[][MAX])
{
	bool visited[MAX];
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(a);
	visited[a] = true;
	int node;
	while (q.size() != 0)
	{
		node = q.front();
		q.pop();
		
		for (int i = 0; i < MAX; i++)
		{
			if (graph[node][i] && !visited[i])
			{
				if (b==i)
				{
					return true;
				}
				q.push(i);
				visited[i] = true;
			}
		}

	}
	return false;
}

int Question_4_2::run()
{
	freopen("4.2.in", "r", stdin);
	int n, m, u, v;
	bool dgraph[MAX][MAX] = { false };
	cin >> n >> m;
	for (int i = 0; i<m; i++)
	{
		cin >> u >> v;
		dgraph[u][v] = true;
	}
	cout << isRoute(0, 3, dgraph);
	
	string s;
	cin >> s;
	return 0;
}
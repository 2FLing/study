#include <iostream>
#include <vector>
#include "Queue.h"
using namespace std;
void dfs(vector<int>, vector<vector<int>>);
void dfs_ultities(vector<int>, vector<vector<int>>, vector<bool>&,int);
void made_adjacent(vector<vector<int>>&, int, int);
void bfs(vector<int>, vector<vector<int>>);
void visit_node(vector<bool>&visited, int);
int main()
{
	vector<int>nodes = { 1,2,3,4,5,6,7,8,9,10 };
	vector<vector<int>>adjacent(nodes.size());
	made_adjacent(adjacent, 1, 2);
	made_adjacent(adjacent, 1, 3);
	made_adjacent(adjacent, 2, 4);
	made_adjacent(adjacent, 2, 5);
	made_adjacent(adjacent, 3, 6);
	made_adjacent(adjacent, 3, 7);
	made_adjacent(adjacent, 4, 8);
	made_adjacent(adjacent, 5, 9);
	made_adjacent(adjacent, 5, 10);
	dfs(nodes, adjacent);
	bfs(nodes, adjacent);
	return 0;
}
void dfs(vector<int>nodes, vector<vector<int>>adjacent)
{
	vector<bool>visited(nodes.size());
	for (int i = 0; i < nodes.size(); i++)
	{
		if (!visited[nodes[i]-1])
		{
			dfs_ultities(nodes, adjacent, visited, i);
		}
	}
	cout << endl;
}
void dfs_ultities(vector<int>nodes, vector<vector<int>>adjacent, vector<bool>&visited,int i)
{
	if (!visited[nodes[i] - 1])
	{
		visit_node(visited, nodes[i]);
	}
	for (int j = 0; j < adjacent[nodes[i] - 1].size(); j++)
	{
		dfs_ultities(nodes, adjacent, visited, adjacent[i][j] - 1);
	}
}
void bfs(vector<int>nodes, vector<vector<int>>adjacent)
{
	vector<bool>visited(nodes.size());
	Queue q;
	for (int i = 0; i < nodes.size(); i++)
	{
		q.insert(nodes[i]);
	}
	while (!q.is_empty())
	{
		int current_node = q.pop();
		if (!visited[current_node - 1])
		{
			visit_node(visited, current_node);
			for (int i = 0; i < adjacent[current_node - 1].size(); i++)
				q.insert(adjacent[current_node - 1][i]);
		}
	}
	cout << endl;
}

void made_adjacent(vector<vector<int>>&adjacent, int i, int j)
{
	adjacent[i-1].push_back(j);
}
void visit_node(vector<bool>& visited, int node)
{
	if (!visited[node - 1])
	{
		cout << node << " ";
		visited[node - 1] = true;
	}
}
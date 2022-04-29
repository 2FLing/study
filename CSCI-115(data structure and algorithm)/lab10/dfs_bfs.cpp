#include <iostream>
#include <vector>
#include <string>
#include "queue.h"
using namespace std;
void dfs(vector<int>, vector<vector<int>>);
void dfs_ultities(vector<int>, vector<vector<int>>, vector<bool>&, int);
void made_adjacency(vector<vector<int>>&, int, int);
void bfs(vector<int>, vector<vector<int>>);
void visit_node(vector<bool>& visited, int);
vector<int> make_v(int);
void m_stoi(string, vector<int>&);
int main()
{
	vector<int> nodes, temp;
	vector<vector<int>> adjacency;
	string size, nums, choice; 
	while (choice != "n")
	{
		cout << "Enter the size of nodes: ";
		getline(cin, size);
		nodes = make_v(stoi(size));
		adjacency = vector<vector<int>>(stoi(size));
		for (int i = 0; i < stoi(size); i++)
		{
			cout << "Please enter the adjacencies for node " << i + 1 << " (seperate by space, enter 'n' for skip) : ";
			getline(cin, nums);
			if (nums != "n")
			{
				m_stoi(nums, temp);
				adjacency[i] = temp;
			}
		}
		cout << "For depth first travel, the result will be: " << endl;
		dfs(nodes, adjacency);
		cout << "For breadth first travel, the result will be: " << endl;
		bfs(nodes, adjacency);
		cout << "continue?(\'n\' for quit):";
		getline(cin, choice);
	}
	return 0;
}
void dfs(vector<int> nodes, vector<vector<int>> adjacency)
{
	vector<bool> visited(nodes.size());
	for (int i = 0; i < nodes.size(); i++)
	{
		if (!visited[nodes[i] - 1])
		{
			dfs_ultities(nodes, adjacency, visited, i);
		}
	}
	cout << endl;
}
void dfs_ultities(vector<int> nodes, vector<vector<int>> adjacency, vector<bool>& visited, int i)
{
	if (!visited[nodes[i] - 1])
	{
		visit_node(visited, nodes[i]);
	}
	for (int j = 0; j < adjacency[nodes[i] - 1].size(); j++)
	{
		if(!visited[adjacency[i][j] - 1])
			dfs_ultities(nodes, adjacency, visited, adjacency[i][j] - 1);
	}
}
void bfs(vector<int> nodes, vector<vector<int>> adjacency)
{
	vector<bool> visited(nodes.size());
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
			for (int i = 0; i < adjacency[current_node - 1].size(); i++)
				q.insert(adjacency[current_node - 1][i]);
		}
	}
	cout << endl;
}

void made_adjacency(vector<vector<int>>& adjacency, int i, int j)
{
	adjacency[i - 1].push_back(j);
}
void visit_node(vector<bool>& visited, int node)
{
	if (!visited[node - 1])
	{
		cout << node << " ";
		visited[node - 1] = true;
	}
}
vector<int> make_v(int size)
{
	vector<int> v;
	for (int i = 0; i < size; i++)
	{
		v.push_back(i + 1);
	}
	return v;
}
void m_stoi(string str, vector<int>& v)
{
	str.push_back(' ');
	string temp = "";
	v.clear();
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			v.push_back(stoi(temp));
			temp = "";
		}
		else
		{
			temp.push_back(str[i]);
		}
	}
}
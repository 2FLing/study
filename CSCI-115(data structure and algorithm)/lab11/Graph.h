#ifndef _GRAPH
#define _GRAPH
#include"Edge.h"
#include<string>
#include<iostream>
using namespace std;
class graph
{
public:
	vector<int>vetexes;
	vector<edge>edges;
	vector<vector<int>>adjacency;
	void inert_vetex(int);
	void insert_edge(edge);
	void inert_adjacency(int,vector<int>);
	bool exist_v(int);
	bool exist_e(pair<int,int>);
	int get_weight(int, int);
	int sum_weight();
};
bool graph::exist_e(pair<int,int> edge)
{
	for (auto ele : edges)
	{
		if (ele.vtx.first == edge.first && ele.vtx.second == edge.second)
			return true;
		else if (ele.vtx.first == edge.second && ele.vtx.second == edge.first)
			return true;
	}
	return false;
}
bool graph::exist_v(int vetex)
{
	for (auto ele : vetexes)
		if (ele == vetex)
			return true;
	return false;
}
void graph::inert_vetex(int vtx)
{
	if (!exist_v(vtx))
	{
		vetexes.push_back(vtx);
		if (adjacency.size() < vtx)
		{
			while (adjacency.size() != vtx)
			{
				adjacency.push_back({});
			}
		}
	}
}
void graph::insert_edge(edge edge)
{
	edges.push_back(edge);
}
void graph::inert_adjacency(int vertex,vector<int>adj)
{
	pair<int, int>temp;
	edge edge;
	string num;
	adjacency[vertex] = adj;
	for (int j = 0; j < adjacency[vertex].size(); j++)
	{
		temp.first = vertex + 1;
		temp.second = adjacency[vertex][j];
		if (!exist_v(temp.first) || !exist_v(temp.second))
		{
			cout << "There is no such vetex in the graph!" << endl;
			exit(1);
		}
		if (!exist_e(temp))
		{
			cout << "Please enter the weight between " << temp.first << " " << temp.second << ":";
			getline(cin, num);
			edge.vtx = temp;
			edge.weight = stoi(num);
			edges.push_back(edge);
		}
	}
}	
int graph::get_weight(int u, int v)
{
	for (auto ele : edges)
	{
		if ((ele.vtx.first == u && ele.vtx.second == v) || (ele.vtx.first == v && ele.vtx.second == u))
			return ele.weight;
	}
	return -1;
}
int graph::sum_weight()
{
	int sum = 0;
	for (auto ele : edges)
	{
		sum += ele.weight;
	}
	return sum;
}
#endif


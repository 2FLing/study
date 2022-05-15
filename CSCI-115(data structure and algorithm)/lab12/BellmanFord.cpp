#include<vector>
#include<string>
#include<limits>
#include<iostream>
using namespace std;
void bellmanFord(vector<vector<int>>, int,int, int);
void bellmanFord(vector<vector<int>>G, int e, int v, int s)
{
	vector<int>distance_list(v);
	for (int i = 0; i < v; i++)
	{
		distance_list[i] = INT_MAX;
	}
	distance_list[s] = 0;
	for (int i = 0; i < v - 1; i++)
	{
		for (int j = 0; j < e; j++)
		{
			int v1 = G[j][0], w = G[j][2], v2 = G[j][1];
			if (distance_list[v1] + w < distance_list[v2])
			{
				distance_list[v2] = distance_list[v1] + w;
			}
		}
	}
	for (int i = 0; i < e; i++)
	{
		int v1 = G[i][0], w = G[i][2], v2 = G[i][1];
		if (distance_list[v1] + w < distance_list[v2])
		{
			cout << "Graph contains negative weight cycle and do not print the shortest distance from the source to rest of the vertices." << endl;
		}
	}
	cout << "Vertex        Distance from source vertex" << endl;
	for (int i = 0; i < v; i++)
	{
		cout << i << "             " << distance_list[i] << endl;
	}
}
int main()
{
	int v = 3, e = 3, s = 0;
	vector<vector<int>>edges = { {0,1,2},{1,2,-1},{0,2,5} };
	bellmanFord(edges, e, v, s);
	return 0;
}
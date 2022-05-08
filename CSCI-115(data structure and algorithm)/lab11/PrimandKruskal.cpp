#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<limits.h>
#include"Graph.h"
using namespace std;
vector<int>parent;
int find(int);
void unite(int, int);
void kruskalMST(graph, int);
void printG(graph);
void prim_MST(graph, int);
vector<int> make_v(int);
void my_sort(vector<edge>&);
void m_stoi(string, vector<int>&);
int get_min(vector<int>&);
bool exist(int, vector<int>);
bool remove(vector<int>&, int);
//remove one element from vector
bool remove(vector<int>& v, int num)
{
	for (int i = 0; i < v.size(); i++)
	{
		//if found the element is in the array
		//swap it to the back and use vector.pop()
		//to remove it.
		if (v[i] == num)
		{
			swap(v[v.size() - 1], v[i]);
			v.pop_back();
			return true;
		}
	}
	return false;
}
//check whether an element is in an array
//return true if it is, otherwise not.
bool exist(int num, vector<int>v)
{
	for (auto ele : v)
	{
		if (ele == num)
			return true;
	}
	return false;
}
//find the index of the minimum element in the array
//after finishing searching, set the minimum element
// to be INT_MAX, that is the way to put rest of
// elements in front of the queue.
int get_min(vector<int>& key)
{
	int min = 0;
	for (int i = 1; i < key.size(); i++)
	{
		if (key[i] < key[min])
		{
			min = i;
		}
	}
	key[min] = INT_MAX;
	return min;
}
//sort the edges by its weight in ascending order
void my_sort(vector<edge>& edges)
{
	vector<edge>res;
	edge temp;
	int max = 0;
	for (int i = edges.size() - 1; i >= 0; i--)
	{
		max = 0;
		for (int j = 1; j <= i; j++)
		{
			if (edges[j].weight > edges[max].weight)
			{
				max = j;
			}
		}
		temp = edges[max];
		edges[max] = edges[i];
		edges[i] = temp;
	}
}
//convert a string into vector
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
// make a vector contains numbered in range from 1 to size.
vector<int> make_v(int size)
{
	vector<int> v;
	for (int i = 0; i < size; i++)
	{
		v.push_back(i + 1);
	}
	return v;
}
//print the graph by its adjacent of each vetex.
void printG(graph G)
{
	for (int i = 0; i < G.adjacency.size(); i++)
	{
		if (G.adjacency[i].size() != 0)
		{
			cout << "Adjacency on vetex " << i + 1 << ": ";
			for (auto vtx : G.adjacency[i])
			{
				cout << vtx << " ";
			}
			cout << endl;
		}
	}
	cout << "The cost of the tree is :" << G.sum_weight() << endl;
}
int find(int x)
{
	if (parent[x - 1] == x)
		return x;
	else
		return find(parent[x - 1]);
}
void unite(int v, int u)
{
	int temp = parent[find(v) - 1];
	parent[find(v) - 1] = find(u);
	for (int i = 0; i < parent.size(); i++)
	{
		if (parent[i] == temp)
			parent[i] = parent[find(v) - 1];
	}
}
void kruskalMST(graph G, int start_node)
{
	graph new_G;
	vector<edge>new_edge = G.edges;
	parent = vector<int>(G.vetexes.size());
	for (int i = 0; i < G.vetexes.size(); i++)
	{
		parent[i] = i + 1;
	}
	//sort the edge by ascending order
	my_sort(new_edge);
	for (int i = 0; i < new_edge.size(); i++)
	{
		//if the edge is not in the same tree with anther one, then they can join together to be a new tree
		//otherwise it will make a cycle.
		if (parent[new_edge[i].vtx.first - 1] != parent[new_edge[i].vtx.second - 1])
		{
			new_G.inert_vetex(new_edge[i].vtx.first);
			new_G.inert_vetex(new_edge[i].vtx.second);
			new_G.edges.push_back(new_edge[i]);
			new_G.adjacency[new_edge[i].vtx.first - 1].push_back(new_edge[i].vtx.second);
			new_G.adjacency[new_edge[i].vtx.second - 1].push_back(new_edge[i].vtx.first);
			unite(new_edge[i].vtx.first, new_edge[i].vtx.second);
			if (new_G.edges.size() == G.vetexes.size() - 1)
				break;
		}
	}
	printG(new_G);

}
void prim_MST(graph G, int start_node)
{
	vector<int>key(G.vetexes.size()), q, parent_list(G.vetexes.size());
	graph new_G;
	//set the key value to be inmax for every vetex except the first one
	//input every vetex in to a queue.
	//set the parent of each node to be itself.
	for (int i = 0; i < key.size(); i++)
	{
		key[i] = INT_MAX;
		parent_list[i] = i + 1;
		q.push_back(i + 1);
	}
	//set the key value of the first element to be 0.
	key[start_node - 1] = 0;
	//insert the first node into output graph.
	new_G.inert_vetex(start_node);
	//while the queue is not empty
	//first remove the vetex that already be process from queue.
	//then get the adjacency of the current vetex
	//for every vetex in the adjacency, if it is in the queue and the weight of the edge is
	//greater than its key value, then update its key value to the weight of the edge and
	//set its parent to be current vetex.
	while (!q.empty())
	{
		//the current vetex should be the one that makes the cost of the tree increse
		//with smallest amount.
		int current_node = get_min(key) + 1;
		remove(q, current_node);
		vector<int> adj = G.adjacency[current_node - 1];
		edge adj_edge;
		for (int i = 0; i < adj.size(); i++)
		{
			if (exist(adj[i], q) && G.get_weight(current_node, adj[i]) < key[current_node - 1])
			{
				key[adj[i] - 1] = G.get_weight(current_node, adj[i]);
				parent_list[adj[i] - 1] = current_node;
			}
		}
		//insert the current vetex into output graph
		if (current_node != start_node)
		{
			new_G.inert_vetex(current_node);
			new_G.adjacency[parent_list[current_node - 1] - 1].push_back(current_node);
			new_G.adjacency[current_node - 1].push_back(parent_list[current_node - 1]);
			adj_edge.vtx.first = parent_list[current_node - 1];
			adj_edge.vtx.second = current_node;
			adj_edge.weight = G.get_weight(parent_list[current_node - 1], current_node);
			new_G.edges.push_back(adj_edge);
		}
	}
	printG(new_G);
}
int main()
{

	string choice;
	while (choice != "n")
	{
		string size, nums;
		int start_node;
		graph G;
		vector<int>v;
		cout << "Enter the size of graph: ";
		getline(cin, size);
		v = make_v(stoi(size));
		for (auto ele : v)
		{
			G.inert_vetex(ele);
		}
		for (int i = 0; i < stoi(size); i++)
		{
			vector<int> temp;
			cout << "Please enter the adjacencies for node " << i + 1 << " (seperate by space, enter 'n' for skip) : ";
			getline(cin, nums);
			if (nums != "n")
			{
				m_stoi(nums, temp);
				G.inert_adjacency(i, temp);
			}
		}
		cout << "Please enter the starting node:";
		getline(cin, nums);
		start_node = stoi(nums);
		printG(G);
		cout << "The minimum spanning tree generated by Prim's Algorithm is: " << endl;
		prim_MST(G, start_node);
		cout << "The minimum spanning tree generated by Kruskal's Algorithm is: " << endl;
		kruskalMST(G, start_node);
		cout << "continue?(\'n\' for quit):";
		getline(cin, choice);
	}
	return 0;
}
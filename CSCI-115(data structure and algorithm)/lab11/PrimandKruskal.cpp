#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>edge;
vector<int>graph;
vector<int>parent_list;

int find(int,vector<int>&);
void union_nodes(int,int,vector<int>&);
void KruskalMST(vector<vector<int>>,int);
bool is_circle(vector<vector<int>>,int);
bool is_circle_helper(vector<vector<int>>,int,int);
void union_nodes(int u,int v,vector<int>&parent)
{
    int v1 = find(u,parent),v2 = find(v,parent);
    if (v1!=v2)
    {
        parent[v1-1] = v2;
    }
}
int find(int u,vector<int>&parent)
{
    if(parent[u-1]!=u)
        u = parent[u-1];
    return u;
}
void KruskalMST(vector<vector<int>>adjecent,int start_node)
{

}
bool is_circle_helper(vector<vector<int>>adjacent,int parent,int current_node)
{
    for(auto ele:adjacent[current_node-1])
    {
        if(ele == parent)
            return true;
    }
    return false;
}
bool is_circle(vector<vector<int>>adjacent,int current_node)
{
    for(auto node:adjacent[current_node-1])
    {
        if(is_circle_helper(adjacent,current_node,node));
            return true;
    }
    return false;
}
int main()
{
     vector<vector<int>>adjacent;
    graph = {1,2,3,4,5,6,7,8};
    adjacent = vector<vector<int>>(8);
    
    return 0;
}

//MingkuanPang
//group 3
#ifndef _HeapSortHeader_H
#define _HeapSortHeader_H
#include <iostream>
#include<vector>
#include<string>
#include<climits>
#include<math.h>
using namespace std;

class Heap
{
public:
   
    vector<int>Arr;
    int size;
    Heap();

    void printArray(vector<int> Arr, int n);

    //Max heap
    void modifyValMax(vector<int>& Arr, int n, int i, int val); //Modify value
    void insert_value_maxHeap(vector<int>& Arr, int val, int& n); //Adds value at the end of array and calls max_heapify
    void max_heapify(vector<int>& Arr, int i, int n); //Maintains the max heap property
    int extract_maximum(vector<int>& Arr, int& n); //Return the maximum element in heap and swap last element with first element
    void ascendingHeapSort(vector<int>& Arr, int n); //Prints the array in ascending order
    void buildMaxHeap(vector<int>& Arr, int n); //Heapifies entire list


    //Min Heap
    void modifyValMin(vector<int>& Arr, int n, int i, int val); //Modify value
    void insert_value_minHeap(vector<int>& Arr, int val, int& n); // Adds value at the end of array and calls min_heapify
    void min_heapify(vector<int>& Arr, int i,int n); //Maintains min heap property
    int extract_minimum(vector<int>& Arr); //Return the minimum element in heap and swap last element with first element
    void descendingHeapSort(vector<int>& Arr, int n); //Prints the array in descending order
    void buildMinHeap(vector<int>& Arr, int n); //Heapifies entire list


};

Heap::Heap()
{
}

void Heap::printArray(vector<int> Arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << Arr[i] << " ";
    cout << endl;
}
void Heap::modifyValMax(vector<int>& Arr, int n, int i, int val)
{
    Arr[i] = val;
    for (int t = i; t >= 0; t--)
    {
        int parent = t / 2;
        if (Arr[parent] < Arr[t] && t < n)
        {
            swap(Arr[parent], Arr[t]);
            t = parent+1;
        }
    }
}
void Heap::insert_value_maxHeap(vector<int>& Arr, int val, int& n)
{
    Arr.push_back(val);
    n++;
    max_heapify(Arr, (n/2-1), n);
}
void Heap::max_heapify(vector<int>& Arr, int i, int n)
{
    int root = Arr[i], large = i;
    int l = 2 * i+1, r = 2 * i + 2;
    if (l < n && Arr[l] > Arr[large])
        large = l;
    if (r < n && Arr[r] > Arr[large])
        large = r;
    if (large != i)
    {
        swap(Arr[i], Arr[large]);
        max_heapify(Arr, large, n);
    }

}
int Heap::extract_maximum(vector<int>& Arr, int& n)
{
    if (n >= 1)
    {
        buildMaxHeap(Arr, n);
        int res = Arr[0];
        Arr[0] = Arr[n - 1];
        n -= 1;
        max_heapify(Arr, 0, n);
        return res;
    }
    else
        throw "heap underflow";
}
void Heap::ascendingHeapSort(vector<int>& Arr, int n)
{
    buildMaxHeap(Arr, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(Arr[i],Arr[0]);
        max_heapify(Arr, 0, i);
    }
}
void Heap::buildMaxHeap(vector<int>& Arr, int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        max_heapify(Arr, i, n);
    }
    Heap::Arr = Arr;
    Heap::size = n;
}
void Heap::modifyValMin(vector<int>& Arr, int n, int i, int val)
{
    Arr[i] = val;
    int parent = i / 2;
    for (int t = i; t >= 0; t--)
    {
        if (Arr[parent] > Arr[t])
        {
            swap(Arr[parent], Arr[t]);
            t = parent;
        }
    }
}
void Heap::min_heapify(vector<int>& Arr, int i,int n)
{
    int parent = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && Arr[l] < Arr[parent])
    {
        parent = l;
    }
    if (r < n && Arr[r] < Arr[parent])
    {
        parent = r;
    }
    if (parent != i)
    {
        swap(Arr[parent], Arr[i]);
        min_heapify(Arr, parent,n);
    }
}
void Heap::insert_value_minHeap(vector<int>& Arr, int val, int& n)
{
    
    Arr.push_back(val);
    n++;
    int parent = (n-1) / 2;
    for (int i = n - 1; i >= 0; i--)
    {
        if (Arr[parent] > Arr[i])
        {
            swap(Arr[parent], Arr[i]);
            i = parent;
        }
    }
}
int Heap::extract_minimum(vector<int>& Arr)
{
    if (Arr.size() < 1)
        throw "heap underflow";
    else
    {
        buildMinHeap(Arr, Arr.size());
        int res = Arr[0];
        Heap::size--;
        swap(Arr[0], Arr[Heap::size]);
        return res;
    }

}
void Heap::descendingHeapSort(vector<int>& Arr, int n)
{
    buildMinHeap(Arr, n);
    for (int i = n-1; i >0; i--)
    {
        swap(Arr[i], Arr[0]);
        min_heapify(Arr, 0,i);
    }
}
void Heap::buildMinHeap(vector<int>& Arr, int n)
{
    Heap::size = n;
    for (int i = n/2; i >=0; i--)
    {
        min_heapify(Arr, i,n);
    }
    Heap::Arr = Arr;
}
#endif // !_HeapSortHeader_H
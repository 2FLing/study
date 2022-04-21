#include <iostream>
#include <time.h>
#include <random>
#include "Sorts.h"
using namespace std;
void print_v(vector<int>);
vector<int> in_order(int);
vector<int> reversed(int);
vector<int> random(int);
bool is_sorted(vector<int>);
void insertion_ordered_small_size();
void insertion_reversed_small_size();
void insertion_random_small_size();
void insertion_ordered_median_size();
void insertion_reversed_median_size();
void insertion_random_median_size();
void insertion_ordered_large_size();
void insertion_reversed_large_size();
void insertion_random_large_size();
void selection_ordered_small_size();
void selection_reversed_small_size();
void selection_random_small_size();
void selection_ordered_median_size();
void selection_reversed_median_size();
void selection_random_median_size();
void selection_ordered_large_size();
void selection_reversed_large_size();
void selection_random_large_size();
void bubble_ordered_small_size();
void bubble_reversed_small_size();
void bubble_random_small_size();
void bubble_ordered_median_size();
void bubble_reversed_median_size();
void bubble_random_median_size();
void bubble_ordered_large_size();
void bubble_reversed_large_size();
void bubble_random_large_size();
void merge_ordered_small_size();
void merge_reversed_small_size();
void merge_random_small_size();
void merge_ordered_median_size();
void merge_reversed_median_size();
void merge_random_median_size();
void merge_ordered_large_size();
void merge_reversed_large_size();
void merge_random_large_size();
void quick_ordered_small_size();
void quick_reversed_small_size();
void quick_random_small_size();
void quick_ordered_median_size();
void quick_reversed_median_size();
void quick_random_median_size();
void quick_ordered_large_size();
void quick_reversed_large_size();
void quick_random_large_size();
void heap_ordered_small_size();
void heap_reversed_small_size();
void heap_random_small_size();
void heap_ordered_median_size();
void heap_reversed_median_size();
void heap_random_median_size();
void heap_ordered_large_size();
void heap_reversed_large_size();
void heap_random_large_size();
void counting_ordered_small_size();
void counting_reversed_small_size();
void counting_random_small_size();
void counting_ordered_median_size();
void counting_reversed_median_size();
void counting_random_median_size();
void counting_ordered_large_size();
void counting_reversed_large_size();
void counting_random_large_size();
void radix_ordered_small_size();
void radix_reversed_small_size();
void radix_random_small_size();
void radix_ordered_median_size();
void radix_reversed_median_size();
void radix_random_median_size();
void radix_ordered_large_size();
void radix_reversed_large_size();
void radix_random_large_size();
int main()
{
    
    return 0;
}

vector<int> in_order(int size)
{
    vector<int> v;
    for (int i = 0; i < size; i++)
        v.push_back(i);
    return v;
}
vector<int> reversed(int size)
{
    vector<int> v;
    for (int i = size - 1; i >= 0; i--)
        v.push_back(i);
    return v;
}
vector<int> random(int size)
{
    vector<int> v;
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++)
    {
        int num = rand() % size;
        v.push_back(num);
    }
    return v;
}
void print_v(vector<int> v)
{
    for (auto ele : v)
    {
        cout << ele << " ";
    }
    cout << endl;
}
bool is_sorted(vector<int> v)
{
    bool sorted = true;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i + 1] < v[i])
        sorted = false;
    }
    return sorted;
}
void insertion_ordered_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 10000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.insertion(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void insertion_reversed_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 10000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.insertion(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void insertion_random_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 10000;
    float start, end;
    v = random(size);
    start = clock();
    sort.insertion(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void insertion_ordered_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 20000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.insertion(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void insertion_reversed_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 20000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.insertion(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void insertion_random_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 20000;
    float start, end;
    v = random(size);
    start = clock();
    sort.insertion(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void insertion_ordered_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.insertion(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void insertion_reversed_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.insertion(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void insertion_random_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = random(size);
    start = clock();
    sort.insertion(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void selection_ordered_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 10000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.selection_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << " to solve an order vector with size of " << size << "." << endl;
}
void selection_reversed_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 10000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.selection_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void selection_random_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 10000;
    float start, end;
    v = random(size);
    start = clock();
    sort.selection_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void selection_ordered_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 20000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.selection_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << " to solve an order vector with size of " << size << "." << endl;
}
void selection_reversed_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 20000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.selection_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void selection_random_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 20000;
    float start, end;
    v = random(size);
    start = clock();
    sort.selection_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void selection_ordered_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.selection_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << " to solve an order vector with size of " << size << "." << endl;
}
void selection_reversed_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.selection_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void selection_random_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = random(size);
    start = clock();
    sort.selection_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void bubble_ordered_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 10000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.bubble_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void bubble_reversed_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 10000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.bubble_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void bubble_random_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 10000;
    float start, end;
    v = random(size);
    start = clock();
    sort.bubble_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void bubble_ordered_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 20000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.bubble_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void bubble_reversed_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 20000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.bubble_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void bubble_random_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 20000;
    float start, end;
    v = random(size);
    start = clock();
    sort.bubble_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void bubble_ordered_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.bubble_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void bubble_reversed_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.bubble_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void bubble_random_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = random(size);
    start = clock();
    sort.bubble_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void merge_ordered_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.merge_sort(v, 0, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void merge_reversed_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.merge_sort(v, 0, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void merge_random_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = random(size);
    start = clock();
    sort.merge_sort(v, 0, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void merge_ordered_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 60000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.merge_sort(v, 0, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void merge_reversed_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 60000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.merge_sort(v, 0, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void merge_random_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 60000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.merge_sort(v, 0, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void merge_ordered_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 90000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.merge_sort(v, 0, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void merge_reversed_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 90000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.merge_sort(v, 0, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void merge_random_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 90000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.merge_sort(v, 0, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void quick_ordered_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.quick_sort(v, 0, v.size() - 1);
    end = clock();
    if (is_sorted(v))
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void quick_reversed_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.quick_sort(v, 0, v.size() - 1);
    end = clock();
    if (is_sorted(v))
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void quick_random_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = random(size);
    start = clock();
    sort.quick_sort(v, 0, v.size() - 1);
    end = clock();
    if (is_sorted(v))
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void quick_ordered_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 60000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.quick_sort(v, 0, v.size() - 1);
    end = clock();
    if (is_sorted(v))
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void quick_reversed_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 60000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.quick_sort(v, 0, v.size() - 1);
    end = clock();
    if (is_sorted(v))
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void quick_random_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 60000;
    float start, end;
    v = random(size);
    start = clock();
    sort.quick_sort(v, 0, v.size() - 1);
    end = clock();
    if (is_sorted(v))
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void quick_ordered_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 90000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.quick_sort(v, 0, v.size() - 1);
    end = clock();
    if (is_sorted(v))
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void quick_reversed_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 90000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.quick_sort(v, 0, v.size() - 1);
    end = clock();
    if (is_sorted(v))
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void quick_random_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 90000;
    float start, end;
    v = random(size);
    start = clock();
    sort.quick_sort(v, 0, v.size() - 1);
    end = clock();
    if (is_sorted(v))
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void heap_ordered_small_size()
{
    Heap hp;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = in_order(size);
    start = clock();
    hp.ascendingHeapSort(v, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void heap_reversed_small_size()
{
    Heap hp;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = reversed(size);
    start = clock();
    hp.ascendingHeapSort(v, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void heap_random_small_size()
{
    Heap hp;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = random(size);
    start = clock();
    hp.ascendingHeapSort(v, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void heap_ordered_median_size()
{
    Heap hp;
    vector<int> v;
    int size = 60000;
    float start, end;
    v = in_order(size);
    start = clock();
    hp.ascendingHeapSort(v, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void heap_reversed_median_size()
{
    Heap hp;
    vector<int> v;
    int size = 60000;
    float start, end;
    v = reversed(size);
    start = clock();
    hp.ascendingHeapSort(v, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void heap_random_median_size()
{
    Heap hp;
    vector<int> v;
    int size = 60000;
    float start, end;
    v = random(size);
    start = clock();
    hp.ascendingHeapSort(v, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void heap_ordered_large_size()
{
    Heap hp;
    vector<int> v;
    int size = 90000;
    float start, end;
    v = in_order(size);
    start = clock();
    hp.ascendingHeapSort(v, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void heap_reversed_large_size()
{
    Heap hp;
    vector<int> v;
    int size = 90000;
    float start, end;
    v = reversed(size);
    start = clock();
    hp.ascendingHeapSort(v, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void heap_random_large_size()
{
    Heap hp;
    vector<int> v;
    int size = 90000;
    float start, end;
    v = random(size);
    start = clock();
    hp.ascendingHeapSort(v, v.size());
    end = clock();
    if (is_sorted(v))
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void counting_ordered_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.counting_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void counting_reversed_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.counting_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void counting_random_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = random(size);
    start = clock();
    sort.counting_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void counting_ordered_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 60000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.counting_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void counting_reversed_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 60000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.counting_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void counting_random_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 60000;
    float start, end;
    v = random(size);
    start = clock();
    sort.counting_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void counting_ordered_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 90000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.counting_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void counting_reversed_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 90000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.counting_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void counting_random_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 90000;
    float start, end;
    v = random(size);
    start = clock();
    sort.counting_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void radix_ordered_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.radix_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void radix_reversed_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.radix_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void radix_random_small_size()
{
    Sorts sort;
    vector<int> v;
    int size = 30000;
    float start, end;
    v = random(size);
    start = clock();
    sort.radix_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void radix_ordered_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 60000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.radix_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void radix_reversed_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 60000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.radix_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void radix_random_median_size()
{
    Sorts sort;
    vector<int> v;
    int size = 60000;
    float start, end;
    v = random(size);
    start = clock();
    sort.radix_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
void radix_ordered_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 90000;
    float start, end;
    v = in_order(size);
    start = clock();
    sort.radix_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << " to solve an ordered vector with size of " << size << "." << endl;
}
void radix_reversed_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 90000;
    float start, end;
    v = reversed(size);
    start = clock();
    sort.radix_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << " to solve a reversed vector with size of " << size << "." << endl;
}
void radix_random_large_size()
{
    Sorts sort;
    vector<int> v;
    int size = 90000;
    float start, end;
    v = random(size);
    start = clock();
    sort.radix_sort(v);
    end = clock();
    if (is_sorted(v))
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << " to solve a random vector with size of " << size << "." << endl;
}
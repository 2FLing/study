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
//produces an ordered array that from 0 to size-1.
vector<int> in_order(int size)
{
    vector<int> v;
    for (int i = 0; i < size; i++)
        v.push_back(i);
    return v;
}
//produces an array from 0 to size-1 but in reversed order.
vector<int> reversed(int size)
{
    vector<int> v;
    for (int i = size - 1; i >= 0; i--)
        v.push_back(i);
    return v;
}
//produces an array in random order in range from 0 to size-1
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
//prints the content in the array
void print_v(vector<int> v)
{
    for (auto ele : v)
    {
        cout << ele << " ";
    }
    cout << endl;
}
//determind if an array is sorted
bool is_sorted(vector<int> v)
{
    bool sorted = true;
    //travel through the array if found the next number is smaller than the current number
    //then the array is unsorted.
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i + 1] < v[i])
        {
            sorted = false;
            break;
        }
    }
    return sorted;
}
//test insertion sort with size of 10000 ordered array
//in range from 0 to 9999
//if insertion sort sorted the array successfully then print out
// the time that took insertion sort to sort the array.
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
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test insertion sort with size of 10000 reversed array
//in range from 0 to 9999
//if insertion sort sorted the array successfully then print out
// the time that took insertion sort to sort the array.
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
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test insertion sort with size of 10000 in random order array
//in range from 0 to 9999
//if insertion sort sorted the array successfully then print out
// the time that took insertion sort to sort the array.
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
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test insertion sort with size of 20000 ordered array
//in range from 0 to 19999
//if insertion sort sorted the array successfully then print out
// the time that took insertion sort to sort the array.
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
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test insertion sort with size of 20000 reversed array
//in range from 0 to 19999
//if insertion sort sorted the array successfully then print out
// the time that took insertion sort to sort the array.
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
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test insertion sort with size of 20000 random order array
//in range from 0 to 19999
//if insertion sort sorted the array successfully then print out
// the time that took insertion sort to sort the array.
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
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test insertion sort with size of 30000 ordered array
//in range from 0 to 29999
//if insertion sort sorted the array successfully then print out
// the time that took insertion sort to sort the array.
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
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test insertion sort with size of 30000 reversed array
//in range from 0 to 29999
//if insertion sort sorted the array successfully then print out
// the time that took insertion sort to sort the array.
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
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test insertion sort with size of 30000 random order array
//in range from 0 to 29999
//if insertion sort sorted the array successfully then print out
// the time that took insertion sort to sort the array.
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
        cout << "It takes insertion sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test selection sort with size of 10000 ordered array
//in range from 0 to 9999
//if selection sort sorted the array successfully then print out
// the time that took selection sort to sort the array.
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
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an order vector with size of " << size << "." << endl;
}
//test selection sort with size of 10000 reversed array
//in range from 0 to 9999
//if selection sort sorted the array successfully then print out
// the time that took selection sort to sort the array.
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
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test selection sort with size of 10000 random order array
//in range from 0 to 9999
//if selection sort sorted the array successfully then print out
// the time that took selection sort to sort the array.
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
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test selection sort with size of 20000 ordered array
//in range from 0 to 19999
//if selection sort sorted the array successfully then print out
// the time that took selection sort to sort the array.
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
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an order vector with size of " << size << "." << endl;
}
//test selection sort with size of 20000 reversed array
//in range from 0 to 19999
//if selection sort sorted the array successfully then print out
// the time that took selection sort to sort the array.
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
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test selection sort with size of 20000 random order array
//in range from 0 to 19999
//if selection sort sorted the array successfully then print out
// the time that took selection sort to sort the array.
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
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test selection sort with size of 30000 ordered array
//in range from 0 to 29999
//if selection sort sorted the array successfully then print out
// the time that took selection sort to sort the array.
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
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an order vector with size of " << size << "." << endl;
}
//test selection sort with size of 30000 reversed array
//in range from 0 to 29999
//if selection sort sorted the array successfully then print out
// the time that took selection sort to sort the array.
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
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test selection sort with size of 30000 random order array
//in range from 0 to 29999
//if selection sort sorted the array successfully then print out
// the time that took selection sort to sort the array.
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
        cout << "It takes selection sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test bubble sort with size of 10000 ordered array
//in range from 0 to 9999
//if bubble sort sorted the array successfully then print out
// the time that took bubble sort to sort the array.
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
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test bubble sort with size of 10000 reversed array
//in range from 0 to 9999
//if bubble sort sorted the array successfully then print out
// the time that took bubble sort to sort the array.
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
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test bubble sort with size of 10000 random order array
//in range from 0 to 9999
//if bubble sort sorted the array successfully then print out
// the time that took bubble sort to sort the array.
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
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test bubble sort with size of 20000 ordered array
//in range from 0 to 19999
//if bubble sort sorted the array successfully then print out
// the time that took bubble sort to sort the array.
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
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test bubble sort with size of 20000 reversed array
//in range from 0 to 19999
//if bubble sort sorted the array successfully then print out
// the time that took bubble sort to sort the array.
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
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test bubble sort with size of 20000 random order array
//in range from 0 to 19999
//if bubble sort sorted the array successfully then print out
// the time that took bubble sort to sort the array.
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
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test bubble sort with size of 30000 ordered array
//in range from 0 to 29999
//if bubble sort sorted the array successfully then print out
// the time that took bubble sort to sort the array.
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
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test bubble sort with size of 10000 reversed array
//in range from 0 to 29999
//if bubble sort sorted the array successfully then print out
// the time that took bubble sort to sort the array.
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
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test bubble sort with size of 30000 random order array
//in range from 0 to 29999
//if bubble sort sorted the array successfully then print out
// the time that took bubble sort to sort the array.
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
        cout << "It takes bubble sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test merge sort with size of 30000 ordered array
//in range from 0 to 29999
//if merge sort sorted the array successfully then print out
// the time that took merge sort to sort the array.
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
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test merge sort with size of 30000 reversed array
//in range from 0 to 29999
//if merge sort sorted the array successfully then print out
// the time that took merge sort to sort the array.
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
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test merge sort with size of 30000 random order array
//in range from 0 to 29999
//if merge sort sorted the array successfully then print out
// the time that took merge sort to sort the array.
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
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test merge sort with size of 60000 ordered array
//in range from 0 to 59999
//if merge sort sorted the array successfully then print out
// the time that took merge sort to sort the array.
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
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test merge sort with size of 30000 reversed array
//in range from 0 to 59999
//if merge sort sorted the array successfully then print out
// the time that took merge sort to sort the array.
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
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test merge sort with size of 60000 random order array
//in range from 0 to 59999
//if merge sort sorted the array successfully then print out
// the time that took merge sort to sort the array.
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
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test merge sort with size of 90000 ordered array
//in range from 0 to 89999
//if merge sort sorted the array successfully then print out
// the time that took merge sort to sort the array.
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
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test merge sort with size of 30000 reversed array
//in range from 0 to 89999
//if merge sort sorted the array successfully then print out
// the time that took merge sort to sort the array.
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
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test merge sort with size of 90000 random order array
//in range from 0 to 89999
//if merge sort sorted the array successfully then print out
// the time that took merge sort to sort the array.
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
        cout << "It takes merge sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test quick sort with size of 30000 ordered array
//in range from 0 to 29999
//if quick sort sorted the array successfully then print out
// the time that took quick sort to sort the array.
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
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test quick sort with size of 30000 reversed array
//in range from 0 to 29999
//if quick sort sorted the array successfully then print out
// the time that took quick sort to sort the array.
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
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test quick sort with size of 30000 random order array
//in range from 0 to 29999
//if quick sort sorted the array successfully then print out
// the time that took quick sort to sort the array.
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
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test quick sort with size of 60000 ordered array
//in range from 0 to 59999
//if quick sort sorted the array successfully then print out
// the time that took quick sort to sort the array.
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
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test quick sort with size of 60000 reversed array
//in range from 0 to 59999
//if quick sort sorted the array successfully then print out
// the time that took quick sort to sort the array.
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
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test quick sort with size of 60000 random order array
//in range from 0 to 59999
//if quick sort sorted the array successfully then print out
// the time that took quick sort to sort the array.
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
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test quick sort with size of 90000 ordered array
//in range from 0 to 89999
//if quick sort sorted the array successfully then print out
// the time that took quick sort to sort the array.
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
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test quick sort with size of 90000 reversed array
//in range from 0 to 89999
//if quick sort sorted the array successfully then print out
// the time that took quick sort to sort the array.
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
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test quick sort with size of 90000 random order array
//in range from 0 to 89999
//if quick sort sorted the array successfully then print out
// the time that took quick sort to sort the array.
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
        cout << "It takes quick sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test heap sort with size of 30000 ordered array
//in range from 0 to 29999
//if heap sort sorted the array successfully then print out
// the time that took heap sort to sort the array.
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
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test heap sort with size of 30000 reversed array
//in range from 0 to 29999
//if heap sort sorted the array successfully then print out
// the time that took heap sort to sort the array.
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
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test heap sort with size of 30000 random order array
//in range from 0 to 29999
//if heap sort sorted the array successfully then print out
// the time that took heap sort to sort the array.
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
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test heap sort with size of 60000 ordered array
//in range from 0 to 59999
//if heap sort sorted the array successfully then print out
// the time that took heap sort to sort the array.
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
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test heap sort with size of 60000 reversed array
//in range from 0 to 59999
//if heap sort sorted the array successfully then print out
// the time that took heap sort to sort the array.
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
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test heap sort with size of 60000 random order array
//in range from 0 to 59999
//if heap sort sorted the array successfully then print out
// the time that took heap sort to sort the array.
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
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test heap sort with size of 90000 ordered array
//in range from 0 to 89999
//if heap sort sorted the array successfully then print out
// the time that took heap sort to sort the array.
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
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test heap sort with size of 90000 reversed array
//in range from 0 to 89999
//if heap sort sorted the array successfully then print out
// the time that took heap sort to sort the array.
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
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test heap sort with size of 90000 random order array
//in range from 0 to 89999
//if heap sort sorted the array successfully then print out
// the time that took heap sort to sort the array.
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
        cout << "It takes heap sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test counting sort with size of 30000 ordered array
//in range from 0 to 29999
//if counting sort sorted the array successfully then print out
// the time that took counting sort to sort the array.
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
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test counting sort with size of 30000 reversed array
//in range from 0 to 29999
//if counting sort sorted the array successfully then print out
// the time that took counting sort to sort the array.
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
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test counting sort with size of 30000 random order array
//in range from 0 to 29999
//if counting sort sorted the array successfully then print out
// the time that took counting sort to sort the array.
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
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test counting sort with size of 60000 ordered array
//in range from 0 to 59999
//if counting sort sorted the array successfully then print out
// the time that took counting sort to sort the array.
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
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test counting sort with size of 60000 reversed array
//in range from 0 to 59999
//if counting sort sorted the array successfully then print out
// the time that took counting sort to sort the array.
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
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test counting sort with size of 60000 random order array
//in range from 0 to 59999
//if counting sort sorted the array successfully then print out
// the time that took counting sort to sort the array.
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
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test counting sort with size of 90000 ordered array
//in range from 0 to 89999
//if counting sort sorted the array successfully then print out
// the time that took counting sort to sort the array.
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
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test counting sort with size of 90000 reversed array
//in range from 0 to 89999
//if counting sort sorted the array successfully then print out
// the time that took counting sort to sort the array.
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
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test counting sort with size of 90000 random order array
//in range from 0 to 89999
//if counting sort sorted the array successfully then print out
// the time that took counting sort to sort the array.
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
        cout << "It takes counting sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test radix sort with size of 30000 ordered array
//in range from 0 to 29999
//if radix sort sorted the array successfully then print out
// the time that took radix sort to sort the array.
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
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test radix sort with size of 30000 reversed array
//in range from 0 to 29999
//if radix sort sorted the array successfully then print out
// the time that took radix sort to sort the array.
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
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test radix sort with size of 30000 random order array
//in range from 0 to 29999
//if radix sort sorted the array successfully then print out
// the time that took radix sort to sort the array.
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
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test radix sort with size of 60000 ordered array
//in range from 0 to 59999
//if radix sort sorted the array successfully then print out
// the time that took radix sort to sort the array.
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
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test radix sort with size of 60000 reversed array
//in range from 0 to 59999
//if radix sort sorted the array successfully then print out
// the time that took radix sort to sort the array.
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
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test radix sort with size of 60000 random order array
//in range from 0 to 59999
//if radix sort sorted the array successfully then print out
// the time that took radix sort to sort the array.
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
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
//test radix sort with size of 90000 ordered array
//in range from 0 to 89999
//if radix sort sorted the array successfully then print out
// the time that took radix sort to sort the array.
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
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << "s to solve an ordered vector with size of " << size << "." << endl;
}
//test radix sort with size of 90000 reversed array
//in range from 0 to 89999
//if radix sort sorted the array successfully then print out
// the time that took radix sort to sort the array.
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
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a reversed vector with size of " << size << "." << endl;
}
//test radix sort with size of 90000 random order array
//in range from 0 to 89999
//if radix sort sorted the array successfully then print out
// the time that took radix sort to sort the array.
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
        cout << "It takes radix sort " << (end - start) / CLOCKS_PER_SEC << "s to solve a random vector with size of " << size << "." << endl;
}
int main()
{
    quick_reversed_large_size();
    return 0;
}
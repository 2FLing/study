There are three functions that can produce three different orders
of array with size of n (n is the parameter of the function).

    vector<int> in_order(int n);
    vector<int> reversed(int n);
    vector<int> random(int n);

in_order produces an ordered array from 0...n-1.
reversed produces a reversed array from 0...n-1.
random produces an array in the random order in the range of 0...n-1, and numbers in the array is repeatable;

is_sorted is a function that receive an array as its parameter and it
can determine if the array is sorted. It returns true if the array is sorted, otherwise false.

bool is_sorted(vector<int> array);

We have three different size and three different types of orders data set for each algorithm. 
For Insertion Sort, Selection Sort, and Bubble sort, the small, median large size will be:
10000, 20000, 30000.
For Merge Sort, Quick Sort, Heapsort, Counting Sort, and Radix Sort, the small, median, large size will be:
30000, 60000, 90000.

Those functions that testing the algorithm are named in this format:

    algorithm name + order of data set + size

For example, the function for testing the quick sort with large size of data set in reversed order is:

    quick_reversed_large_size();

In the end of the testing funcion, if the algorithm sorted the array successfully
(inside the testing function, the result will be passed to is_sorted() to test if the array has been sorted),
then it will print out the information about the name of the algorithm, how long it took the algorithm to sort and
the order and the size of the data set.

For example, the output of the quick_reversed_large_size() will be:

    It takes quick sort 0.061s to solve a reversed vector with size of 90000.


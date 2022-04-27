As the puerpose of this program is to determind whether or not there exist
two numbers in the array that whose sum is exactly a provided integer.
The funtion takes two parameters, one is the vector, and another is the integer.

    bool two_sum(vector<int> Array, int num);
    bool two_sum_evolve(vector<int>Array, int num);

It returns true if there two numbers in the array that whose sum is exactly the parameter "num".
Otherwise, it returns false.

For running those function, you will need to pass one array and one integer, for example:

Example 1:

    two_sum({1,3,3,6,9},6)
    two_sum_evolve({1,3,3,6,9},6)
output: true, because in the array [1,3,3,6,9], array[1] + array[2] = 6.

Example 2:

    two_sum({1,2,3,6,9},6)
    two_sum_evolve({1,2,3,6,9},6)
output: false, because there is not two numbers in the array [1,2,3,6,9] that whose sum is 6.





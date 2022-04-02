// I executed my program on cygwin terminal
// Before execution, you have to convert the cpp file
// to exe by using g++ CSci114_P3.cpp -o anyname
// then you will see a anyname.exe in the same folder
// when you run the exe program you will need the
// size of those two matrixs. For example, if 
// size of matrix A is 4 * 5, and matrix B is 5 * 6
// for running the exe file, you have to put
// ./anyname 4 5 6 (4 5 is the size of matrix A and 5 6 is the size of matrix B)
// Then you should see the production of those two matrixs.


// If the size you entered is larger than the size of matrix in the txt file,
// it will not do the calculation and it will prompt the size you entered is too large instead.
#include<iostream>
#include<stdio.h>
#include<vector>
#include<thread>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;
void product_rc(vector<vector<int>>&, vector<int>, vector<int>, int r, int c);//calculates the product of one row of matrix A and one column of matrix B and put the product into nums_in_matrix
vector<vector<int>> create_matrix(string file_name,int, int); //create a matrix by reading a seire numbers from the file.
vector<vector<int>> make_matrix(vector<int>, int, int);//make a vector to be a n*m matrix
vector<int>read_nums_from_file(string file_name, int, int); //read numbers from a txt file and insert those numbers into a vector,and return the vector as a result.
void string_to_int(vector<int>&, string);// convert a string of numbers to int and put them into a vector
void print_matrix(vector<vector<int>>);// print out the vector
void read_arguments(char**, int,int&,int&,int&);//read the arguments in the main function and assigns them to M N K.
int main(int argc, char** argv)
{
    int M,N, K;
    read_arguments(argv, argc, M, N, K);
    vector<int>column(K,0);
    vector<vector<int>>matrix_A, matrix_B,matrix_C(M,column);
    vector<thread>thrds;
    string matrix_A_file = "A.txt", matrix_B_file = "B.txt";
    matrix_A = create_matrix(matrix_A_file, M, N);
    matrix_B = create_matrix(matrix_B_file, N, K);
    for (int i = 0; i <M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            vector<int>column;
            for (int l = 0; l < N; l++)
            {
                column.push_back(matrix_B[l][j]);
            }
            thrds.push_back(thread(ref(product_rc), ref(matrix_C), matrix_A[i], column,i,j)); //matrix_A[i] is actually row.
        }
    }
    for (int i = 0; i < thrds.size(); i++)
        thrds[i].join();
    print_matrix(matrix_C);
    return 0;
}
//@para matrix that is the vector that for storing the result matrix
//@para row that represents the row of matrix A
//@para column that represents the column of matrix B
//@para r represent the current rth row that in the production.
//#para c represnets the current  cth column that in the produciton
void product_rc(vector<vector<int>>&matrix,vector<int>row, vector<int>column,int r,int c)
{
    int sum = 0;
    for (int i=0,j=0;i<row.size(),j<column.size();i++,j++)
    {
        sum += row[i] * column[j];
    }
    matrix[r][c]=sum;
}
//it reads a matrix that written in a txt file and put it into a vector.
//@para file_name the name of the txt file that contains the matrix
//@para column the column of the matrix that stored in the txt file
//@para row the row of the matix that sotred in the txt file
vector<vector<int>> create_matrix(string file_name,int column,int row)
{
    vector<int>nums_in_matrix=read_nums_from_file(file_name,column,row);
    return make_matrix(nums_in_matrix, column, row);
}
//@para nums_in_matrix it is a vecotor of vectors used for store the matrix
//@para columns will be the number of columns of the matrix
//@para rows will be the number of rows of the matrix
vector<vector<int>> make_matrix(vector<int>nums_in_matrix, int columns, int rows)
{
    vector<vector<int>>matrix;
    int index = 0;
    for (int i = 0; i < columns; i++)
    {
        vector<int>row;
        int count = 0;
        while (count < rows && index < nums_in_matrix.size())
        {
            row.push_back(nums_in_matrix[index]);
            index++;
            count++;
        }
        matrix.push_back(row);
    }
    return matrix;
}
//read a matrix from a txt file
//@para file_name the name of the file
//@para columns the number of column of the matrix
//@para rows the number of the rows of the matrix
vector<int> read_nums_from_file(string file_name, int columns, int rows)
{
    ifstream matrix_file;
    matrix_file.open(file_name, ios::in);
    vector<int>nums_in_file;
    if (matrix_file.is_open())
    {
        string str;
        while (getline(matrix_file, str,char(13)))
        {
            string_to_int(nums_in_file, str);
        }
        matrix_file.close();
        if (nums_in_file.size() < columns * rows)
        {
            cout << "The matrix size is smaller than " << columns << " * " << rows << endl;
            exit(1);
        }
        else
        {
            return nums_in_file;
        }
    }
    else
    {
        cout << file_name << " does not exist!" << endl;
        exit(1);
    }
}
//transfer a string in integer
//@para nums vector that used for storing the nums
//@para str is the string that waiting for be transferred
void string_to_int(vector<int>& nums, string str)
{
    int start = 0, end = str.size() - 1;
    string tmp="";
    while (str[start] == ' ' || str[start] == '\n')
    {
        start++;
    }
    while (str[end] == ' ' || str[end] == '\n')
    {
        end--;
    }
    str.push_back(' ');
    for (int i = start; i <= end+1; i++)
    {
        if (str[i] != ' ')
        {
            tmp.push_back(str[i]);
        }
        else
        {
            nums.push_back(stoi(tmp));
            tmp = "";
        }
    }
}
//prints the matrix in the format of the matrix
//@para matrix is the vector that stores the matrix
void print_matrix(vector<vector<int>>matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (auto ele : matrix[i])
        {
            cout <<ele<< " ";
        }
        cout << endl;
    }
}
//reads the parameters that passed to the main function
void read_arguments(char** argv, int arg,int& M,int& N,int& K)
{
    string nums = "";
    vector<int>args;
    for (int i = 1; i < arg; i++)
    {
        argv++;
        nums += *argv;
        nums += " ";
    }
    string_to_int(args, nums);
    M = args[0];
    N = args[1];
    K = args[2];
}
#include<stdio.h>
#include<iostream>
#include<unistd.h>
#include<wait.h>
using namespace std;
int main()
{
    int val =5;
    int pid;
    if(pid = fork())
    {
        wait(&pid);
    }
    else
    {
        exit(val);
    }
    val++;
    cout<<val<<endl;
    return val;
}
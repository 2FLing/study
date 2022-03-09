// For running this program on cygwin terminal,
// you have to use "mv" instruction to convert
// the input file to the data file named "data.in"
// then use "g++" instruction to make the cpp file
// to be an application. Then afer running the 
// aplication, you will get a new data file named "data.out"
// in the folder. Then use "mv" instruction again to
// convert it to the same format as the original file
// for testing purpose.
// 
// 
// For example, if the input file is a video named "tst.mp4"
// then the instructions you need to use will be

// "mv tst.mp4 data.in" ------------convert the input file to data file named "data.in"
// "g++ Csci114_P1.cpp -o p1" -------- to make cpp file to be an application
// "./p1" ---------- execute the application which just created (p1)
// "mv data.out new.mp4" ---------- convert data.out to the file with the same format as the input file.
// finally, open "new.mp4" see if it is can be opened correctly.
// It will be the same for the other file of input file.
// ***********************************************************************
// * However, for some reasons, when I try to process a .mp4 format file,*
// * it is very slow. A 10 mb .mp4 file took me about an hour to process.*
// * I dont know why. That is why I removed sleep function, because with *
//    sleep(), it will be more slower.                                   *
// ***********************************************************************
#include <unistd.h>     
#include <sys/types.h>     
#include <stdio.h>      
#include <sys/wait.h>   
#include <stdlib.h>     
#include<fstream>
using namespace std;
int main()
{
    int fd[2];
    pipe(fd);
    ifstream inFile;
    ofstream outFile;
    char c;
    bool unfinish;
    if(fork()==0)
    {
        outFile.open("data.out",ios::out|ios::binary);
        close(fd[1]);
        while(true)
        {
            unfinish=read(fd[0],&c,sizeof(c));
            if(!unfinish)
            {
                break;
            }
            outFile.put(c);
        }
        close(fd[0]);
    }
    else
    {
        inFile.open("data.in",ios::in|ios::binary);
        close(fd[0]);
        while(inFile.get(c))
        {
            write(fd[1],&c,sizeof(c));
        }

    }
    inFile.close();
    outFile.close();
    return 0;
}
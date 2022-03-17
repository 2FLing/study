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

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool file_processor(string);
int main()
{
	string file_name = "data.in";
	file_processor(file_name);
	return 0;
}
bool file_processor(string file_name)
{
	ifstream file;
	ofstream out_file;
	char c;
	bool res = true;
	file.open(file_name,ios::in|ios::binary);

	if (file.is_open())
	{
		
		out_file.open("data.out",ios::out|ios::binary);
		while (file.get(c))
		{
			out_file.put(c);
		}
		file.close();
		out_file.close();
	}
	else
	{
		cout << "file does not exist!" << endl;
		res = false;
	}
	return res;
}
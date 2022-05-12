// I executed my program on cygwin terminal
// Before execution, you have to convert the cpp file
// to exe by using g++ CSci114_P5.cpp -o anyname
// then you will see a anyname.exe in the same folder
// After the program been executed, it will generated
// a txt file named "final_size.txt", you will see the 
// result within the txt file.
// attention: if it prompt file does not exist, please check
// if the input file name is "requests-1.txt".

#include <iostream>
#include <fstream>
#include <vector>
#include<string>
#include"LinkedList.h"
using namespace std;
void initial_memory_blocks(linked_list*);
void read_instructions(linked_list*, linked_list*);
void write_result(linked_list*);
void write_result(linked_list* mblock)
{
	fstream file;
	Node* temp = mblock->head;
	file.open("final_size.txt", ios::out);
	while (temp)
	{
		file << to_string(temp->free_memory_size) << endl;
		temp = temp->next;
	}
	file.close();
}
void initial_memory_blocks(linked_list* list)
{
	for (int i = 0; i < 1024; i++)
	{
		list->insert_block(i + 1);
	}
}
void read_instructions(linked_list* mblocks, linked_list* request)
{
	fstream file;
	file.open("requests-1.txt", ios::in);
	if (file.is_open())
	{
		string str;
		while (getline(file, str))
		{
			string instruction;
			int rid;
			instruction = str[0];
			rid = stoi(str.substr(str.find(" ") + 1, 1));
			if (instruction == "A")
			{
				int memory_size = stoi(str.substr(str.find_last_of(" ")));
				int bid = mblocks->find_best(memory_size);
				if (bid == -1)
				{
					cout << "None of the memory block can fit." << endl;
					exit(1);
				}
				mblocks->allocate(bid, memory_size);
				request->insert_request(rid, bid, memory_size);
			}
			else
			{
				int bid = request->get_bid(rid);
				mblocks->release(bid);
			}

		}
		file.close();
	}
	else
	{
		cout << "file does not exist!" << endl;
		exit(1);
	}
}
int main()
{
	linked_list* mblocks = new linked_list();
	linked_list* request = new linked_list();
	initial_memory_blocks(mblocks);
	read_instructions(mblocks, request);
	write_result(mblocks);
	return 0;
}
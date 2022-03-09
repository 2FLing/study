#include<vector>
#include<string>
#include"HeapSortHeader.h"
using namespace std;
vector<int> create_vector();
int main()
{
	Heap h;
	vector<int>v;
	int choice;
	char take_trash;
	string ans="w";
	int temp;
	while (ans != "n")
	{
		cout << "Enter 0 for ascending and 1 for descending order:" << endl;
		cin >> choice;
		take_trash = getchar();
		v=create_vector();
		cout << "input element:";
		cin >> temp;
		if (choice == 0)
		{
			h.buildMaxHeap(v, v.size());
			h.insert_value_maxHeap(h.Arr, temp, h.size);
			cout << "sorted heap: ";
			h.ascendingHeapSort(h.Arr, h.size);
			h.printArray(h.Arr, h.size);
			cout << "On calling extract_maximum:" << h.extract_maximum(h.Arr, h.size) << endl;;
			h.ascendingHeapSort(h.Arr, h.size);
			cout << "Sorted heap is" << endl;
			h.printArray(h.Arr, h.size);
		}
		else
		{
			h.buildMinHeap(v, v.size());
			h.insert_value_minHeap(h.Arr, temp, h.size);
			cout << "sorted heap: ";
			h.descendingHeapSort(h.Arr, h.size);
			h.printArray(h.Arr, h.size);
			cout << "On calling extract_minimum: " << h.extract_minimum(h.Arr) << endl;
			h.descendingHeapSort(h.Arr, h.size);
			cout << "Sorted heap is" << endl;
			h.printArray(h.Arr, h.size);
		}
		cout << "Want to continue testing?(enter 'n' to quit):";
		cin >> ans;
	}


	//h.modifyValMax(h.Arr, h.size, h.size - 1, temp);
	//h.printArray(h.Arr, h.size);

	return 0;
		
}
vector<int> create_vector()
{
	string num;
	vector<int>v;
	cout << "Input array:";
	getline(cin, num);
	for (auto ele : num)
	{
		if (ele != ' ')
		{
			int temp = ele - '0';
			v.push_back(temp);
		}
	}
	return v;
}
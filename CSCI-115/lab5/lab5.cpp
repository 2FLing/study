#include<iostream>
#include<time.h>
#include"counting_sort.h"
using namespace std;
int main()
{
	vector<int>v;
	string choice = "";
	string sort_name;
	float start, end;
	while (choice != "n")
	{
		cout << "Please choose which sort you want to test(0 for counting sort, 1 for radix sort, \'n\' to quit): ";
		getline(cin, choice);
		if (choice == "n")
			break;
		v=create_vector();
		if (choice == "0")
		{
			sort_name = "Counting Sort ";
			start = clock();
			counting_sort(v);
			end = clock();
		}
		else
		{
			sort_name = "Radix Sort ";
			start = clock();
			radix_sort(v);
			end = clock();
		}
		cout << "After sorting, the array is ";
		print_vector(v);
		cout << "It takes " << sort_name << (end - start) / CLOCKS_PER_SEC << "s to finish sorting." << endl;
	}
	v = crazy_vector();
	start = clock();
	counting_sort(v);
	end = clock();
	if(v == in_order_vector())
		cout<<"It takes counting sort "<< (end - start) / CLOCKS_PER_SEC<<"s to finish sorting a completely reversed array from 0 to 999999"<<endl;
	v = crazy_vector();
	start = clock();
	radix_sort(v);
	end = clock();
	if(v == in_order_vector())
		cout<<"It takes radix sort "<< (end - start) / CLOCKS_PER_SEC<<"s to finish sorting a completely reversed array from 0 to 999999"<<endl;
	return 0;
}
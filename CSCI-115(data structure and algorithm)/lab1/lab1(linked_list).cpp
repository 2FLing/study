#include"LinkedList.h"
int main()
{
	linked_list list;
	list.insert(60);
	list.insert(40);
	list.insert(20);
	cout << "Items in the linked list:";
	list.display();
	list.delete_begin();
	cout << "Items in the linked list after deleting the first element:";
	list.display();
	list.delete_end();
	cout << "Items in the linked list after deleting the last element:";
	list.display();
	return 0;
}
#include "stack.h"

int main()
{
	stack st;
	int pop_item, peek_item;
	st.push(20);
	st.push(40);
	st.push(60);
	st.display();
	pop_item = st.pop();
	cout << "Poped tiem is: " << pop_item << endl;
	peek_item = st.peek();
	cout << "Peeked item is:" << peek_item << endl;
	st.display();
	return 0;
}
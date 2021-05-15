#include "Stack.h"
#include <iostream>
using namespace std;


Stack::Stack()
{
	top = -1;
}

void Stack::display()
{
	for (int i = 0; i <= top; i++)
	{
		cout << "items" << ":" << arr[i] << endl;
	}
}


void Stack::push(int n)
{
	if (isFull() == false)
	{
		top++;
		arr[top] = n;

		cout << n << " is pushed" << endl;
	}
	else
		cout << "Stack is full" << endl;

}
int Stack::pop()
{
	int popped = -1;
	if (isEmpty() == false)
	{
		popped = arr[top];
		top--;
		return popped;
	}
	return popped;
}



bool Stack::isFull()
{
	if (top == 4)
	{
		return true;
	}
	else
		return false;

}

bool Stack::isEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
		return false;

}
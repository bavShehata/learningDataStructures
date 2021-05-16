// LabTwo_Answers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Stack
{
private:
	int top;
	int arr[5];

public:
	void push(int n);
	int pop();
	bool isFull();
	bool isEmpty();
	void display();
	Stack();
};

Stack::Stack()
{
	top = -1;
}

void Stack::display()
{
	for (int i = 0; i <= top; i++)
	{
		cout << "items"
			 << ":" << char(arr[i]) << endl;
	}
}

void Stack::push(int n)
{
	if (isFull() == false)
	{
		top++;
		arr[top] = n;

		cout << char(n) << " is pushed" << endl;
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

bool isBalanced(Stack s)
{
	int x;
	int balance = 0;
	while (!s.isEmpty())
	{
		x = s.pop();
		if (char(x) == '(')
			balance++;
		else if (char(x) == ')')
			balance--;
	};
	if (balance != 0)
		return false;
	else
		return true;
}

int main()
{
	Stack s;
	char ch;
	char p;
	int c;

	do
	{

		cout << "to push item enter 1" << endl;
		cout << "to pop item enter 2" << endl;
		cout << "to display items enter 3" << endl;
		cout << "to exit enter 4" << endl;
		cout << "enter your choice" << endl;
		cin >> c;

		switch (c)
		{
		case 1:
			cout << "please enter character" << endl;
			cin >> ch;
			s.push(int(ch));
			break;
		case 2:
			if (!s.isEmpty())
			{
				p = char(s.pop());
				cout << p << " is popped" << endl;
			}
			else
				cout << "Stack is Empty" << endl;
			break;
		case 3:
			s.display();
			break;
		case 4:
			return 0;
		case 5:
			if (isBalanced(s))
				cout << "BALANCED\n";
			else
				cout << "NOT BALANCED :(\n";
		}
	} while (c != 4);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

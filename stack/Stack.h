#pragma once
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


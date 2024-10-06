#include<iostream>

using namespace std;

class Stack {
private:
	int top;
	char* items;
	int capacity;
	int count=0;
	int minEle;
public:
	Stack(int n);
	~Stack();
	bool isEmpty();
	bool isFull();
	void Push(int newItem);
	void Pop();
	int size();
	int getMin();

};
Stack::Stack(int n) {
	capacity = n;
	items = new char[n];
	top = -1;
}
Stack::~Stack() {
	delete[] items;
}
bool Stack::isEmpty() {
	return (top == -1);
}
bool Stack::isFull() {
	return (top == capacity - 1);
}
void Stack::Push(int newItem) {
	if (isFull()) {
		cout << "STACK OVERFLOW" << endl;
		exit(1);
	}
	if (isEmpty()) {
		top++;
		items[top] = newItem;
		minEle = newItem;
	}
	else if (newItem >= minEle) {
		top++;
		items[top] = newItem;
	}
	else if (newItem < minEle) {
		top++;
		items[top] = 2 * newItem - minEle;
		minEle = newItem;
	}
	
}
void Stack::Pop() {
	if (isEmpty()) {
		cout << "STACK UNDERFLOW" << endl;
		exit(1);
	}
	int item = items[top];
	top--;
	if (item < minEle) {
		minEle = 2 * minEle - item;
	}
	
	
}
int Stack::size() {
	int size = ++top;
	return size;
}
int Stack::getMin() {
	int min;
	if (isEmpty()) {
		cout << "Stack is Empty"<<endl;
		return -1;
	}
	else {
		min = minEle;
		return min;
	}

}

int main() {
	Stack s(10);
	s.Push(5);
	s.Push(7);
	s.Push(8);
	s.Push(4);
	s.Push(9);
	cout << "\nsize of stack: " << s.size();
	cout << "\nMinimun value is: " << s.getMin();
	s.Push(3);
	s.Push(10);
	s.Push(11);
	s.Push(2);
	cout << "\nsize of stack: " << s.size();
	cout << "\nMinimun value is: " << s.getMin();
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	cout << "\nsize of stack: " << s.size();
	cout << "\nMinimun value is: " << s.getMin();
	return 0;
}
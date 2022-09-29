#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int> Stack;
	int a = 1, b = 2, c = 3, d = 4;
	//stack 초기화
	Stack.push_front(a);
	Stack.push_front(b);
	Stack.push_front(c);
	Stack.push_front(d);

	//FIFO
	Stack.pop_back();
	
	cout << "FIFO\n";
	for (deque< int >::iterator iterPos = Stack.begin(); iterPos != Stack.end();
 ++iterPos)
	{
		cout << " " << *iterPos << endl;
	}



	//LIFO
	Stack.pop_front();

	cout << "LIFO\n";
	for (deque< int >::iterator iterPos = Stack.begin(); iterPos != Stack.end(); 
++iterPos)
	{
		cout << " " << *iterPos << endl;
	}

}
#include <iostream> 
#include <deque> 
using namespace std;

int main()
{
	deque< int > deque1;

	cout << "assign 1" << endl;
	deque1.assign(7, 7);
	for (deque< int >::iterator iterPos = deque1.begin();
		iterPos != deque1.end();
		++iterPos)
	{
		cout << "deque 1 : " << *iterPos << endl;
	}

	cout << endl << "assign 2" << endl;
	deque< int > deque2;
	deque2.assign(deque1.begin(), deque1.end());
	for (deque< int >::iterator iterPos = deque2.begin();
		iterPos != deque2.end();
		++iterPos)
	{
		cout << "deque 2 : " << *iterPos << endl;
	}

	// swap 
	deque< int > deque3;
	deque3.push_back(10);
	deque3.push_back(20);
	deque3.push_back(30);

	cout << endl << "swap" << endl;
	deque3.swap(deque1);
	for (deque< int >::iterator iterPos = deque3.begin();
		iterPos != deque3.end();
		++iterPos)
	{
		cout << "deque 3 : " << *iterPos << endl;
	}

	for (deque< int >::iterator iterPos = deque1.begin();
		iterPos != deque1.end();
		++iterPos)
	{
		cout << "deque 1 : " << *iterPos << endl;
	}
}
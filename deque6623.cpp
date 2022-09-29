#include <iostream>
#include <deque>

using namespace std;

typedef deque<int> Deque;

void Undo(Deque* main, Deque* bin) {
	if (main->empty()) {
		cout << "더 이상 항복이 없습니다\n";
	}
	else {
		int x = main->front();
		main->pop_front();  //없애기
		bin->push_front(x);  //추가하기 
	}
}

void Redo(Deque* main, Deque* bin) {
	if (bin->empty()) {
		cout << "더 이상 항목이 없습니다\n";
	}
	else {
		int x = bin->front();
		bin->pop_front();
		main->push_front(x);
	}
}

void Print(Deque* main) {
	if (main->empty()) {
		cout << "이 디큐는 비어있습니다\n";
	}
	else {
		for (deque< int >::iterator iterPos = main->begin(); iterPos != main->end(); ++iterPos)
		{
			cout << " " << *iterPos << endl;
		}
	}
}


int main() {
	int a = 1, b = 2, c = 3, d = 4, y;
	Deque Inventory;
	Deque Trash;

	//Inventory 초기화
	Inventory.push_front(a);
	Inventory.push_front(b);
	Inventory.push_front(c);
	Inventory.push_front(d);

	cout << "Inventory before undo\n";
	Print(&Inventory);

	Undo(&Inventory, &Trash);

	//if (Inventory.empty()) {
	//	cout << "더 이상 항복이 없습니다";
	//}
	//else {
	//	y = Inventory.front();
	//	Inventory.pop_front(); //없애기
	//	Trash.push_front(y); //추가하기
	//}

	cout << "after undo:\n";
	cout << "Inventory\n";
	Print(&Inventory);
	cout << "Trash\n";
	Print(&Trash);



	Redo(&Inventory, &Trash);


	//if (Trash.empty()) {
	//	cout << "더 이상 항복이 없습니다";
	//}
	//else {
	//	y = Trash.front();
	//	Trash.pop_front();  //없애기
	//	Inventory.push_front(y);  //추가하기
	//}

	cout << "after redo:\n";
	cout << "Inventory\n";
	Print(&Inventory);
	cout << "Trash\n";
	Print(&Trash);

}
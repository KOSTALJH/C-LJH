#include <iostream>
#include <deque>

using namespace std;

class Items
{
	public:
		//생성자
		Items(int Index) {
		}

		int Trash;
		deque <Items> Inventory;
		deque <Items> Bin;
	
		void Undo() {
			if (Inventory.empty()) {
				cout << "더 이상 항목이 없습니다";
			}
			else {
				Trash = Inventory.front(); //Inventory 가장 늦게 추가된 원소를 저장
				Inventory.pop_front(); //Inventory에서 원소 삭제
				Bin.push_front(Trash); //Bin으로 저장
			}
		}

	void Redo() {
		if (Bin.empty()) {
			cout << "더 이상 항목이 없습니다";
		}
		else {
			Trash = Bin.front(); //Bin에 가장 늦게 추가된 원소 저장
			Bin.pop_front(); // Bin에서 원소 삭제
			Inventory.push_front(Trash); //Inventory로 저장
		}
	}
};

int main() {
	//intialize deque
	Items Item1(1);
	Items Item2(2);
	Items Item3(3);
	Items Item4(4);
	
	Inventory.push_front(Item1);
	Inventory.push_front(Item2);
	Inventory.push_front(Item3);
	Inventory.push_front(Item4);

	Items::Inventory.Undo();
	cout << " " << Inventory.front();
	cout << " " << Bin.front();

	Items::Inventory.Redo();
	cout << " " << Inventory.front();
	cout << " " << Bin.front();
}

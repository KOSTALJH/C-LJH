#include <iostream> 
#include <deque> 
using namespace std;

// 서버/클라이언트 같에 주고 받는 패킷
struct Packet
{
	unsigned short Index; // 패킷 인덱스
	unsigned short BodySize; // 패킷 보디(실제 데이터)의 크기
	char acBodyData[100]; // 패킷의 데이터
};


int main()
{
	Packet Pkt1;
	Pkt1.Index = 1; Pkt1.BodySize = 10;

	Packet Pkt2;
	Pkt2.Index = 2; Pkt2.BodySize = 12;

	Packet Pkt3;
	Pkt3.Index = 3; Pkt3.BodySize = 14;

	Packet Pkt4;
	Pkt4.Index = 4; Pkt4.BodySize = 16;

	deque< Packet > ReceivePackets;
	ReceivePackets.push_back(Pkt1);
	ReceivePackets.push_back(Pkt2);
	ReceivePackets.push_back(Pkt3);

	cout << "< insert >" << endl;

	// 첫 번째 위치에 Pkt3을 삽입
	cout << "insert 1" << endl;
	ReceivePackets.insert(ReceivePackets.begin(), Pkt3);

	for (deque< Packet >::iterator iterPos = ReceivePackets.begin();
		iterPos != ReceivePackets.end();
		++iterPos)
	{
		cout << "패킷 인덱스: " << iterPos->Index;
		cout << " 패킷 바디 크기: " << iterPos->BodySize << endl;
	}


	// 두 번째 위치에 Pkt4를 2개 삽입
	cout << endl << "insert 2" << endl;
	ReceivePackets.insert(++ReceivePackets.begin(), 2, Pkt4);
	for (deque< Packet >::iterator iterPos = ReceivePackets.begin();
		iterPos != ReceivePackets.end();
		++iterPos)
	{
		cout << "패킷 인덱스: " << iterPos->Index;
		cout << " 패킷 바디 크기: " << iterPos->BodySize << endl;
	}


	deque< Packet > ReceivePackets2;
	ReceivePackets2.push_back(Pkt3);
	ReceivePackets2.push_back(Pkt4);
	ReceivePackets2.push_back(Pkt1);

	// ReceivePackets2의 모든 것을 ReceivePackets의 첫 번째 위치에 삽입
	cout << endl << "insert 3" << endl;
	ReceivePackets.insert(ReceivePackets.begin(), ReceivePackets2.begin(),
		ReceivePackets2.end());
	for (deque< Packet >::iterator iterPos = ReceivePackets.begin();
		iterPos != ReceivePackets.end();
		++iterPos)
	{
		cout << "패킷 인덱스: " << iterPos->Index;
		cout << " 패킷 바디 크기: " << iterPos->BodySize << endl;
	}
	cout << endl << "< erase >" << endl;

	// 두 번째 원소를 삭제한다. 
	cout << "erase 1" << endl;
	ReceivePackets.erase(++ReceivePackets.begin());
	for (deque< Packet >::iterator iterPos = ReceivePackets.begin();
		iterPos != ReceivePackets.end();
		++iterPos)
	{
		cout << "패킷 인덱스: " << iterPos->Index;
		cout << " 패킷 바디 크기: " << iterPos->BodySize << endl;
	}

	// 두 번째 이후부터 모두 삭제한다. 
	cout << endl << "erase 2" << endl;
	ReceivePackets.erase(++ReceivePackets.begin(), ReceivePackets.end());
	for (deque< Packet >::iterator iterPos = ReceivePackets.begin();
		iterPos != ReceivePackets.end();
		++iterPos)
	{
		cout << "패킷 인덱스: " << iterPos->Index;
		cout << " 패킷 바디 크기: " << iterPos->BodySize << endl;
	}
}
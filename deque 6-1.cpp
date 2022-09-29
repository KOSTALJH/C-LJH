#include <iostream> 
#include <deque> 
using namespace std;


// 서버/ 클라이언트간에 주고 받는 패킷
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


	deque< Packet > ReceivePackets;


	// 뒤에 추가
	ReceivePackets.push_back(Pkt2);
	ReceivePackets.push_back(Pkt3);

	// 앞에 추가
	ReceivePackets.push_front(Pkt1);

	// 저장된 패킷 정보 출력
	for (deque< Packet >::iterator iterPos = ReceivePackets.begin();
		iterPos != ReceivePackets.end();
		++iterPos)
	{
		cout << "패킷 인덱스: " << iterPos->Index << endl;
		cout << "패킷 바디 크기: " << iterPos->BodySize << endl;
	}

	cout << endl << "역방향으로 출력" << endl;
	for (deque< Packet >::reverse_iterator iterPos = ReceivePackets.rbegin();
		iterPos != ReceivePackets.rend();
		++iterPos)
	{
		cout << "패킷 인덱스: " << iterPos->Index << endl;
		cout << "패킷 바디 크기: " << iterPos->BodySize << endl;
	}

	cout << endl << "배열 방식으로 접근" << endl;
	// 저장된 총 패킷 수
	int ReceivePacketCount = ReceivePackets.size();
	cout << "총 패킷 수: " << ReceivePacketCount << endl;
	for (int i = 0; i < ReceivePacketCount; ++i)
	{
		cout << "패킷 인덱스: " << ReceivePackets[i].Index << endl;
		cout << "패킷 바디 크기: " << ReceivePackets[i].BodySize << endl;
	}


	// 첫 번째, 마지막 위치에 있는 패킷
	Packet& FirstPacket = ReceivePackets.front();
	cout << "첫 번째 패킷의 인덱스: " << FirstPacket.Index << endl;

	Packet& LastPacket = ReceivePackets.back();
	cout << "마지막 패킷의 인덱스: " << LastPacket.Index << endl;

	// at을 사용하여 두 번째 패킷
	Packet& PacketAt = ReceivePackets.at(1);
	cout << "두 번째 패킷의 인덱스: " << PacketAt.Index << endl;


	// 첫 번째 패킷 삭제
	ReceivePackets.pop_front();
	cout << "첫 번째 패킷의 인덱스: " << ReceivePackets[0].Index << endl;

	// 마지막패킷삭제
	ReceivePackets.pop_back();
	LastPacket = ReceivePackets.back();
	cout << "마지막 패킷의 인덱스: " << LastPacket.Index << endl;

	// 모든 패킷을 삭제
	if (false == ReceivePackets.empty())
	{
		cout << "모든 패킷을 삭제합니다." << endl;
		ReceivePackets.clear();
	}
}
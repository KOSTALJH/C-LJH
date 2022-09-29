#include <iostream>
#include <deque>
#include <chrono>

using namespace std;
using namespace chrono;

int main( )
{
    deque<int> dq;
    system_clock::time_point start = system_clock::now();
    for(int i = 0 ; i < 4 ; i++) {
        dq.push_back( (i+1)*10 );
        
        cout << sizeof(dq) << ' ' ;  
    }
    cout << endl;
    for(int i = 0; i < 4; i++) {
        dq.push_front( (i+1)*3);
        cout << sizeof(dq) << ' ';
    }
    // for( int i = 0 ; i < dq.size() ; i++)
    //     cout << dq[i] << ' ';
    cout << endl;
}
#include <iostream>
#include <vector>
using namespace std;

void part(string s, int& p){
    static int num = 1;
    string a;
    char B[] = "";
    if(num == p) return;
    int count = 1;
    if (num == 1) cout << count << endl;
    
    for(int i = 0; i < s.length(); i++){
        if (s[i] == s[i+1]) count++;
        else{
            a.push_back(count + 48);
            a.push_back(s[i]);
            count = 1;
        }
    }
    for(string::iterator itr = a.begin(); itr != a.end(); itr++){
        B[num] = *itr;
        cout << B[num];
    }
    num++;
    cout << endl;
    part(a,p);
    
}


int main() {
    int pre;
    cin >> pre;
    
    string s("1");
    part("1", pre);
}
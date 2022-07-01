// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <deque>

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

deque<char> dq;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin>>s;
    string bomb; cin>>bomb;

    int size = bomb.size();
    for(int i=0;i<s.size();i++){
        dq.push_back(s[i]);
        if(s[i] != bomb[size-1]) continue;

        if(dq.size()>=size) {
            bool trigger = true;
            for (int j = 0; j < size; j++) {
                if (dq.size() - 1 - j < 0 || dq[dq.size() - 1 - j] != bomb[size - j - 1]) {
                    trigger = false;
                    break;
                }
            }

            int cpy_size = size;
            if (trigger) {
                while (cpy_size--)
                    dq.pop_back();
            }
        }
    }

    if(dq.empty()) {
        cout<<"FRULA";
    }else{
        for(int k=0;k<dq.size();k++) cout<<dq[k];
    }

    return 0;
}
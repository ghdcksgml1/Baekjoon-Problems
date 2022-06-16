// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 21428 KB , 시간 : 172ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string.h> // memset

using namespace std;

unordered_map<int,int> um;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M; cin>>N>>M;
    int cnt = N+M;
    int join = 0;
    while(N--){
        int tmp; cin>>tmp;
        um[tmp] = 1;
    }
    while(M--){
        int tmp; cin>>tmp;
        if(um[tmp] == 1) join++;
    }

    cout<<(cnt-(2*join))<<'\n';

    return 0;
}
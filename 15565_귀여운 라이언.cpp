// 언어 : C++ , (성공/실패) : 1/1 , 메모리 : 5404 KB , 시간 : 60ms
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string.h> // memset

using namespace std;

vector<int> v;
deque<int> dq;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,K; cin>>N>>K;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        if(tmp==1){
            v.push_back(i);
        }
    }

    if(v.size() < K) {
        cout<<-1<<'\n';
        return 0;
    }
    for(int i=0;i<K;i++){
        dq.push_back(v[i]);
    }

    int len = dq.back() - dq.front() + 1;

    for(int i=K;i<v.size();i++){
        dq.pop_front();
        dq.push_back(v[i]);
        len = min(len, dq.back() - dq.front() + 1);
    }

    cout<<len<<'\n';

    return 0;
}
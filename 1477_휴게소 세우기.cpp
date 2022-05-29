// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int N,M,L;
int min_len = 1e9;
vector<int> v;

bool func(int x){
    int prev = 0;
    int cnt = 0;

    for(int cur: v){
        int diff = (cur - prev);
        prev = cur;
        if(diff <= x) continue;
        if(diff%x == 0) cnt += (diff/x) - 1;
        else cnt += (diff/x);
    }


    if(cnt > M) {
        return false;
    }
    else {
        min_len = min(min_len, x);
        return true;
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M>>L;
    int prev = 0;
    int max_len = 0;
    for(int i=0;i<N;i++){
        int tmp; cin>>tmp;
        v.push_back(tmp);
    }
    v.push_back(L);

    sort(v.begin(), v.end());

    for(int i=0;i<v.size();i++){
        max_len = max(max_len,v[i] - prev);
        prev = v[i];
    }



    int st=1, en=max_len;
    while(st<=en){
        int mid = (st + en) / 2;
        if(func(mid)){
            en = mid - 1;
        }else{
            st = mid + 1;
        }
    }

    cout<<min_len<<'\n';

    return 0;
}
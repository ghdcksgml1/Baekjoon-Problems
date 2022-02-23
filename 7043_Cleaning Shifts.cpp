// 언어 : C++ , (성공/실패) : 1/6 , 메모리 : 2536 KB , 시간 : 8ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int N,T;
vector<pair<int,int>> v;

bool compare(pair<int,int> a,pair<int,int> b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>T;
    for(int i=0;i<N;i++){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());

    v.push_back({1000000000,0});
    bool trigger=0;
    int x=0;
    int y=0;
    int cnt=0;
    for(int i=0;i<v.size();i++){
        if(v[i].first<=x+1){
            if(y<v[i].second){
                y = v[i].second;
                trigger=true;
            }
            if(v[i+1].first > x+1 && trigger){ // 다음 숫자올 숫자의 first가 전에 비교한 값의 second+1보다 크다면
                // ex.) 1 4    3 5    5 7 인 경우에는 현재 3 5이므로 카운팅하지 않는다.
                cnt++;
                x=y;
                trigger=false;
            }
        }
    }

    if(y==T) cout<<cnt<<'\n';
    else cout<<"-1"<<'\n';

    return 0;
}
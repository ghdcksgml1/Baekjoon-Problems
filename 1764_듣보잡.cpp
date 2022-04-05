// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 12816 KB , 시간 : 64 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <unordered_map>

using namespace std;

unordered_map<string,int> um;
vector<string> v;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M; cin>>N>>M;

    for(int i=0;i<N;i++){
        string tmp = ""; cin>>tmp;
        um[tmp] = 1;
    }
    for(int i=0;i<M;i++){
        string tmp = ""; cin>>tmp;
        if( um[tmp] == 1 ){
            v.push_back(tmp);
        }
    }

    sort(v.begin(),v.end());

    cout<<v.size()<<'\n';
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<'\n';
    }

    return 0;
}
// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

vector<vector<pii>> p_list;

bool compare(pii a, pii b){
    if(a.yy == b.yy) return a.xx < b.xx;
    else return a.yy > b.yy;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M; cin>>N>>M;

    for(int i=0; i<50; i++){
        vector<pair<int,int>> v;
        for(int i=0;i<26; i++){
            v.push_back({i,0});
        }
        p_list.push_back(v);
    }

    for(int i=0; i<N; i++){
        string s; cin>>s;
        for(int j=0; j<s.size(); j++){
            p_list[j][s[j]-'A'].yy++;
        }
    }

    for(int i=0; i<M; i++){
        sort(ALL(p_list[i]), compare);
    }

    string result = "";
    int cnt = 0;
    for(int i=0; i<M; i++){
        for(int j=0; j<26 ; j++){
            if(j == 0){
                result += (p_list[i][j].xx + 'A');
            }else{
                cnt += p_list[i][j].yy;
            }
        }
    }

    cout<<result<<"\n"<<cnt<<"\n";

    return 0;
}
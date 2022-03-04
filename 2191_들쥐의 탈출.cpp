// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2168 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <math.h>
#define MAX 101

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int N,M;
float S,V;

pair<int,int> mouse[MAX];
pair<int,int> hole[MAX];

bool dfs(int x){
    for(auto t : a[x]){
        if(c[t]) continue;
        c[t] = true;
        if(d[t] == 0 || dfs(d[t])){
            d[t] = x;
            return true;
        }
    }
    return false;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M>>S>>V;

    for(int i=1;i<=N;i++){
        float x,y; cin>>x>>y;
        mouse[i] = {x,y};
    }
    for(int i=1;i<=M;i++){
        float x,y; cin>>x>>y;
        hole[i] = {x,y};
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            float tmp = sqrt(pow(abs(mouse[i].first-hole[j].first),2) + pow(abs(mouse[i].second-hole[j].second),2));
            if(tmp <= S*V){
                a[i].push_back(j);
            }
        }
    }

    int count = 0;
    for(int i=1;i<=N;i++){
        fill(c,c+MAX,false);
        if(dfs(i)) count++;
    }

    cout<<N-count<<'\n';

    return 0;
}
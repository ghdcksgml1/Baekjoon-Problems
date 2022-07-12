// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

vector<pii> v;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin>>T;
    while(T--){
        v.clear();
        int N; cin>>N;
        for(int i=0;i<N;i++){
            int x,y; cin>>x>>y;
            v.push_back({x,y});
        }

        sort(ALL(v));
        int cnt = 1;
        int mn = v[0].yy;
        for(int i=1;i<N;i++){
            if(v[i].yy < mn){
                cnt++;
                mn = v[i].yy;
            }
        }

        cout<<cnt<<'\n';
    }

    return 0;
}
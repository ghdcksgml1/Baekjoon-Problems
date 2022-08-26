// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

priority_queue<int, vector<int>, greater<int>> pq;
vector<pii> v;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    while(N--){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }
    sort(ALL(v));

    int mx = 0;
    for(pii cur : v){
        pq.push(cur.second);
        while(!pq.empty() && cur.first >= pq.top()){
            pq.pop();
        }
        mx = mx > pq.size()? mx : pq.size();
    }

    cout<<mx<<'\n';

    return 0;
}
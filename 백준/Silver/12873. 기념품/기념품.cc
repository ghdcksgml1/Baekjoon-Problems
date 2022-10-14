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

void removeQueue(queue<int> &q, ll n){
    n--;
    n %= q.size();
    for(int i=0; i<n; i++){
        q.push(q.front());
        q.pop();
    }
    q.pop();
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    queue<int> q;
    for(int i=1; i<=N; i++)
        q.push(i);

    ll i = 1;
    while(q.size() > 1){
        removeQueue(q, i*i*i);
        i++;
    }
    cout<<q.front()<<"\n";

    return 0;
}
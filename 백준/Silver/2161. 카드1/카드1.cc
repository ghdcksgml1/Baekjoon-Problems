// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <queue>
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

queue<int> q;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=1; i<=N; i++){
        q.push(i);
    }

    while(q.size() > 1){
        cout<<q.front()<<" ";
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout<<q.front()<<"\n";

    return 0;
}
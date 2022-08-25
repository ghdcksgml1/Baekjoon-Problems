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

priority_queue<int> pq_mx;
priority_queue<int, vector<int>, greater<int>> pq_mn;
vector<int> v;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=0; i<N; i++){
        int tmp; cin>>tmp;
        if(tmp > 1)
            pq_mx.push(tmp);
        else if (tmp == 1)
            v.push_back(tmp);
        else
            pq_mn.push(tmp);
    }

    while(!pq_mx.empty()){
        if(pq_mx.size() == 1){
            v.push_back(pq_mx.top());
            break;
        }
        int a = pq_mx.top(); pq_mx.pop();
        int b = pq_mx.top(); pq_mx.pop();
        v.push_back(a*b);
    }

    while(!pq_mn.empty()){
        if(pq_mn.size() == 1){
            v.push_back(pq_mn.top());
            break;
        }
        int a = pq_mn.top(); pq_mn.pop();
        int b = pq_mn.top(); pq_mn.pop();
        v.push_back(a*b);
    }

    int sum = 0;
    for(int cur : v)
        sum += cur;

    cout<<sum<<'\n';

    return 0;
}
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
#define MAX 1e6+1000

using namespace std;
typedef long long ll;

vector<int> tree(MAX*4,0);
pii arr[101000];

int query(int left,int right,int node,int start,int end){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right) return tree[node];
    int mid = start + end >> 1;
    return query(left,right,node*2,start,mid) +
        query(left,right,node*2+1,mid+1,end);
}

int update(int target,int node,int start,int end){
    if(target>end || target<start) return tree[node];
    if(start == end) return tree[node] += 1;
    int mid = start + end >> 1;
    return tree[node] = update(target,node*2,start,mid) +
            update(target,node*2+1,mid+1,end);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=1;i<=2*N;i++){
        int tmp; cin>>tmp;
        if(!arr[tmp].xx) arr[tmp].xx = i;
        else arr[tmp].yy = i;
    }

    sort(arr+1,arr+N+1);

    ll cnt = 0;
    for(int i=1;i<=N;i++){
        cnt += query(arr[i].xx,arr[i].yy,1,1,2*N);
        update(arr[i].yy,1,1,2*N);
    }

    cout<<cnt<<'\n';

    return 0;
}
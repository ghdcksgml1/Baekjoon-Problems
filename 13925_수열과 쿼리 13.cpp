// 언어 : C++ , (성공/실패) : 1/10 , 메모리 : 14652 KB , 시간 : 216ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
struct Tree{
    ll value = 0;
    ll lazy_a = 1; // 곱
    ll lazy_b = 0; // 합
}tree[5050505];

ll N,M;
ll arr[1010101];

ll buildRec(ll node,ll start,ll end){
    if(start == end)
        return tree[node].value = arr[start];
    ll mid = (start + end) / 2;
    return tree[node].value = (buildRec(node*2,start,mid) + buildRec(node*2+1,mid+1,end)) % MOD;
}

void propagation(ll node,ll start,ll end){
    if(tree[node].lazy_a!=1){
        tree[node].value = (tree[node].lazy_a * tree[node].value) % MOD;
        if(start != end){
            tree[node*2].lazy_a = (tree[node*2].lazy_a * tree[node].lazy_a) % MOD;
            tree[node*2+1].lazy_a = (tree[node*2+1].lazy_a * tree[node].lazy_a) % MOD;
            tree[node*2].lazy_b = (tree[node*2].lazy_b * tree[node].lazy_a) % MOD;
            tree[node*2+1].lazy_b = (tree[node*2+1].lazy_b * tree[node].lazy_a) % MOD;
        }
        tree[node].lazy_a = 1;
    }
    if(tree[node].lazy_b!=0){
        tree[node].value = (tree[node].value + (end-start+1)*tree[node].lazy_b) % MOD;
        if(start != end){
            tree[node*2].lazy_b = (tree[node*2].lazy_b+tree[node].lazy_b) % MOD;
            tree[node*2+1].lazy_b = (tree[node*2+1].lazy_b+tree[node].lazy_b) % MOD;
        }
        tree[node].lazy_b = 0;
    }
}

void updateRec(int left,int right,int node,int start,int end,int a,int b,int v){
    propagation(node,start,end);
    if(left > end || right < start) return;
    if(left<=start && end<=right){
        if(a!=0){ // 곱
            tree[node].lazy_a = a;
            propagation(node,start,end);
        }else if(b!=0){ // 합
            tree[node].lazy_b = b;
            propagation(node,start,end);
        }else if(v!=0){ // V
            tree[node].lazy_a = 0;
            tree[node].lazy_b = v;
            propagation(node,start,end);
        }
        return;
    }
    ll mid = (start + end) / 2;
    updateRec(left,right,node*2,start,mid,a,b,v);
    updateRec(left,right,node*2+1,mid+1,end,a,b,v);
    tree[node].value = (tree[node*2].value + tree[node*2+1].value) % MOD;
}

ll queryRec(ll left,ll right,ll node,ll start,ll end){
    propagation(node,start,end);
    if(left>end || right<start) return 0;
    if(left<=start && end<=right) return tree[node].value;
    int mid = (start + end) / 2;
    return (queryRec(left,right,node*2,start,mid)+ queryRec(left,right,node*2+1,mid+1,end)) % MOD;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++) cin>>arr[i];

    buildRec(1,1,N);

    cin>>M;

    for(int i=0;i<M;i++){
        int t,x,y,v;
        cin>>t;
        if(t==1){ // [x,y]에 v를 더해줌.
            cin>>x>>y>>v;
            updateRec(x,y,1,1,N,0,v,0);
        }else if(t==2){ // [x,y]에 v를 곱해줌.
            cin>>x>>y>>v;
            updateRec(x,y,1,1,N,v,0,0);
        }else if(t==3){ // [x,y]를 v로 바꿈.
            cin>>x>>y>>v;
            updateRec(x,y,1,1,N,0,0,v);
        }else if(t==4){ // [x,y] 구간의 합
            cin>>x>>y;
            cout<<(queryRec(x,y,1,1,N) % MOD)<<'\n';
        }
    }

    return 0;
}
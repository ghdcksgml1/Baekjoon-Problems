// 언어 : C++ , (성공/실패) : 1/1 , 메모리 : 12176 KB , 시간 : 92 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;
typedef long long ll;

ll N,Q;
ll arr[100001];

struct Tree{
    ll value = 0;
    ll lazy_a = 0; // 개수
    ll lazy_b = 0; // (L-1) 더한거
}tree[400001];

ll buildRec(ll node,ll start,ll end){
    if(start == end){
        return tree[node].value = arr[start];
    }
    ll mid = (start + end) / 2;
    return tree[node].value = buildRec(node*2,start,mid) + buildRec(node*2+1,mid+1,end);
}

void propagation(ll node,ll start,ll end){
    if(tree[node].lazy_a){
        if(start != end){
            tree[node*2].lazy_a += tree[node].lazy_a;
            tree[node*2].lazy_b += tree[node].lazy_b;

            tree[node*2+1].lazy_a += tree[node].lazy_a;
            tree[node*2+1].lazy_b += tree[node].lazy_b;
        }else{
            tree[node].value += (start*tree[node].lazy_a)-tree[node].lazy_b;
        }
        tree[node].lazy_a = 0;
        tree[node].lazy_b = 0;
    }
}

void updateRec(ll left,ll right,ll node,ll start,ll end){
    propagation(node,start,end);
    if(left > end || right < start) return;
    if(left<=start && end<=right){
        tree[node].lazy_a += 1;
        tree[node].lazy_b += (left-1);
        return;
    }

    ll mid = (start + end) / 2;
    updateRec(left,right,node*2,start,mid);
    updateRec(left,right,node*2+1,mid+1,end);
}

ll query(ll target,ll node,ll start,ll end){
    propagation(node,start,end);
    if(target > end || target < start){
        return 0;
    }
    if(start == end){
        return tree[node].value;
    }

    ll mid = (start + end) / 2;
    return query(target,node*2,start,mid) + query(target,node*2+1,mid+1,end);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }

    buildRec(1,1,N);

    cin>>Q;
    while(Q--){
        ll t,L,R,X;
        cin>>t;
        if(t==1){
            cin>>L>>R;
            updateRec(L,R,1,1,N);
        }else{
            cin>>X;
            cout<<query(X,1,1,N)<<'\n';
        }
    }

    return 0;
}
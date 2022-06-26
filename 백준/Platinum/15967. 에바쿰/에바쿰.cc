// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 1000001

using namespace std;
typedef long long ll;

struct Tree{
    ll value = 0;
    ll lazy = 0;
}tree[MAX * 4];

ll arr[MAX];

void propagation(int node,int start,int end){
    if(tree[node].lazy){
        tree[node].value += (end-start+1) * tree[node].lazy;
        if(start != end){
            tree[node*2].lazy += tree[node].lazy;
            tree[node*2+1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }
}

ll buildRec(int node,int start,int end){
    if(start == end){
        return tree[node].value = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node].value = buildRec(node*2,start,mid) + buildRec(node*2+1,mid+1,end);
}

ll query(int left,int right,int node,int start,int end){
    propagation(node,start,end);
    if(left>end || right<start) return 0;
    if(left<=start && end<=right){
        return tree[node].value;
    }
    int mid = (start + end) / 2;
    return query(left,right,node*2,start,mid) + query(left,right,node*2+1,mid+1,end);
}

void update(int left,int right,int node,int start,int end,ll value){
    propagation(node,start,end);
    if(left>end || right<start) return;
    if(left<=start && end<=right){
        tree[node].value += (end-start+1)*value;
        if(start != end){
            tree[node*2].lazy += value;
            tree[node*2+1].lazy += value;
        }
        return ;
    }
    int mid = (start + end) / 2;
    update(left,right,node*2,start,mid,value);
    update(left,right,node*2+1,mid+1,end,value);
    tree[node].value = tree[node*2].value + tree[node*2+1].value;
}


int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,Q1,Q2; cin>>N>>Q1>>Q2;
    int sum = Q1+Q2;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }

    buildRec(1,1,N);

    while(sum--){
        int a,b,c,d; cin>>a;

        if(a == 1){
            cin>>b>>c;
            cout<<query(b,c,1,1,N)<<'\n';
        }else{
            cin>>b>>c>>d;
            update(b,c,1,1,N,d);
        }

    }



    return 0;
}
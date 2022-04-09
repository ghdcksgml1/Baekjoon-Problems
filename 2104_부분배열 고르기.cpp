// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 13612 KB , 시간 : 32ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 100002

using namespace std;
typedef long long ll;

struct Tree{
    ll idx;
    ll value;
    ll sum;
}tree[MAX*4];

ll arr[MAX];
ll N;
ll result = 0;

void buildRec(ll node,ll start,ll end){
    if(start == end){
        tree[node].idx = start;
        tree[node].value = arr[start];
        tree[node].sum = arr[start];
        return ;
    }
    ll mid = (start + end) / 2;
    buildRec(node*2,start,mid);
    buildRec(node*2+1,mid+1,end);
    tree[node].idx = (tree[node*2].value < tree[node*2+1].value) ? tree[node*2].idx : tree[node*2+1].idx;
    tree[node].value = (tree[node*2].value < tree[node*2+1].value) ? tree[node*2].value : tree[node*2+1].value;
    tree[node].sum = tree[node*2].sum + tree[node*2+1].sum;

    return ;
}

pair<ll,ll> queryRec(ll left,ll right,ll node,ll start,ll end){
    if(left>end || right<start) return {100001,0};
    if(left<=start && end<=right){
        return {tree[node].idx,tree[node].sum};
    }
    ll mid = (start + end) / 2;
    pair<ll,ll> leftVal = queryRec(left,right,node*2,start,mid);
    pair<ll,ll> rightVal = queryRec(left,right,node*2+1,mid+1,end);
    return {arr[leftVal.first] < arr[rightVal.first] ? leftVal.first : rightVal.first,leftVal.second + rightVal.second};
}

void divcon(ll start, ll end){
    if(start == end){
        pair<ll,ll> tmp = queryRec(start,end,1,1,N);
        result = max(result, arr[tmp.first]*tmp.second);
        return;
    }
    else{
        pair<ll,ll> Min_idx = queryRec(start,end,1,1,N);
        result = max(result, arr[Min_idx.first]*Min_idx.second);

        if(Min_idx.first == start){
            divcon(start+1,end);
        }else if(Min_idx.first == end){
            divcon(start,end-1);
        }else{
            divcon(start,Min_idx.first-1);
            divcon(Min_idx.first+1,end);
        }
    };
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++) cin>>arr[i];
    arr[100001] = 1000001;

    buildRec(1,1,N);
    divcon(1,N);
    cout<<result<<'\n';

    return 0;
}
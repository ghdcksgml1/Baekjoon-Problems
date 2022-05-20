// 언어 : C++ , (성공/실패) : 1/6 , 메모리 : 27808 KB , 시간 : 124ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 100001

using namespace std;

typedef long long ll;

struct Tree{
    pair<ll,ll> Lsum = {0,0};
    pair<ll,ll> Rsum = {0,0};
    pair<ll,ll> Maxsum = {0,0};
    pair<ll,ll> Sum = {0,0};
}tree[MAX*4];

ll arr[MAX];
ll N,Q,U,V;

ll cal(ll x,ll y){
    return (U*x + V*(y-1));
}

void buildRec(ll node,ll start,ll end){
    if(start == end){
        tree[node].Lsum = {arr[start],1};
        tree[node].Rsum = {arr[start],1};
        tree[node].Maxsum = {arr[start],1};
        tree[node].Sum = {arr[start],1};
        return ;
    }
    ll mid = (start + end) / 2;
    buildRec(node*2,start,mid);
    buildRec(node*2+1,mid+1,end);
    if(cal(tree[node*2].Lsum.first,tree[node*2].Lsum.second) > cal(tree[node*2].Sum.first + tree[node*2+1].Lsum.first, tree[node*2].Sum.second + tree[node*2+1].Lsum.second)){
        tree[node].Lsum = {tree[node*2].Lsum.first, tree[node*2].Lsum.second};
    }else{
        tree[node].Lsum = {tree[node*2].Sum.first + tree[node*2+1].Lsum.first, tree[node*2].Sum.second + tree[node*2+1].Lsum.second};
    }

    if(cal(tree[node*2+1].Rsum.first,tree[node*2+1].Rsum.second) > cal(tree[node*2+1].Sum.first + tree[node*2].Rsum.first, tree[node*2+1].Sum.second + tree[node*2].Rsum.second)){
        tree[node].Rsum = {tree[node*2+1].Rsum.first,tree[node*2+1].Rsum.second};
    }else{
        tree[node].Rsum = {tree[node*2+1].Sum.first + tree[node*2].Rsum.first, tree[node*2+1].Sum.second + tree[node*2].Rsum.second};
    }

    tree[node].Sum = {tree[node*2].Sum.first + tree[node*2+1].Sum.first, tree[node*2].Sum.second + tree[node*2+1].Sum.second};

    if(cal(tree[node*2].Maxsum.first,tree[node*2].Maxsum.second) > cal(tree[node*2+1].Maxsum.first,tree[node*2+1].Maxsum.second)){
        if(cal(tree[node*2].Maxsum.first,tree[node*2].Maxsum.second) > cal(tree[node*2].Rsum.first + tree[node*2+1].Lsum.first,tree[node*2].Rsum.second + tree[node*2+1].Lsum.second)){
            tree[node].Maxsum = {tree[node*2].Maxsum.first,tree[node*2].Maxsum.second};
        }else{
            tree[node].Maxsum = {tree[node*2].Rsum.first + tree[node*2+1].Lsum.first,tree[node*2].Rsum.second + tree[node*2+1].Lsum.second};
        }
    }else{
        if(cal(tree[node*2+1].Maxsum.first,tree[node*2+1].Maxsum.second) > cal(tree[node*2].Rsum.first + tree[node*2+1].Lsum.first,tree[node*2].Rsum.second + tree[node*2+1].Lsum.second)){
            tree[node].Maxsum = {tree[node*2+1].Maxsum.first,tree[node*2+1].Maxsum.second};
        }else{
            tree[node].Maxsum = {tree[node*2].Rsum.first + tree[node*2+1].Lsum.first,tree[node*2].Rsum.second + tree[node*2+1].Lsum.second};
        }
    }
}

Tree queryRec(ll left,ll right,ll node,ll start,ll end){
    if(left>end || right<start) {
        Tree tmp;
        if(U>0) {
            tmp.Lsum = {-1000, 0};
            tmp.Rsum = {-1000, 0};
            tmp.Sum = {-1000, 0};
            tmp.Maxsum = {-1000, 0};
        }else{
            tmp.Lsum = {1000, 0};
            tmp.Rsum = {1000, 0};
            tmp.Sum = {1000, 0};
            tmp.Maxsum = {1000, 0};
        }
        return tmp;
    }
    if(left<=start && end<=right){
        return tree[node];
    }
    ll mid = (start + end) / 2;
    Tree newTree;
    Tree leftTree = queryRec(left,right,node*2,start,mid);
    Tree rightTree = queryRec(left,right,node*2+1,mid+1,end);

    // Lsum
    if(cal(leftTree.Lsum.first,leftTree.Lsum.second) > cal(leftTree.Sum.first + rightTree.Lsum.first, leftTree.Sum.second + rightTree.Lsum.second)){
        newTree.Lsum = {leftTree.Lsum.first, leftTree.Lsum.second};
    }else{
        newTree.Lsum = {leftTree.Sum.first + rightTree.Lsum.first, leftTree.Sum.second + rightTree.Lsum.second};
    }

    // Rsum
    if(cal(rightTree.Rsum.first,rightTree.Rsum.second) > cal(rightTree.Sum.first + leftTree.Rsum.first, rightTree.Sum.second + leftTree.Rsum.second)){
        newTree.Rsum = {rightTree.Rsum.first,rightTree.Rsum.second};
    }else{
        newTree.Rsum = {rightTree.Sum.first + leftTree.Rsum.first, rightTree.Sum.second + leftTree.Rsum.second};
    }

    // Sum
    newTree.Sum = {leftTree.Sum.first + rightTree.Sum.first, leftTree.Sum.second + rightTree.Sum.second};

    // Maxsum
    if(cal(leftTree.Maxsum.first,leftTree.Maxsum.second) > cal(rightTree.Maxsum.first,rightTree.Maxsum.second)){
        if(cal(leftTree.Maxsum.first,leftTree.Maxsum.second) > cal(leftTree.Rsum.first + rightTree.Lsum.first,leftTree.Rsum.second + rightTree.Lsum.second)){
            newTree.Maxsum = {leftTree.Maxsum.first,leftTree.Maxsum.second};
        }else{
            newTree.Maxsum = {leftTree.Rsum.first + rightTree.Lsum.first,leftTree.Rsum.second + rightTree.Lsum.second};
        }
    }else{
        if(cal(rightTree.Maxsum.first,rightTree.Maxsum.second) > cal(leftTree.Rsum.first + rightTree.Lsum.first,leftTree.Rsum.second + rightTree.Lsum.second)){
            newTree.Maxsum = {rightTree.Maxsum.first,rightTree.Maxsum.second};
        }else{
            newTree.Maxsum = {leftTree.Rsum.first + rightTree.Lsum.first,leftTree.Rsum.second + rightTree.Lsum.second};
        }
    }
    return newTree;
}

void updateRec(ll target,ll value,ll node,ll start,ll end){
    if(target>end || target<start) return;
    if(start == end){
        tree[node].Lsum = {value,1};
        tree[node].Rsum = {value,1};
        tree[node].Maxsum = {value,1};
        tree[node].Sum = {value,1};
        return;
    }
    ll mid = (start + end) / 2;
    updateRec(target,value,node*2,start,mid);
    updateRec(target,value,node*2+1,mid+1,end);
    if(cal(tree[node*2].Lsum.first,tree[node*2].Lsum.second) > cal(tree[node*2].Sum.first + tree[node*2+1].Lsum.first, tree[node*2].Sum.second + tree[node*2+1].Lsum.second)){
        tree[node].Lsum = {tree[node*2].Lsum.first, tree[node*2].Lsum.second};
    }else{
        tree[node].Lsum = {tree[node*2].Sum.first + tree[node*2+1].Lsum.first, tree[node*2].Sum.second + tree[node*2+1].Lsum.second};
    }

    if(cal(tree[node*2+1].Rsum.first,tree[node*2+1].Rsum.second) > cal(tree[node*2+1].Sum.first + tree[node*2].Rsum.first, tree[node*2+1].Sum.second + tree[node*2].Rsum.second)){
        tree[node].Rsum = {tree[node*2+1].Rsum.first,tree[node*2+1].Rsum.second};
    }else{
        tree[node].Rsum = {tree[node*2+1].Sum.first + tree[node*2].Rsum.first, tree[node*2+1].Sum.second + tree[node*2].Rsum.second};
    }

    tree[node].Sum = {tree[node*2].Sum.first + tree[node*2+1].Sum.first, tree[node*2].Sum.second + tree[node*2+1].Sum.second};

    if(cal(tree[node*2].Maxsum.first,tree[node*2].Maxsum.second) > cal(tree[node*2+1].Maxsum.first,tree[node*2+1].Maxsum.second)){
        if(cal(tree[node*2].Maxsum.first,tree[node*2].Maxsum.second) > cal(tree[node*2].Rsum.first + tree[node*2+1].Lsum.first,tree[node*2].Rsum.second + tree[node*2+1].Lsum.second)){
            tree[node].Maxsum = {tree[node*2].Maxsum.first,tree[node*2].Maxsum.second};
        }else{
            tree[node].Maxsum = {tree[node*2].Rsum.first + tree[node*2+1].Lsum.first,tree[node*2].Rsum.second + tree[node*2+1].Lsum.second};
        }
    }else{
        if(cal(tree[node*2+1].Maxsum.first,tree[node*2+1].Maxsum.second) > cal(tree[node*2].Rsum.first + tree[node*2+1].Lsum.first,tree[node*2].Rsum.second + tree[node*2+1].Lsum.second)){
            tree[node].Maxsum = {tree[node*2+1].Maxsum.first,tree[node*2+1].Maxsum.second};
        }else{
            tree[node].Maxsum = {tree[node*2].Rsum.first + tree[node*2+1].Lsum.first,tree[node*2].Rsum.second + tree[node*2+1].Lsum.second};
        }
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>Q>>U>>V;
    for(ll i=1;i<=N;i++){
        cin>>arr[i];
    }

    buildRec(1,1,N);

    while(Q--){
        ll a,b,c; cin>>a>>b>>c;
        if(a==0){
            Tree tmp = queryRec(b,c,1,1,N);
//            cout<<tmp.Maxsum.first<<' '<<tmp.Maxsum.second<<'\n';
            ll result = U*tmp.Maxsum.first + V*(tmp.Maxsum.second - 1);
            cout<<result<<'\n';
        }else{
            updateRec(b,c,1,1,N);
        }
    }

    return 0;
}
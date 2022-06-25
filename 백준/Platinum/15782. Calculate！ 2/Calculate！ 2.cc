// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 100001

using namespace std;

struct Tree{
    int value = 0;
    int lazy = 0;
}tree[MAX * 4];

int N,M;
vector<int> adj[MAX];
int st[MAX], en[MAX];
bool visit[MAX];
int cnt = 0;

void propagation(int start, int end, int node)
{
    int lazy = tree[node].lazy;
    if(lazy){
        if((end-start+1)%2 == 1) tree[node].value ^= lazy;
        if(start != end){
            tree[node*2].lazy ^= lazy;
            tree[node*2+1].lazy ^= lazy;
        }
        tree[node].lazy = 0;
    }
}
void update(int start, int end, int node, int left, int right, int i_xor)
{
    propagation(start, end, node);
    if(end < left || right < start) return;
    if(left <= start && end <= right){
        if((end-start+1)%2 == 1) tree[node].value ^= i_xor; /// 홀수개이면
        if(start != end){
            tree[node*2].lazy ^= i_xor;
            tree[node*2+1].lazy ^= i_xor;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node*2, left, right, i_xor);
    update(mid+1, end, node*2+1, left, right, i_xor);

    tree[node].value = tree[node*2].value ^ tree[node*2+1].value;
}
int cal_xor(int start, int end, int node, int left, int right) /// xor 계산
{
    propagation(start, end, node);

    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node].value;
    int mid = (start + end) / 2;
    return cal_xor(start, mid, node*2, left, right) ^ cal_xor(mid+1, end, node*2+1, left, right);
}

//void propagation(int node,int start,int end){
//    if(tree[node].lazy != 0){
//        tree[node].value = (end-start+1)%2==0 ? tree[node].value : tree[node].value ^ tree[node].lazy;
//        if(start != end){
//            tree[node*2].lazy ^= tree[node].lazy;
//            tree[node*2+1].lazy ^= tree[node].lazy;
//        }
//        tree[node].lazy = 0;
//    }
//}
//
//void update(int left,int right,int node,int start,int end,int value){
//    propagation(node,start,end);
//    if(left>end || right<start) return;
//    if(left<=start && end<=right){
//        tree[node].lazy = (end-start+1)%2==0 ? tree[node].lazy : tree[node].lazy ^ value;
//        propagation(node,start,end);
//        return;
//    }
//    int mid = (start + end) / 2;
//    update(left,right,node*2,start,mid,value);
//    update(left,right,node*2+1,mid+1,end,value);
//    tree[node].value = tree[node*2].value ^ tree[node*2+1].value;
//}
//
//int query(int left,int right,int node,int start,int end){
//    propagation(node,start,end);
//    if(left>end || right<start) return 0;
//    if(left<=start && end<=right){
//        return tree[node].value;
//    }
//    int mid = (start + end) / 2;
//    return query(left,right,node*2,start,mid) ^
//            query(left,right,node*2+1,mid+1,end);
//}

void dfs(int x){
    st[x] = ++cnt;
    visit[x] = true;
    for(int next : adj[x]){
        if(visit[next]) continue;
        dfs(next);
    }
    en[x] = cnt;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    for(int i=0;i<N-1;i++){
        int tmp1,tmp2; cin>>tmp1>>tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }

    dfs(1);

    for(int i=1;i<=N;i++){
        int tmp; cin>>tmp;
        update(1,N,1,st[i],st[i],tmp);
    }

    while(M--){
        int t,x,y; cin>>t;

        if(t == 1){
            cin>>x;
            cout<<cal_xor(1,N,1,st[x],en[x])<<'\n';
        }else{
            cin>>x>>y;
            update(1,N,1,st[x],en[x],y);
        }
    }

    return 0;
}
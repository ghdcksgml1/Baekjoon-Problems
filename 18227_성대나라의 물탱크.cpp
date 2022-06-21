// 언어 : C++ , (성공/실패) : 1/2 , 메모리 : 33428 KB , 시간 : 236ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 200001

using namespace std;
typedef long long ll;

struct Tree{
    ll value = 0;
}tree[MAX*4];

ll N,C,Q;
vector<ll> adj[MAX];
ll st[MAX], en[MAX];
ll cnt = 0;
ll t[MAX];
bool visit[MAX];

void dfs(ll x,ll depth){
    visit[x] = true;
    st[x] = ++cnt;
    t[x] = depth;
    for(ll next : adj[x]){
        if(visit[next]) continue;
        dfs(next,depth+1);
    }
    en[x] = cnt;
}

void update(ll target,ll node,ll start,ll end,ll value){
    if(target>end || target<start) return;
    if(start == end){
        tree[node].value += value;
        return;
    }
    ll mid = (start + end) / 2;
    update(target,node*2,start,mid,value);
    update(target,node*2+1,mid+1,end,value);
    tree[node].value = tree[node*2].value + tree[node*2+1].value;
}

ll query(ll left,ll right,ll node,ll start,ll end){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right){
        return tree[node].value;
    }
    ll mid = (start + end) / 2;
    return query(left,right,node*2,start,mid) + query(left,right,node*2+1,mid+1,end);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>C;
    for(ll i=1;i<N;i++){
        ll tmp1,tmp2; cin>>tmp1>>tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }

    dfs(C,1);

    cin>>Q;
    while(Q--){
        ll a,b; cin>>a>>b;
        if(a == 1){
            update(st[b],1,1,N,1);
        }else{
            cout<<query(st[b],en[b],1,1,N)*t[b]<<'\n';
        }
    }

    return 0;
}
// 언어 : C++ , (성공/실패) : 1/3 , 메모리 : 2932 KB , 시간 : 924ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 3001
using namespace std;
typedef long long ll;

struct Node{
    ll x,y,w;
};

bool compare(Node a,Node b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

struct Tree{
    ll Lsum;
    ll Rsum;
    ll TotalSum;
    ll MaxSum;
}tree[MAX*4];

vector<Node> v;
vector<ll> xx;
vector<ll> yy;
vector<vector<Node>> yyy;

Tree update(ll target,ll value,ll node,ll start,ll end){
    if(target>end || target<start) return tree[node];
    if(start == end){
        tree[node].Lsum += value;
        tree[node].Rsum += value;
        tree[node].MaxSum += value;
        tree[node].TotalSum += value;
        return tree[node];
    }
    ll mid = (start + end) / 2;
    Tree left = update(target,value,node*2,start,mid);
    Tree right = update(target,value,node*2+1,mid+1,end);

    tree[node].Lsum = max(left.Lsum,left.TotalSum+right.Lsum);
    tree[node].Rsum = max(right.Rsum,right.TotalSum+left.Rsum);
    tree[node].TotalSum = left.TotalSum + right.TotalSum;
    tree[node].MaxSum = max({left.MaxSum,right.MaxSum,left.Rsum+right.Lsum});
    return tree[node];
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll N; cin>>N; v.resize(N);
    for(auto& i: v){
        cin>>i.x>>i.y>>i.w;
        xx.push_back(i.x);
        yy.push_back(i.y);
    }
    sort(xx.begin(), xx.end()); sort(yy.begin(), yy.end());
    xx.erase(unique(xx.begin(), xx.end()),xx.end());
    yy.erase(unique(yy.begin(), yy.end()),yy.end());

    yyy.resize(N);
    for(auto& i: v){
        i.x = lower_bound(xx.begin(), xx.end(),i.x) - xx.begin();
        i.y = lower_bound(yy.begin(), yy.end(),i.y) - yy.begin();
        swap(i.x,i.y);
        yyy[i.x].push_back({i.x,i.y,i.w});
    }
    sort(v.begin(), v.end(),compare);

    ll res = 0;

    for(ll i=0;i<yyy.size();i++){
        if(yyy[i].empty()) continue;
        memset(tree,0,sizeof(tree));
        for(ll j=i;j<yyy.size();j++){
            if(yyy[j].empty()) continue;
            for(ll k=0;k<yyy[j].size();k++){
                update(yyy[j][k].y,yyy[j][k].w,1,0,N-1);
            }
            res = max(res,tree[1].MaxSum);
        }
    }
    cout<<res<<'\n';

    return 0;
}
// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 28672 KB , 시간 : 136 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <math.h>

using namespace std;
typedef long long ll;
class Edge{
public:
    ll node[2];
    ll distance;
    Edge (ll a,ll b,ll distance){
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
};
vector<pair<ll,ll>> tmp[3];
vector<Edge> edge;
int parent[100001];

bool compare(pair<ll,ll> a,pair<ll,ll> b){
    return a.first > b.first;
}

bool compare1(Edge a,Edge b){
    return a.distance < b.distance;
}

int getParent(int parent[], int x){
    if(parent[x] == x) return x;
    return getParent(parent,parent[x]);
}

void unionParent(int parent[],int a,int b){
    a = getParent(parent,a);
    b = getParent(parent, b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

int findParent(int parent[],int a,int b){
    a = getParent(parent,a);
    b = getParent(parent, b);
    if(a==b) return 1;
    return 0;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        tmp[0].push_back({a,i});
        tmp[1].push_back({b,i});
        tmp[2].push_back({c,i});
    }
    sort(tmp[0].begin(),tmp[0].end(),compare);
    sort(tmp[1].begin(),tmp[1].end(),compare);
    sort(tmp[2].begin(),tmp[2].end(),compare);

    for(int i=0;i<n-1;i++){
        for(int j=0;j<3;j++){
            edge.push_back(Edge(tmp[j][i].second,tmp[j][i+1].second,abs(tmp[j][i].first-tmp[j][i+1].first)));
        }
    }

    sort(edge.begin(),edge.end(),compare1);

    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    ll cnt = 0;
    for(int i=0;i<edge.size();i++){
        if(!findParent(parent,edge[i].node[0],edge[i].node[1])){
            cnt += edge[i].distance;
            unionParent(parent,edge[i].node[0],edge[i].node[1]);
        }
    }

    cout<<cnt<<'\n';

    return 0;
}
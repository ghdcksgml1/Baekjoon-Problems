// 언어 : C++ , (성공/실패) : 1/8 , 메모리 : 26760 KB , 시간 : 144 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <math.h>

using namespace std;
typedef long long ll;
class Edge{
public:
    int node[2];
    ll distance;
    Edge (int a,int b,ll distance){
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
};
vector<pair<ll,ll>> tmp;
vector<Edge> edge;
int parent[1001];

bool compare(Edge a,Edge b){
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

    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        ll a,b;cin>>a>>b;
        tmp.push_back({a,b});
    }

    for(int i=0;i<N;i++){
        parent[i] = i;
    }

    for(int i=0;i<M;i++){
        ll a,b;cin>>a>>b;
        edge.push_back(Edge(a-1,b-1,0));
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) continue;
            ll x = (tmp[i].first - tmp[j].first)*(tmp[i].first - tmp[j].first);
            ll y = (tmp[i].second - tmp[j].second)*(tmp[i].second - tmp[j].second) + x;
            edge.push_back(Edge(i,j,y));
        }
    }

    sort(edge.begin(),edge.end(),compare);

    double cnt = 0.0;
    for(int i=0;i<edge.size();i++){
        if(!findParent(parent,edge[i].node[0],edge[i].node[1])){
            cnt += sqrt(edge[i].distance);
//            cout<<"x: "<<edge[i].node[0]<<", y: "<<edge[i].node[1]<<", dist: "<<edge[i].distance<<'\n';
            unionParent(parent,edge[i].node[0],edge[i].node[1]);
        }
    }
    printf("%.2lf",cnt);

    return 0;
}
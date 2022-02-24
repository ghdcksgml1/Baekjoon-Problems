// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 20976 KB , 시간 : 384ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

class Edge{
public:
    int node[2];
    int distance;
    Edge (int a,int b,int distance){
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
};
vector<Edge> edge;
int parent[100001];

bool compare(Edge a,Edge b){
    return a.distance < b.distance;
}

int getParent(int parent[],int x){
    if(parent[x] == x) return x;
    else return getParent(parent,parent[x]);
}

void unionParent(int parent[],int a,int b){
    a = getParent(parent,a);
    b = getParent(parent, b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

int findParent(int parent[],int a,int b){
    a = getParent(parent, a);
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
    for(int i=0;i<M;i++){
        int a,b,c; cin>>a>>b>>c;
        edge.push_back({a,b,c});
    }
    sort(edge.begin(),edge.end(),compare);

    for(int i=1;i<=N;i++){
        parent[i] = i;
    }

    int sum = 0;
    int last = 0;
    for(int i=0;i<edge.size();i++){
        if(!findParent(parent,edge[i].node[0],edge[i].node[1])){
            sum += edge[i].distance;
            last = edge[i].distance;
            unionParent(parent, edge[i].node[0],edge[i].node[1]);
        }
    }

    cout<<sum-last<<'\n';

    return 0;
}
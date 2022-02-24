// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 4460 KB , 시간 : 32ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;
class Edge{
public:
    int node[2];
    int distance;
    Edge(int a,int b,int distance){
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
};

int N,M;
vector<Edge> edge;
int parent[1001];

int getParent(int parent[], int x){
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a,int b){
    a = getParent(parent,a);
    b = getParent(parent, b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

int findParent(int parent[], int a,int b){
    a = getParent(parent,a);
    b = getParent(parent, b);
    if(a==b) return 1;
    return 0;
}

bool compare (Edge a,Edge b){
    return a.distance < b.distance;
}


int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge.push_back(Edge(a,b,c));
    }

    sort(edge.begin(),edge.end(),compare);
    for(int i=0;i<N;i++){
        parent[i] = i;
    }
    int sum = 0;
    for(int i=0;i<edge.size();i++){
        if(!findParent(parent,edge[i].node[0]-1,edge[i].node[1]-1)){
            sum += edge[i].distance;
            unionParent(parent,edge[i].node[0]-1,edge[i].node[1]-1);
        }
    }
    cout<<sum<<'\n';

    return 0;
}
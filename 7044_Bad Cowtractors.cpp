// 언어 : C++ , (성공/실패) : 1/4 , 메모리 : 2732 KB , 시간 : 4ms
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
bool visit[1001];

// 부모 리턴
int getParent(int parent[], int x){
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

// 부모를 공유한다.
void unionParent(int parent[], int a,int b){
    a = getParent(parent,a);
    b = getParent(parent, b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

// 공통 부모를 찾는다.
int findParent(int parent[], int a,int b){
    a = getParent(parent,a);
    b = getParent(parent, b);
    if(a==b) return 1;
    return 0;
}

bool compare (Edge a,Edge b){
    return a.distance > b.distance;
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

    sort(edge.begin(),edge.end(),compare); // 최소 스패닝 트리의 최댓값을 구하기 위해 distance가 높은 순으로 정렬
    for(int i=1;i<=N;i++){
        parent[i] = i;
    }
    int sum = 0;
    int cnt = 0; // cnt가 N-1이 나와야 모든 곳이 네트워크 연결된 것이다.
    for(int i=0;i<edge.size();i++){
        if(!findParent(parent,edge[i].node[0],edge[i].node[1])){
            sum += edge[i].distance;
            unionParent(parent,edge[i].node[0],edge[i].node[1]);
            cnt++;
        }
    }

    cout<<(cnt==N-1?sum:-1)<<'\n';

    return 0;
}
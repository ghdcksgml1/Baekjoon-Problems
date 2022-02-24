// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2548 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <math.h>

using namespace std;

class Edge{
public:
    float node[2];
    float distance;
    Edge (float a,float b,float distance){
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
};
vector<pair<float,float>> tmp;
vector<Edge> edge;
int parent[101];

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

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        float x,y;
        cin>>x>>y;
        tmp.push_back({x,y});
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            float distance = sqrt(pow(tmp[i].first - tmp[j].first, 2) + pow(tmp[i].second - tmp[j].second, 2));
            edge.push_back(Edge(i,j,distance));
        }
    }
    sort(edge.begin(),edge.end(),compare);

    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    float result = 0.0;
    for(int i=0;i<edge.size();i++){
        if(!findParent(parent,edge[i].node[0],edge[i].node[1])){
            result += edge[i].distance;
            unionParent(parent,edge[i].node[0],edge[i].node[1]);
        }
    }

    printf("%.2f",result);

    return 0;
}
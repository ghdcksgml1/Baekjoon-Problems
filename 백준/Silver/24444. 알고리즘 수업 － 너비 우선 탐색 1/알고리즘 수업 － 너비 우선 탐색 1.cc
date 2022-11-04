// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

vector<int> graph[100001];
bool visited[100001];
int result[100001];
queue<int> q;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M, R; cin>>N>>M>>R;

    for(int i=0; i<M; i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=0; i<=N; i++){
        sort(ALL(graph[i]));
    }

    memset(visited, 0, sizeof(visited));
    q.push(R);
    visited[R] = true;

    int cnt = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        result[cur] = cnt++;
        for(int neighbor : graph[cur]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    for(int i=1; i<=N; i++){
        cout<<result[i]<<"\n";
    }

    return 0;
}
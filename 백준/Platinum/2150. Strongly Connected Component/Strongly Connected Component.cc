// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

int id = 0;
vector<int> adj[10001];
int d[10001];
int sccNum = 1;
int sn[10001];
bool finished[10001];
stack<int> s;
vector<vector<int>> SCC;

int DFS(int c){
    d[c] = ++id;
    s.push(c);

    int result = d[c];
    for(int next : adj[c]){
        if(d[next] == 0) result = min(result, DFS(next));
        else if(!finished[next]) result = min(result, d[next]);
    }

    if(result == d[c]){
        vector<int> scc;
        while(1){
            int cur = s.top();
            s.pop();
            scc.push_back(cur);
            finished[cur] = true;
            sn[cur] = sccNum;
            if(cur == c) break;
        }
        sort(ALL(scc));
        SCC.push_back(scc);
        sccNum++;
    }

    return result;
}

bool compare(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int V,E; cin>>V>>E;
    for(int i=0; i<E; i++){
        int v,e; cin>>v>>e;
        adj[v].push_back(e);
    }

    for(int i=1; i<=V; i++){
        if(d[i] == 0) DFS(i);
    }

    sort(ALL(SCC), compare);

    cout<<SCC.size()<<"\n";
    for(vector<int> cur : SCC){
        for(int curr : cur){
            cout<<curr<<" ";
        }
        cout<<"-1\n";
    }

    return 0;
}
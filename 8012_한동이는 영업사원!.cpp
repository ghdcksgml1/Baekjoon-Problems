#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int N,M;
int parent[30001][18];
int depth[30001];
vector<int> adj[30001];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(parent,-1,sizeof(parent));
    memset(depth,-1,sizeof(depth));

    cin>>N;
    for(int i=1;i<N;i++){
        int n1,n2;
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    stack<int> st;
    st.push(1);
    depth[1] = 0;
    while(!st.empty()){
        int curr = st.top();st.pop();
        for(auto next : adj[curr]){
            if(depth[next] == -1){
                parent[next][0] = curr;
                depth[next] = depth[curr] + 1;
                st.push(next);
            }
        }
    }

    for(int j=0;j<17;j++){
        for(int i=2;i<=N;i++){
            if(parent[i][j] != -1){
                parent[i][j+1] = parent[parent[i][j]][j];
            }
        }
    }


    cin>>M;
    int prev = 1;
    int result = 0;
    for(int i=0;i<M;i++){
        int u = prev;
        int v;
        cin>>v;
        prev = v;

        result += (depth[u]+depth[v]);

        if(depth[u] < depth[v]) swap(u,v);
        int diff = depth[u] - depth[v];

        for(int j=0;diff;j++){
            if(diff%2==1) u = parent[u][j];
            diff /= 2;
        }

        if(u!=v){
            for(int j=17;j>=0;j--){
                if(parent[u][j]!=-1 && parent[u][j] != parent[v][j]){
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        result -= (depth[u]*2);
    }

    cout<<result<<'\n';

    return 0;
}
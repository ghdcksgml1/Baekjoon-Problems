#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int N,M;
int parent[40010][18];
int depth[40010];
int sum[40010];
vector<pair<int,int>> adj[40010];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(parent,-1,sizeof(parent));
    memset(depth,-1,sizeof(depth));

    cin>>N;
    for(int i=1;i<N;i++){
        int n1,n2,val;
        cin>>n1>>n2>>val;
        adj[n1].push_back({n2,val});
        adj[n2].push_back({n1,val});
    }

    stack<int> st;
    st.push(1);
    depth[1] = 0;
    while(!st.empty()){
        int cur = st.top(); st.pop();
        for(auto next : adj[cur]){
            if(depth[next.first] == -1){
                parent[next.first][0] = cur;
                depth[next.first] = depth[cur] + 1;
                sum[next.first] = sum[cur] + next.second;
                st.push(next.first);
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
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        int u_depth = sum[u];
        int v_depth = sum[v];

        if(depth[u] < depth[v]) swap(u,v);
        int diff = depth[u] - depth[v];

        for(int j=0;diff;j++){
            if(diff%2 == 1) u = parent[u][j];
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

        int result = 0;
        result += (u_depth - sum[u]);
        result += (v_depth - sum[u]);
        cout<<result<<'\n';
    }

    return 0;
}
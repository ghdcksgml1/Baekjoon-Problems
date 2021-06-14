#include <iostream>
#include <vector>
#define MAX 1010
using namespace std;
int n, N, M;
vector<int> v[MAX];
int d[MAX];
bool c[MAX];
bool dfs(int x) {
    for (int i = 0; i < v[x].size(); i++) {
        int t = v[x][i];
        if (c[t]) continue;
        c[t] = true;
        if (d[t] == 0 || dfs(d[t])) {
            d[t] = x;
            return true;
        }
    }
    return false;
}
void init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}
int main(void) {
    init();
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            int n_i;
            cin >> n_i;
            v[i].push_back(n_i);
        }
    }
    
    int cnt = 0;
    
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= 2; j++) {
            fill(c, c + MAX, false);
            if (dfs(i)) cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
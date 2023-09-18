// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

int dist[101];
int item_val[101];

vector<pii> adj[101];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++) {
        cin >> item_val[i];
    }

    while (r--) {
        int a, b, l;
        cin >> a >> b >> l;
        adj[a].push_back({b,l});
        adj[b].push_back({a,l});
    }

    int mx = 0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<101; j++) {
            dist[j] = MAX;
        }

        dist[i] = 0;
        pq.push({i, 0});

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if (dist[cur.xx] != cur.yy) continue;
            for (auto nxt : adj[cur.xx]) {
                if (dist[nxt.xx] <= dist[cur.xx] + nxt.yy) continue;
                dist[nxt.xx] = dist[cur.xx] + nxt.yy;
                pq.push({nxt.xx, dist[nxt.xx]});
            }
        }

        int sum = 0;
        for (int j=1; j<=n; j++) {
            if (dist[j] <= m) sum += item_val[j];
        }

        mx = max(mx, sum);
    }

    cout << mx << '\n';

    return 0;
}
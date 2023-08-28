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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int graph[1001][1001];
int dist[1001][1001];

vector<pii > ik_to; // 익은 토마토

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            graph[i][j] = tmp;

            if (tmp == 1) {
                ik_to.push_back({i, j});
            }

            if (tmp == -1) {
                dist[i][j] = -1;
            }
        }
    }

    queue<pii > Q;
    for (pii ik: ik_to) {
        // 넣고, 방문 표시
        Q.push({ik.xx, ik.yy});
        dist[ik.xx][ik.yy] = 1;
    }

    while (!Q.empty()) {
        pii cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.xx + dx[i];
            int ny = cur.yy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist[nx][ny] != 0) continue;

            int tmp = dist[cur.xx][cur.yy] + 1;
            if (dist[nx][ny] == 0) {
                dist[nx][ny] = tmp;
            } else {
                dist[nx][ny] = min(dist[nx][ny], tmp);
            }
            Q.push({nx, ny});
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == 0) {
                cout << -1 << '\n';
                return 0;
            }
            cnt = max(cnt, dist[i][j]);
        }
    }

    cout << cnt - 1 << '\n';

    return 0;
}
// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <queue>

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

int graph[502][502];
int board[502][502];
bool visited[502][502];
vector<pii > v;

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            graph[i][j] = tmp;
            board[i][j] = 0;
            visited[i][j] = false;
            if (tmp == 1) v.push_back({i, j});

//            cout << graph[i][j] << ' ';
        }
//        cout << '\n';
    }

    int cnt = 0;
    int mx = 0;

    for (pii tmp: v) {
        int X = tmp.first;
        int Y = tmp.second;
        if (visited[X][Y]) continue;

        visited[X][Y] = true;
        board[X][Y] = 1;
        queue<pii > Q;
        Q.push({X, Y});

        cnt++;
        int tmp_mx = 1;

        while (!Q.empty()) {
            pii cur = Q.front();
            Q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                // 패스 조건
                if (visited[nx][ny] || graph[nx][ny] == 0) continue;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                // 적합한 값이면 방문처리후 큐에 넣어주기~
                visited[nx][ny] = true;
                tmp_mx++;
                board[nx][ny] = board[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }

        mx = max(mx, tmp_mx);
    }

    cout << cnt << '\n' << mx << '\n';

    return 0;
}
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

int graph[101][101];
int board[101][101];
bool visited[101][101];

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < m; j++) {
            graph[i][j] = tmp[j] - '0';
            board[i][j] = 0;
            visited[i][j] = false;
        }
    }
    //////////

    queue<pii> Q;
    visited[0][0] = true;
    board[0][0] = 1;
    Q.push({0, 0});

    while (!Q.empty()) {
        pii cur = Q.front();
        Q.pop();

        if (cur.xx == (n - 1) && cur.yy == (m - 1)) {
            cout << board[cur.xx][cur.yy] << '\n';

            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.xx + dx[i];
            int ny = cur.yy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny] || graph[nx][ny] == 0) continue;

            board[nx][ny] = board[cur.xx][cur.yy] + 1;
            visited[nx][ny] = true;
            Q.push({nx,ny});
        }
    }

    return 0;
}
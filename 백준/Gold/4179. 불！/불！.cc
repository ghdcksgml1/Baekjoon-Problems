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

string graph[1001];
int fire[1001][1001];
int jihun[1001][1001];

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }

    queue<tuple<int, int, char>> Q;

    // 지훈이 넣기
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (graph[i][j] == 'J') {
                // 지훈이의 발자취는 jihun에 표시
                Q.push({i, j, 'J'});
                jihun[i][j] = 1;
            }

    // 불 넣기
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (graph[i][j] == 'F') {
                // 불은 fire에 표시
                Q.push({i, j, 'F'});
                fire[i][j] = 1;
            }

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        // 지훈이는 자기가 불에탔나 확인해야댐
        if (get<2>(cur) == 'J' && fire[get<0>(cur)][get<1>(cur)] == 1) continue;

        for (int i = 0; i < 4; i++) {
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];

            // 지훈이의 입장 : 가려는 곳이 불길이 퍼져있거나, 지훈이가 이미 다녀간 곳이거나, 벽이면, 범위를 벗어나면 탈출
            if (get<2>(cur) == 'J') {
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    cout << jihun[get<0>(cur)][get<1>(cur)] << '\n';
                    return 0;
                }
                if (fire[nx][ny] == 1 || jihun[nx][ny] >= 1 || graph[nx][ny] == '#') continue;

                jihun[nx][ny] = jihun[get<0>(cur)][get<1>(cur)] + 1;
                Q.push({nx, ny, 'J'});
            } else {
                // 불의 입장 : 가려는 곳이 불길이 이미 퍼진곳이거나, 범위를 벗어나거나, 벽이면
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (fire[nx][ny] == 1 || graph[nx][ny] == '#') continue;

                fire[nx][ny] = 1;
                Q.push({nx, ny, 'F'});
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
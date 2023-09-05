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

// 모든 점에서 상하좌우로

using namespace std;
typedef long long ll;

struct Node {
    int a;
    int b;
    int c;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int graph[11][11];
int visited[11][11];
int parent[11];

vector<Node> v;

int f_p(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = f_p(parent[a]);
}

void connect(int a, int b) {
    int tmp1 = f_p(a);
    int tmp2 = f_p(b);

    if (tmp1 < tmp2) parent[tmp2] = tmp1;
    else parent[tmp1] = tmp2;
}

bool tf(int a, int b) {
    int tmp1 = f_p(a);
    int tmp2 = f_p(b);

    return (tmp1 == tmp2);
}

bool cmp(Node n1, Node n2) {
    if (n1.c == n2.c) {
        return n1.a < n2.a;
    }

    return n1.c < n2.c;
}

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    int num = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                queue<pii > Q;
                Q.push({i, j});
                visited[i][j] = true;
                graph[i][j] = num;

                while (!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = cur.xx + dx[k];
                        int ny = cur.yy + dy[k];

                        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                        if (visited[nx][ny] || graph[nx][ny] == 0) continue;

                        graph[nx][ny] = num;
                        visited[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
                num++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] != 0) {
                int cur = graph[i][j];
                for (int k = 0; k < 4; k++) {
                    int cnt = 1;
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    while (!(nx < 0 || ny < 0 || nx >= N || ny >= M)) {
                        if (graph[nx][ny] > 0) {
                            if ((graph[nx][ny] != cur) && cnt > 2) {
                                v.push_back({cur, graph[nx][ny], cnt - 1});
                            }
                            break;
                        }

                        cnt++;
                        nx += dx[k];
                        ny += dy[k];
                    }
                }
            }
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < 11; i++) {
        parent[i] = i;
    }

    int ans = 0;
    for (Node t: v) {
        if (!tf(t.a, t.b)) {
            connect(t.a, t.b);
            ans += t.c;
        }
    }

    for (int i = 1; i < num; i++) {
        if (f_p(parent[i]) != 1){
            cout << "-1" << '\n';
            return 0;
        }
    }

    cout << ans << '\n';

    return 0;
}
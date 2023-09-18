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

int dx[4] = {1, -1, 0 ,0};
int dy[4] = {0, 0, 1, -1};

struct Node {
    int x;
    int y;
    int val;
};

struct compare {
    bool operator()(Node n1, Node n2) {
        return n1.val > n2.val;
    }
};

char graph[101][101];
vector<Node> adj[101][101];
int dist[101][101];

priority_queue<Node, vector<Node>, compare> pq;

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<101; i++) {
        for (int j=0; j<101; j++) {
            dist[i][j] = MAX;
        }
    }

    int N, M;
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k=0; k<4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (graph[nx][ny] == '1') {
                    adj[i][j].push_back({nx, ny, 1});
                } else {
                    adj[i][j].push_back({nx, ny, 0});
                }
            }
        }
    }

    pq.push({0, 0, 0});
    dist[0][0] = 0;

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.x][cur.y] != cur.val) continue;
        for (auto nxt : adj[cur.x][cur.y]) {
            if (dist[nxt.x][nxt.y] <= dist[cur.x][cur.y] + nxt.val) continue;
            dist[nxt.x][nxt.y] = dist[cur.x][cur.y] + nxt.val;
            pq.push({nxt.x, nxt.y, dist[nxt.x][nxt.y]});
        }
    }

    cout << dist[N-1][M-1] << '\n';

    return 0;
}
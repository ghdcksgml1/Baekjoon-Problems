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

struct Node {
    int x;
    int y;
    int z; // 들어온 방향 0: 가로, 1: 세로
    int val;
};

struct compare {
    bool operator()(Node n1, Node n2) {
        return n1.val > n2.val;
    }
};

// 하,상,우,좌
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<pii > C;
int dist[101][101];
char graph[101][101];

priority_queue<Node, vector<Node>, compare> pq;

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            dist[i][j] = MAX;
        }
    }

    int N, M;
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'C') C.push_back({i, j});
        }
    }

    pq.push({C[0].xx, C[0].yy, 0, 0});
    pq.push({C[0].xx, C[0].yy, 1, 0});
    pq.push({C[0].xx, C[0].yy, 2, 0});
    pq.push({C[0].xx, C[0].yy, 3, 0});
    dist[C[0].xx][C[0].yy] = 0;

    while (!pq.empty()) {
        auto cur = pq.top();
//        cout << "curX: " << cur.x << " ,curY: " << cur.y << " ,curVal:" << cur.val << '\n';
        pq.pop();
//        if (cur.x == C[1].xx && cur.y == C[1].yy) {
//            cout << cur.val << '\n';
//
//        }
        if (dist[cur.x][cur.y] != cur.val) continue;
        for (int k = 0; k < 4; k++) {
            if (cur.z == 0 && k == 1) continue;
            if (cur.z == 1 && k == 0) continue;
            if (cur.z == 2 && k == 3) continue;
            if (cur.z == 3 && k == 2) continue;
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (graph[nx][ny] == '*') continue;

            if ((cur.z == 2 || cur.z == 3) && (k == 0 || k == 1)) {
                if (dist[nx][ny] <= cur.val + 1) continue;
                dist[nx][ny] = cur.val + 1;
                pq.push({nx, ny, k, cur.val + 1});
            }
            else if ((cur.z == 0 || cur.z == 1) && (k == 2 || k == 3)) {
                if (dist[nx][ny] <= cur.val + 1) continue;
                dist[nx][ny] = cur.val + 1;
                pq.push({nx, ny, k, cur.val + 1});
            }
            else {
                if (dist[nx][ny] < cur.val) continue;
                dist[nx][ny] = cur.val;
                pq.push({nx, ny, k, cur.val});
            }
        }
    }

//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            cout << dist[i][j]  << " ";
//        }
//        cout << "\n";
//    }
    cout << dist[C[1].xx][C[1].yy] << '\n';

    return 0;
}


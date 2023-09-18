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
    char c;
};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

vector<string> graph;
int dist[51][51];
pii S;
pii D;
vector<pii> water;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int R, C;
    cin >> R >> C;

    for (int i=0; i<R; i++) {
        string tmp;
        cin >> tmp;
        graph.push_back(tmp);

        for (int j=0; j<C; j++) {
            if (tmp[j] == 'S') S = {i,j};
            if (tmp[j] == 'D') D = {i,j};
            if (tmp[j] == '*') water.push_back({i,j});
        }
    }

    queue<Node> Q;
    Q.push({S.first, S.second, 'S'});
    for (pii w : water) {
        Q.push({w.first, w.second, '*'});
    }

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        if (cur.x == D.first && cur.y == D.second) {
            cout << dist[cur.x][cur.y] << '\n';
            return 0;
        }

        for (int k=0 ; k<4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (cur.c == 'S') {
                if (graph[cur.x][cur.y] != 'S') continue;
                if (graph[nx][ny] == '*' || graph[nx][ny] == 'X' || graph[nx][ny] == 'S') continue;
                graph[nx][ny] = 'S';
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                Q.push({nx, ny, 'S'});

            } else if (cur.c == '*') {
                if (graph[nx][ny] == 'X' || graph[nx][ny] == '*' || graph[nx][ny] == 'D') continue;
                graph[nx][ny] = '*';
                Q.push({nx, ny, '*'});
            }

        }
    }

    cout << "KAKTUS" << '\n';

    return 0;
}
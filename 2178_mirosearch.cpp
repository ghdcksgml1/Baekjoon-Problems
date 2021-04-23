#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

char graph[101][101];
int dist[101][101];
int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int,int>> Q;

int main(void) {
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", graph[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == '1')
				dist[i][j] = -1;
		}
	}
	Q.push({ 0,0 });
	dist[0][0] = 1;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx,ny });
		}
	}
	printf("%d\n", dist[N-1][M-1]);
	return 0;
}
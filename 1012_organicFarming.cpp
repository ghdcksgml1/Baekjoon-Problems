#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int M, N;
int graph[50][50];
int dist[50][50];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> Q;

void bfs(int x, int y) {
	graph[x][y] = 0;
	Q.push({ x,y });
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (graph[nx][ny] == 0) continue;
			graph[nx][ny] = 0;
			Q.push({ nx,ny });
		}
	}
}

int main(void) {
	int T, K, X, Y;
	
	scanf("%d", &T);
	for (int ii = 0; ii < T; ii++) {
		int result = 0;
		scanf("%d %d %d", &M, &N, &K);
		for (int i = 0; i < K; i++) {
			scanf("%d", &X);
			scanf("%d", &Y);
			graph[X][Y] = 1;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][j] == 1) {
					bfs(i, j);
					result++;
				}
			}
		}
		printf("%d\n", result);
	}
	return 0;
}
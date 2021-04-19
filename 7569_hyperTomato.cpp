#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int M, N, H;
int graph[101][101][101];
int dist[101][101][101];
queue<pair<int, pair<int, int>>> Q;
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(void) {
	scanf("%d", &H);
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < H; k++) {
				scanf("%d", &graph[i][j][k]);
				if (graph[i][j][k] == 1)
					Q.push({ i,{j,k} });
				if (graph[i][j][k] == 0)
					dist[i][j][k] = -1;
			}
		}
	}
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second.first + dy[dir];
			int nz = cur.second.second + dz[dir];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= M || ny >= N || nz >= H) continue;
			if (dist[nx][ny][nz] >= 0) continue;
			dist[nx][ny][nz] = dist[cur.first][cur.second.first][cur.second.second] + 1;
			Q.push({ nx ,{ny,nz} });
		}
	}
	int ans = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < H; k++) {
				if (dist[i][j][k] == -1) {
					printf("-1\n");
					return 0;
				}
				ans = max(ans, dist[i][j][k]);
			}
		}
	}
	printf("%d\n",ans);
}
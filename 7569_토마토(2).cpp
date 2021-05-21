#include <iostream>
#include <queue>
using namespace std;
int M, N, H;
int graph;
int days[101][101][101];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
queue<pair<int, pair<int, int>>> q;
int main(void) {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> M >> N >> H;
	int cnt = 0; // 벽에 막혀있는 0을 찾기위한 변수
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> graph;
				if (graph == 0) {
					days[i][j][k] = -1;
					cnt++;
				}
				else if (graph == 1) {
					q.push({ i,{j,k} });
					cnt++;
				}
			}
		}
	}
	// DFS
	int maxx = 0;
	while (!q.empty()) {
		cnt--;
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second.first + dy[dir];
			int nz = cur.second.second + dz[dir];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= H || ny >= N || nz >= M)continue;
			if (days[nx][ny][nz] >= 0) continue;
			days[nx][ny][nz] = days[cur.first][cur.second.first][cur.second.second] + 1;
			maxx = days[nx][ny][nz];
			q.push({ nx,{ny,nz} });
		}
	}
	// cnt가 0이면 모든 토마토가 익은거지만,
	// 0이 아닐경우 익지 않은 토마토가 있는것
	if (cnt == 0) {
		cout << maxx << '\n';
	}
	else {
		cout << "-1" << '\n';
	}
	return 0;
}
#include <iostream>
#include <queue>
using namespace std;
int N, M;
char nm_arr[101][101];
int dist[101][101];
// 상하좌우 검색
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int,int>> q;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> nm_arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (nm_arr[i][j] == '1') {
				dist[i][j] = -1;
			}
		}
	}
	q.push({ 0,0 });
	dist[0][0] = 1;
	// BFS
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			// 범위를 벗어난 구간은 continue 시킨다.
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			// 벽: 0 , 이미지나간 구간 : >0 이므로
			if (dist[nx][ny] >= 0) continue;
			// 조건에 걸리지않은 값들은 거리를 +1 해준뒤 큐에 넣어준다.
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}
	cout << dist[N-1][M-1] << '\n';
}
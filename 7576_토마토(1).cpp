#include <iostream>
#include <queue>
using namespace std;
int N, M;
int graph[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main(void) {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0) {
				visited[i][j] = -1;
			}
			else if (graph[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}

	//DFS
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny] >= 0) continue;
			visited[nx][ny] = visited[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}
	int maxx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			maxx = max(maxx, visited[i][j]);
			if (visited[i][j] == -1) {
				cout << "-1" << '\n';
				return 0;
			}
		}
	}
	cout << maxx << '\n';
}

#include <iostream>
#include <queue>
using namespace std;
int N, M;
char graph[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> idx_1;
queue<pair<int,int>> q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
priority_queue<int, vector<int>, greater<int>> pq;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> graph[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == '1') { // º®ÀÌ¸é
				idx_1.push({ i,j });
			}
		}
	}
	while (!idx_1.empty()) {
		auto idx_cur = idx_1.front();
		idx_1.pop();
		graph[idx_cur.first][idx_cur.second] = '0';
		q.push({ 0,0 });
		visited[0][0] = 1;
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (graph[nx][ny] == '1' || visited[nx][ny] > 0) continue;
				visited[nx][ny] = visited[cur.first][cur.second] + 1;
				q.push({ nx,ny });
			}
		}
		int vvs = visited[N - 1][M - 1];
		if (vvs != 0) {
			pq.push(vvs);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = 0;
			}
		}
		graph[idx_cur.first][idx_cur.second] = '1';
	}
	if (!pq.empty()) {
		cout << pq.top() << '\n';
	}
	else {
		cout << "-1" << '\n';
	}
}
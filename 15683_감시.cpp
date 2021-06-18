#include <iostream>
#include <vector>
using namespace std;
int N, M;
int Min = 1000000000;
int graph[8][8];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int d_2[2] = { 1,-1 };
int dx_3[4] = { -1,1,1,-1 };
int dy_3[4] = { 1,1,-1,-1 };


vector<pair<int,pair<int, int>>> cctv;
void backtracking(int x) {
	if (x == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] == 0) cnt++;
			}
		}
		Min = min(Min, cnt);
		return;
	}
	int graph_cpy[8][8];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			graph_cpy[i][j] = graph[i][j];
		}
	}
	if (cctv[x].first == 1) {
		for (int dir = 0; dir < 4; dir++) {
			int nx = cctv[x].second.first;
			int ny = cctv[x].second.second;
			while (graph[nx][ny] != 6) {
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (graph[nx][ny] == 0) graph[nx][ny] = 7;
				nx += dx[dir];
				ny += dy[dir];
			}
			backtracking(x + 1);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					graph[i][j] = graph_cpy[i][j];
				}
			}
		}
	}
	if (cctv[x].first == 2) {
		for (int dir = 0; dir < 2; dir++) {
			int nx = cctv[x].second.first;
			int ny = cctv[x].second.second;
			while (graph[nx][ny] != 6) {
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (graph[nx][ny] == 0) graph[nx][ny] = 7;
				nx += d_2[dir];
			}
		}
		backtracking(x + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				graph[i][j] = graph_cpy[i][j];
			}
		}
		for (int dir = 0; dir < 2; dir++) {
			int nx = cctv[x].second.first;
			int ny = cctv[x].second.second;
			while (graph[nx][ny] != 6) {
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (graph[nx][ny] == 0) graph[nx][ny] = 7;
				ny += d_2[dir];
			}
		}
		backtracking(x + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				graph[i][j] = graph_cpy[i][j];
			}
		}
	}
	if (cctv[x].first == 3) {
		for (int dir = 0; dir < 4; dir++) {
			int nx = cctv[x].second.first;
			int ny = cctv[x].second.second;
			while (graph[nx][ny] != 6) {
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (graph[nx][ny] == 0) graph[nx][ny] = 7;
				nx += dx_3[dir];
			}
			nx = cctv[x].second.first;
			ny = cctv[x].second.second;
			while (graph[nx][ny] != 6) {
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (graph[nx][ny] == 0) graph[nx][ny] = 7;
				ny += dy_3[dir];
			}
			backtracking(x + 1);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					graph[i][j] = graph_cpy[i][j];
				}
			}
		}
	}
	if (cctv[x].first == 4) {
		for (int i = 0; i < 4; i++) {
			for (int dir = 0; dir < 4; dir++) {
				if (dir == i) continue;
				int nx = cctv[x].second.first;
				int ny = cctv[x].second.second;
				while (graph[nx][ny] != 6) {
					if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
					if (graph[nx][ny] == 0) graph[nx][ny] = 7;
					nx += dx[dir];
					ny += dy[dir];
				}
			}
			backtracking(x + 1);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					graph[i][j] = graph_cpy[i][j];
				}
			}
		}
	}
	if (cctv[x].first == 5) {
		for (int dir = 0; dir < 4; dir++) {
			int nx = cctv[x].second.first;
			int ny = cctv[x].second.second;
			while (graph[nx][ny] != 6) {
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
				if (graph[nx][ny] == 0) graph[nx][ny] = 7;
				nx += dx[dir];
				ny += dy[dir];
			}
		}
		backtracking(x + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				graph[i][j] = graph_cpy[i][j];
			}
		}
	}
}
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] >= 1 && graph[i][j] <= 5) {
				cctv.push_back({ graph[i][j], {i,j} });
			}
		}
	}
	backtracking(0);
	cout << Min << '\n';
}
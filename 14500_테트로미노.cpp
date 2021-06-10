#include <iostream>
#include <queue>
using namespace std;
int N, M;
int Max = 0;
int graph[500][500];
bool visit[500][500];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void dfs(int x,int y,int cnt,int sum) {
	if (cnt == 4) {
		Max = max(sum, Max);
		return;
	}
	if (x < 0 || y < 0 || x >= N || y >= M) return;
	if (!visit[x][y]) {
		visit[x][y] = true;
		sum += graph[x][y];
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			dfs(nx, ny, cnt + 1, sum);
		}
		visit[x][y] = false;
	}
	else {
		return;
	}
}
void anthoer_case(int i, int j) {
	int sum = graph[i][j];
	for (int dir = 0; dir < 4; dir++) {
		int nx = i + dx[dir];
		int ny = j + dy[dir];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
		sum += graph[nx][ny];
	}
	for (int dir = 0; dir < 4; dir++) {
		int nx = i + dx[dir];
		int ny = j + dy[dir];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
			Max = max(sum, Max);
		}
		else {
			sum -= graph[nx][ny];
			Max = max(sum, Max);
			sum += graph[nx][ny];
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
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dfs(i, j, 0, 0);
			anthoer_case(i, j);
		}
	}

	cout << Max << '\n';
}
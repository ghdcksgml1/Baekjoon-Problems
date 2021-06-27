#include <iostream>
#include <vector>
#define MAX 51
using namespace std;
int R, C, T;
int cnt = 0;
int graph[MAX][MAX];
int spread_graph[MAX][MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<pair<int, int>> air_cleaner;
void air_spread() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] > 0) {
				int dir_cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
					if (graph[nx][ny] == -1) continue;
					spread_graph[nx][ny] = spread_graph[nx][ny] + (graph[i][j] / 5);
					dir_cnt++;
				}
				graph[i][j] = graph[i][j] - (graph[i][j] / 5 * dir_cnt);
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			graph[i][j] += spread_graph[i][j];
			spread_graph[i][j] = 0;
		}
	}
}
void air_filter() {
	auto up_counterClockwise = air_cleaner[0]; // 위쪽 공기청정기의 좌표
	auto down_clockwise = air_cleaner[1]; // 아래쪽 공기청정기의 좌표

	// 위쪽
	int temp = graph[0][0];
	for (int i = 0; i < C; i++) {
		if (i == C - 1) {
			graph[0][i] = graph[1][i];
		}
		else {
			graph[0][i] = graph[0][i + 1];
		}
	}
	for (int i = 1; i <= up_counterClockwise.first; i++) {
		if (i == up_counterClockwise.first) {
			graph[i][C - 1] = graph[up_counterClockwise.first][C - 2];
		}
		else {
			graph[i][C - 1] = graph[i + 1][C - 1];
		}
	}
	for (int i = C - 2; i >= 0; i--) {
		if (i == 0) {
			graph[up_counterClockwise.first][i] = graph[up_counterClockwise.first - 1][i];
		}
		else {
			graph[up_counterClockwise.first][i] = graph[up_counterClockwise.first][i - 1];
		}
	}
	for (int i = up_counterClockwise.first - 1; i >= 1; i--) {
		if (i == 1) {
			graph[i][0] = temp;
		}
		else {
			graph[i][0] = graph[i - 1][0];
		}
	}
	// 아래쪽
	temp = graph[down_clockwise.first][C - 1];
	for (int i = C - 1; i >= 0; i--) {
		if (i == 0) {
			graph[down_clockwise.first][i] = graph[down_clockwise.first + 1][i];
		}
		else {
			graph[down_clockwise.first][i] = graph[down_clockwise.first][i - 1];
		}
	}
	for (int i = down_clockwise.first + 1; i < R; i++) {
		if (i == R - 1) {
			graph[i][0] = graph[i][1];
		}
		else {
			graph[i][0] = graph[i + 1][0];
		}
	}
	for (int i = 1; i < C; i++) {
		if (i == C - 1) {
			graph[R - 1][i] = graph[R - 2][i];
		}
		else {
			graph[R - 1][i] = graph[R - 1][i + 1];
		}
	}
	for (int i = R - 2; i >= down_clockwise.first+1; i--) {
		if (i == down_clockwise.first + 1) {
			graph[i][C - 1] = temp;
		}
		else {
			graph[i][C - 1] = graph[i - 1][C - 1];
		}
	}
	// -1은 0으로 원래 좌표에는 -1로
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] == -1) graph[i][j] = 0;
		}
	}
	graph[up_counterClockwise.first][up_counterClockwise.second] = -1;
	graph[down_clockwise.first][down_clockwise.second] = -1;
}
void init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	// 확산되는 양 = 미세먼지양/5
	// 남은 미세먼지의 양 = 미세먼지양 - 확산되는양 * 확산된방향의개수
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == -1) air_cleaner.push_back({ i,j });
		}
	}

	while (T--) {
		air_spread();
		air_filter();
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] != -1) cnt += graph[i][j];
		}
	}
	cout << cnt << '\n';

	return 0;
}
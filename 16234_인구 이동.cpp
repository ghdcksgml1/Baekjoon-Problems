#include <iostream>
#define MAX 50
using namespace std;
int N, L, R;
int graph[MAX][MAX];
int visit[MAX][MAX];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int sum_country = 0;
int sum_person = 0;
int cnt = 0;
int idx = 0;
int human_migration = 0; // 인구이동의 횟수
bool trigger=false; // DFS가 필요한지 아닌지 결정해주는 트리거

// DFS (Depth First Search)
void dfs(int x, int y) {
	if (!visit[x][y]) {
		visit[x][y] = idx;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visit[nx][ny]) continue;
			if (abs(graph[nx][ny] - graph[x][y]) >= L && abs(graph[nx][ny] - graph[x][y]) <= R) {
				dfs(nx, ny);
			}
		}
		sum_country += 1;
		sum_person += graph[x][y];
	}
}

void init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main(void) {
	init();
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	while (true) {
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				trigger = 0;
				sum_country = 0;
				sum_person = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (visit[nx][ny]) continue;
					if (abs(graph[nx][ny] - graph[i][j]) >= L && abs(graph[nx][ny] - graph[i][j]) <= R) {
						trigger = 1;
					}
				}
				if (trigger == 1) {
					idx++;
					dfs(i, j);
					for (int x = 0; x < N; x++) {
						for (int y = 0; y < N; y++) {
							if (visit[x][y] == idx) {
								graph[x][y] = sum_person / sum_country;
							}
						}
					}
				}
				if (sum_country == 0) cnt++;
			}
		}
		if (cnt == N * N) break;
		// visit 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = 0;
			}
		}
		human_migration++;
	}
	cout << human_migration << '\n';
}
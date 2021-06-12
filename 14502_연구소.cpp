#include <iostream>
#include <queue>
using namespace std;
int N, M;
int graph[8][8];
int copy_graph[8][8];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<pair<int, int>> v0;
queue<pair<int, int>> v2;
int Max = 0;
void BFS() {
	while (!v2.empty()) {
		auto cur = v2.front(); v2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (graph[nx][ny] == 1 || graph[nx][ny] == 2) continue;
			graph[nx][ny] = 2;
			v2.push({ nx,ny });
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) cnt++;
		}
	}
	Max = max(Max, cnt);
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
			copy_graph[i][j] = graph[i][j];
			if (graph[i][j] == 0) {
				v0.push_back({ i,j });
			}
			else if (graph[i][j] == 2) {
				v2.push({ i,j });
			}
		}
	}

	int v0_len = v0.size();
	// nC3을 구현하기 위해 3중 for문을 이용
	for (int i = 0; i < v0_len; i++) {
		for (int j = i+1; j < v0_len; j++) {
			for (int k = j+1; k < v0_len; k++) {
				graph[v0[i].first][v0[i].second] = 1; // 벽 1개
				graph[v0[j].first][v0[j].second] = 1; // 벽 2개
				graph[v0[k].first][v0[k].second] = 1; // 벽 3개
				BFS();
				// 원래의 graph값으로 되돌리기
				for (int ii = 0; ii < N; ii++) {
					for (int jj = 0; jj < M; jj++) {
						graph[ii][jj] = copy_graph[ii][jj];
						// v2는 현재 비어있는 상태이기 때문에, 다시 넣어준다.
						if(graph[ii][jj] == 2)
							v2.push({ ii,jj });
					}
				}
			}
		}
	}
	cout << Max << '\n';
}
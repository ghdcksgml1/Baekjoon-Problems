#include <iostream>
#include <queue>
using namespace std;
int N, M, cnt, cnt_1, cnt_day , all_0;
int graph[101][101];
int v_sign[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;
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
			if (graph[i][j] == 0) {
				all_0++;
			}
		}
	}
	if (all_0 == N * M) {
		cout << "0" << '\n' << "0" << '\n';
		return 0;
	}
	// BFS
	while(1) {
		cnt_day++; // 날짜세는 변수
		cnt = 0;  // 마지막날인지 확인하는 변수
		cnt_1 = 0; // 마지막 전날의 치즈개수를 세는 변수
		q.push({ 0,0 });
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (v_sign[nx][ny] == 1) continue; // 방문한곳이면 continue
				// 치즈가 있는 칸이지만, 방문하지 않았으면
				if (graph[nx][ny] == 1 && v_sign[nx][ny] == 0) {
					graph[nx][ny] = 0; // 다음날에는 치즈가 사라지므로 치즈가 없는칸 처리
					v_sign[nx][ny] = 1; // 방문표시
					cnt_1++; // 이 날에 치즈가 몇개 사라지는지 세기
				}
				else {
					// 치즈가 없는 칸이고, 방문하지 않은 칸이면
					if (graph[nx][ny] == 0 && v_sign[nx][ny] == 0) {
						v_sign[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				// 둘러 쌓여있어 0이지만 방문하지 못했을경우 방문처리해줌
				if (graph[i][j] == 0 && v_sign[i][j] == 0) v_sign[i][j] = 1;
				// 방문 안한곳 세기
				if (v_sign[i][j] == 0) {
					cnt++;
				}
				// 방문 초기화
				v_sign[i][j] = 0;
			}
		}
		if (cnt == 0) {
			cout << cnt_day << '\n'<< cnt_1 << '\n';
			return 0;
		}
	}
}
#include <iostream>
#include <queue>
using namespace std;
int N, M;
char graph[1001][1001];
bool visited[1001][1001][2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> graph[i];
	}
	
	// bfs
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0},{1,1} });
	visited[0][0][1] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		// 가장먼저 N x M에 도착한게 최솟값이므로
		if (x == N - 1 && y == M - 1) {
			cout << cnt << '\n';
			return 0;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			// 범위를 벗어나면 continue
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			// 벽 && 부수기 남은횟수 1
			if (graph[nx][ny] == '1' && wall == 1) {
				visited[nx][ny][wall] = true;
				q.push({ {nx,ny},{wall - 1,cnt + 1} });
			}
			// 길 && 방문하지않았을때
			if (graph[nx][ny] == '0' && !visited[nx][ny][wall]) {
				visited[nx][ny][wall] = true;
				q.push({ {nx,ny},{wall,cnt + 1} });
			}
			// 중요!!
			// visited에서 true와 false는 단순히 방문했는지 안했는지임
			// 벽 부수기 남은 횟수와는 관련없음
		}
	}
	cout << "-1" << '\n'; return 0;
}
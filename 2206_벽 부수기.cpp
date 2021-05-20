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
		// ������� N x M�� �����Ѱ� �ּڰ��̹Ƿ�
		if (x == N - 1 && y == M - 1) {
			cout << cnt << '\n';
			return 0;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			// ������ ����� continue
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			// �� && �μ��� ����Ƚ�� 1
			if (graph[nx][ny] == '1' && wall == 1) {
				visited[nx][ny][wall] = true;
				q.push({ {nx,ny},{wall - 1,cnt + 1} });
			}
			// �� && �湮�����ʾ�����
			if (graph[nx][ny] == '0' && !visited[nx][ny][wall]) {
				visited[nx][ny][wall] = true;
				q.push({ {nx,ny},{wall,cnt + 1} });
			}
			// �߿�!!
			// visited���� true�� false�� �ܼ��� �湮�ߴ��� ���ߴ�����
			// �� �μ��� ���� Ƚ���ʹ� ���þ���
		}
	}
	cout << "-1" << '\n'; return 0;
}
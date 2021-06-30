#include <iostream>
#include <queue>
#define MAX 51
using namespace std;
int N, M;
int graph[MAX][MAX];
int cpy_graph[MAX][MAX];
int visit[MAX][MAX];
int Max_dist;
int cnt = 0;
bool back_visit[11];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<pair<int, int>,int>> q;
vector<pair<int, int>> virus_location;
priority_queue<int, vector<int>, greater<int>> pq;
void BFS() {
	while (!q.empty()) {
		int curX = q.front().first.first; int curY = q.front().first.second; int curZ = q.front().second; q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visit[nx][ny] > 0 || graph[nx][ny] == 1) continue;
			// 비활성->활성이 된 바이러스
			if (graph[curX][curY] == 2 && curZ == 1) {
				// 다음 좌표가 활성인지 비활성인지 확인
				if (graph[nx][ny] == 2 && visit[nx][ny] == 0) {
					visit[nx][ny] = visit[curX][curY];
					q.push({ { nx,ny },1 });
					continue;
				}
				else {
					visit[nx][ny] = visit[curX][curY] + 2;
					q.push({ { nx,ny },0 });
					continue;
				}
			}
			// 비활성 바이러스면
			if (graph[nx][ny] == 2 && visit[nx][ny] == 0) {
				visit[nx][ny] = visit[curX][curY];
				q.push({ { nx,ny },1 });
				continue;
			}
			
			visit[nx][ny] = visit[curX][curY] + 1;
			q.push({ { nx,ny },0 });
		}
	}
}
void backTracking(int x,int prev) {
	if (x == M) {
		for (int i = 0; i < virus_location.size(); i++) {
			// 방문하고 있는 vector값이면
			if (back_visit[i]) {
				q.push({ { virus_location[i].first,virus_location[i].second },0 });
				visit[virus_location[i].first][virus_location[i].second] = 1;
			}
		}
		BFS();
		Max_dist = 0;
		for (int cpy_i = 0; cpy_i < N; cpy_i++) {
			for (int cpy_j = 0; cpy_j < N; cpy_j++) {
				Max_dist = max(Max_dist, visit[cpy_i][cpy_j]);
			}
		}
		for (int cpy_i = 0; cpy_i < N; cpy_i++) {
			for (int cpy_j = 0; cpy_j < N; cpy_j++) {
				// 방문하지 않았는데 벽이 아니라면
				if (visit[cpy_i][cpy_j] == 0 && graph[cpy_i][cpy_j] != 1) {
					Max_dist = -1;
				}
				visit[cpy_i][cpy_j] = 0;
			}
		}

		if (Max_dist != -1) {
			cnt++;
			pq.push(Max_dist);
			
		}
		return;
	}
	// 조합 nCr
	for (int i = prev; i < virus_location.size(); i++) {
		back_visit[i] = true;
		backTracking(x + 1, i + 1);
		back_visit[i] = false;
	}
}
void init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			cpy_graph[i][j] = graph[i][j];
			if (graph[i][j] == 2) {
				virus_location.push_back({ i,j });
			}
		}
	}
	
	backTracking(0, 0);

	if (cnt != 0) {
		cout << pq.top() - 1 << '\n';
	}
	else {
		cout << "-1" << '\n';
	}
	
	return 0;
}
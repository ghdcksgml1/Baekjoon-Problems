#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 21
using namespace std;
int N;
int graph[MAX][MAX];
int visit[MAX][MAX];
int dist = 0;
int baby_shark_size = 2;
int baby_shark_feed = 0;
int baby_shark_distance = 0;
// 상, 좌, 하, 우 순으로
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

vector<pair<int, pair<int, int>>> v;
queue<pair<int, int>> baby_shark_location;
void bfs(int x, int y) {
	dist = 1000000000;
	v.clear();
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		int X = q.front().first; int Y = q.front().second; q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = X + dx[dir]; int ny = Y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visit[nx][ny] == 0 && baby_shark_size >= graph[nx][ny]) {
				visit[nx][ny] = visit[X][Y] + 1;
				if (graph[nx][ny] > 0 && (graph[nx][ny] < baby_shark_size)) {
					if (dist >= visit[nx][ny]) {
						dist = visit[nx][ny];
						v.push_back({ dist,{ nx,ny } });
					}
				}
				q.push({ nx,ny });
			}
			
		}
	}
	// 가장 가깝고, 가장 위에 있고, 가장 왼쪽에 있는 물고기를 선정하는과정
	if (!v.empty()) {
		sort(v.begin(), v.end());
		auto cur = v[0];
		int X = cur.second.first; int Y = cur.second.second;
		graph[X][Y] = 0;
		baby_shark_feed++;
		if (baby_shark_feed == baby_shark_size) {
			baby_shark_feed = 0;
			baby_shark_size++;
		}
		baby_shark_distance += cur.first;
		baby_shark_location.push({ X,Y });
	}
}
void init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	// 1. queue에 아기상어의 좌표를 넣는다. 그래프 상의 아기상어의 값을 0으로 바꾼다.
	// 2. bfs를 통해 아기상어가 먹을 수 있는 물고기 중 가장 가까운 물고기 한테간다.
	// 3. 물고기를 먹으면, graph에서 물고기를 지우고, 아기 상어가 먹은 양에 +1 해준다.
	// 4. 만약 아기 상어가 먹은 양이 아기상어의 크기와 같다면, 먹은양을 0으로 초기화하고, 
	//    아기상어의 크기를 +1해준다.
	// 5. 아기상어의 좌표를 먹이를 먹은 곳의 좌표로 바꿔준다.

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 9) {
				baby_shark_location.push({ i,j });
				graph[i][j] = 0;
			}
		}
	}
	while (!baby_shark_location.empty()) {
		auto cur = baby_shark_location.front(); baby_shark_location.pop();
		bfs(cur.first, cur.second);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = 0;
			}
		}
	}
	cout << baby_shark_distance << '\n';
}
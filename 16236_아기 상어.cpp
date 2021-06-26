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
// ��, ��, ��, �� ������
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
	// ���� ������, ���� ���� �ְ�, ���� ���ʿ� �ִ� ����⸦ �����ϴ°���
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
	// 1. queue�� �Ʊ����� ��ǥ�� �ִ´�. �׷��� ���� �Ʊ����� ���� 0���� �ٲ۴�.
	// 2. bfs�� ���� �Ʊ�� ���� �� �ִ� ����� �� ���� ����� ����� ���װ���.
	// 3. ����⸦ ������, graph���� ����⸦ �����, �Ʊ� �� ���� �翡 +1 ���ش�.
	// 4. ���� �Ʊ� �� ���� ���� �Ʊ����� ũ��� ���ٸ�, �������� 0���� �ʱ�ȭ�ϰ�, 
	//    �Ʊ����� ũ�⸦ +1���ش�.
	// 5. �Ʊ����� ��ǥ�� ���̸� ���� ���� ��ǥ�� �ٲ��ش�.

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
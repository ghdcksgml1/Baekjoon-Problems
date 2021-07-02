#include <iostream>
#include <vector>
#define MAX 13
using namespace std;
int N, K;
int coord_x, coord_y, dir, num=1;
int graph[MAX][MAX]; // ü����
int visit[MAX][MAX]; // ü���ǿ� ��ġ���ִ� ���� ����
int blue_cnt = 0;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
vector<pair<pair<int,int>,pair<int,int>>> coord_K;

void white(int index, int curX, int curY, int curDir, int curNum);
void red(int index, int curX, int curY, int curDir, int curNum);
void blue(int index, int curX, int curY, int curDir, int curNum);

void init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main(void) {
	init();
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			// 0: ��� , 1: ������ , 2: �Ķ���
			cin >> graph[i][j];
		}
	}
	for (int i = 1; i <= K; i++) {
		cin >> coord_x >> coord_y >> dir;
		// 1: �� , 2: �� , 3: �� , 4: �Ʒ�
		coord_K.push_back({ { num, dir-1 }, { coord_x,coord_y } });
		visit[coord_x][coord_y] = 1;
	}
	
	int cnt = 0;
	while (++cnt<=1000) {
		for (int i = 0; i < K; i++) {
			int curX = coord_K[i].second.first; int curY = coord_K[i].second.second;
			int curDir = coord_K[i].first.second; int curNum = coord_K[i].first.first;

			blue_cnt = 0;
			int nx = curX + dx[curDir];
			int ny = curY + dy[curDir];
			// ü������ ������ ��� ���
			if (nx <= 0 || ny <= 0 || nx > N || ny > N) {
				blue(i, curX, curY, curDir, curNum);
			}
			// ü���� = ���
			else if (graph[nx][ny] == 0) {
				white(i, curX, curY, curDir, curNum);
			}
			// ü���� = ������
			else if (graph[nx][ny] == 1) {
				red(i, curX, curY, curDir, curNum);
			}
			// ü���� = �Ķ���
			else if (graph[nx][ny] == 2) {
				blue(i, curX, curY, curDir, curNum);
			}

			// ���� 4���̻� ���̸� ����
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (visit[i][j] >= 4) {
						cout << cnt << '\n';
						return 0;
					}
				}
			}
		}
		
	}

	cout << "-1" << '\n';

	return 0;
}

void white(int index, int curX, int curY, int curDir, int curNum) {
	int nx = curX + dx[curDir];
	int ny = curY + dy[curDir];
	if (nx <= 0 || ny <= 0 || nx > N || ny > N) {
		blue(index, curX, curY, curDir, curNum);
		return;
	}

	if (visit[curX][curY] == 1) {
		visit[curX][curY]--; visit[nx][ny]++;
		curNum = visit[nx][ny];
		coord_K[index] = { { curNum, curDir }, { nx,ny } };
	}
	else {
		int visited = visit[nx][ny] + 1;
		for (int i = 0; i < coord_K.size(); i++) {
			if (coord_K[i].second.first == curX && coord_K[i].second.second == curY) {
				if (coord_K[i].first.first >= curNum) {
					visit[curX][curY]--; visit[nx][ny]++;
					int newNum = visited + (coord_K[i].first.first - curNum);
					coord_K[i] = { { newNum, coord_K[i].first.second }, { nx,ny } };
				}
			}
		}
	}

}

void red(int index, int curX, int curY, int curDir, int curNum) {
	int nx = curX + dx[curDir];
	int ny = curY + dy[curDir];
	if (nx <= 0 || ny <= 0 || nx > N || ny > N) {
		blue(index, curX, curY, curDir, curNum);
		return;
	}
	if (visit[curX][curY] == 1) {
		visit[curX][curY]--; visit[nx][ny]++;
		coord_K[index] = { { visit[nx][ny], curDir }, { nx,ny } };
	}
	else {
		int old_visited = visit[curX][curY] - curNum;
		int visited = visit[nx][ny] + 1;
		for (int i = 0; i < coord_K.size(); i++) {
			if (coord_K[i].second.first == curX && coord_K[i].second.second == curY) {
				if (coord_K[i].first.first >= curNum) {
					visit[curX][curY]--; visit[nx][ny]++;
					int newNum = visited + old_visited - (coord_K[i].first.first - curNum);
					coord_K[i] = { { newNum, coord_K[i].first.second }, { nx,ny } };
				}
			}
		}
	}
}

void blue(int index, int curX, int curY, int curDir, int curNum) {
	int oldDir = curDir;
	blue_cnt++;
	// blue �Լ��� 2���̻� ȣ��Ǵ� ����
	// ü������ ����� ���ۿ� �����Ƿ�
	if (blue_cnt == 2) return;
	if (curDir == 0) curDir = 1;
	else if (curDir == 1) curDir = 0;
	else if (curDir == 2) curDir = 3;
	else if (curDir == 3) curDir = 2;

	int nx = curX + dx[curDir];
	int ny = curY + dy[curDir];
	coord_K[index] = { { curNum, curDir }, { curX,curY } };
	if (nx <= 0 || ny <= 0 || nx > N || ny > N) {
		blue(index, curX, curY, oldDir, curNum);
		return;
	}
	if (graph[nx][ny] == 0) {
		white(index, curX, curY, curDir, curNum);
	}
	if (graph[nx][ny] == 1) {
		red(index, curX, curY, curDir, curNum);
	}
	
}

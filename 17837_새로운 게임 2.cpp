#include <iostream>
#include <vector>
#define MAX 13
using namespace std;
int N, K;
int coord_x, coord_y, dir, num=1;
int graph[MAX][MAX]; // 체스판
int visit[MAX][MAX]; // 체스판에 위치해있는 말의 개수
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
			// 0: 흰색 , 1: 빨간색 , 2: 파란색
			cin >> graph[i][j];
		}
	}
	for (int i = 1; i <= K; i++) {
		cin >> coord_x >> coord_y >> dir;
		// 1: 오 , 2: 왼 , 3: 위 , 4: 아래
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
			// 체스판이 범위를 벗어날 경우
			if (nx <= 0 || ny <= 0 || nx > N || ny > N) {
				blue(i, curX, curY, curDir, curNum);
			}
			// 체스판 = 흰색
			else if (graph[nx][ny] == 0) {
				white(i, curX, curY, curDir, curNum);
			}
			// 체스판 = 빨간색
			else if (graph[nx][ny] == 1) {
				red(i, curX, curY, curDir, curNum);
			}
			// 체스판 = 파란색
			else if (graph[nx][ny] == 2) {
				blue(i, curX, curY, curDir, curNum);
			}

			// 말이 4개이상 쌓이면 종료
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
	// blue 함수가 2번이상 호출되는 경우는
	// 체스판을 벗어나는 경우밖에 없으므로
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

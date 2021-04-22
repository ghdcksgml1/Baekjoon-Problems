#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

char graph[1001][1001];
int check[1001][1001];
int check2[1001][1001];
int R, C;
queue<pair<int,int>> q1;
queue<pair<int,int>> q2;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main(void) {
	scanf("%d", &R);
	scanf("%d", &C);
	for (int i = 0; i < R; i++) {
		scanf("%s", graph[i]);
	}
	// °ª ³Ö±â
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] == 'J') {
				check[i][j] = 1;
				check2[i][j] = -1;
				q1.push({ i,j });
			}
			if (graph[i][j] == 'F') {
				q2.push({ i,j });
				check[i][j] = 0;
				check2[i][j] = 1;
			}
			if (graph[i][j] == '.') {
				check[i][j] = -1;
				check2[i][j] = -1;
			}
			if (graph[i][j] == '#') {
				check[i][j] = 0;
				check2[i][j] = 0;
			}
		}
	}
	while (!q2.empty()) {
		auto cur2 = q2.front(); q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur2.first + dx[dir];
			int ny = cur2.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			if (check2[nx][ny] >= 0) continue;
			check2[nx][ny] = check2[cur2.first][cur2.second] + 1;
			q2.push({ nx,ny });
		}
	}
	while (!q1.empty()) {
		auto cur1 = q1.front(); q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur1.first + dx[dir];
			int ny = cur1.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
				cout << check[cur1.first][cur1.second];
				return 0;
			}
			if (check[nx][ny] >= 0) continue;
			if (check2[nx][ny]!=-1 && check2[nx][ny] <= check[cur1.first][cur1.second] + 1)continue;
			check[nx][ny] = check[cur1.first][cur1.second] + 1;
			q1.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}
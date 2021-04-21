#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <malloc.h>

using namespace std;

int L, R, C;
queue<pair<int, pair<int, int>>> Q;
char graph[30][30][30];
int dist[30][30][30];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
// ('#' ASCII : 35) , ('.' ASCII : 46) , ('E' ASCII : 69) , ('S' ASCII : 83)
int main(void) {
	while (scanf("%d %d %d", &L, &R, &C)) {
		if (L == 0 && R == 0 && C == 0) break;
		int isE = 0;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				scanf("%s", &graph[i][j]);
			}
		}
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					if (graph[i][j][k] == 'S') {
						dist[i][j][k] = 1;
						Q.push({ i,{j,k} });
					}
					if (graph[i][j][k] == '.')
						dist[i][j][k] = -1;
					if (graph[i][j][k] == 'E')
						dist[i][j][k] = -69;
					
					// dist가 음수로 바뀔일이 없으므로 69보단 -69로 설정
				}
			}
		}
		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			for (int dir = 0; dir < 6; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second.first + dy[dir];
				int nz = cur.second.second + dz[dir];
				if (nx < 0 || ny < 0 || nz < 0 || nx >= L || ny >= R || nz >= C) continue;
				if (dist[nx][ny][nz] == -69) {
					printf("Escaped in %d minute(s).\n", dist[cur.first][cur.second.first][cur.second.second]);
					isE = 1;
					break;
				}
				if (dist[nx][ny][nz] >= 0) continue;
				dist[nx][ny][nz] = dist[cur.first][cur.second.first][cur.second.second] + 1;
				Q.push({ nx,{ny,nz} });
			}
			
		}
		if (isE != 1) {
			printf("Trapped!\n");
		}
	}
}
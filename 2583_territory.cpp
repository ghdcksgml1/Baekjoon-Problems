#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int graph[100][100];
int M, N, K;
int countt = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> Q;
priority_queue<int, vector<int>, greater<int>> pq;

void dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M) return;
	if (graph[x][y] == 0) {
		graph[x][y] = 1;
		countt++;
		dfs(x+1, y);
		dfs(x-1, y);
		dfs(x, y+1);
		dfs(x, y-1);
	}
	if (graph[x][y] == 1) return;
}

int main(void) {
	
	int X1, X2, Y1, Y2;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
		for (int ii = X1; ii < X2; ii++) {
			for (int jj = Y1; jj < Y2; jj++) {
				graph[jj][ii] = 1;
			}
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) {
				result++;
				countt = 0;
				dfs(i, j);
				pq.push(countt);
			}
		}
	}
	printf("%d\n", result);
	while (!pq.empty()) {
		printf("%d ", pq.top());
		pq.pop();
	}
	return 0;
}
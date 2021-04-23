#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N, L;
int graph[100][100];
int check[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
priority_queue<int> pq;
priority_queue<int> pq2;

void dfs(int x, int y, int size) {
	if (x < 0 || y < 0 || x >= N || y >= N) return;
	if (check[x][y] == 1) return;
	if (graph[x][y] >= size) {
		check[x][y] = 1;
		dfs(x+1, y, size);
		dfs(x-1, y, size);
		dfs(x, y+1, size);
		dfs(x, y-1, size);
		return;
	}
	return;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
			pq.push(graph[i][j]);
		}
	}

	int max = pq.top();
	int result = 0;
	for (int k = 1; k <= max; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][j] >= k && check[i][j]==0) {
					dfs(i, j, k);
					result++;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				check[i][j] = 0;
			}
		}
		pq2.push(result);
		result = 0;
	}
	printf("%d\n", pq2.top());
	return 0;
}
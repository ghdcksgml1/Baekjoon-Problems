#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, E;
int d[3][801];
vector<pair<int, int>> a[801];
int INF = 1000000000;

void dijkstra(int start,int index) {
	d[index][start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (d[index][current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			int next = a[current][i].second;
			int nextDistance = distance + a[current][i].first;
			if (d[index][next] > nextDistance) {
				d[index][next] = nextDistance;
				pq.push({ -nextDistance,next });
			}
		}
	}
}

int main(void) {
	int n1, n2, n3;
	int v1, v2;
	int result = 0;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &n1, &n2, &n3);
		a[n1].push_back({ n3,n2 });
		a[n2].push_back({ n3,n1 });
	}
	cin >> v1 >> v2;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= N; j++) {
			d[i][j] = INF;
		}
	}
	dijkstra(1, 0);
	dijkstra(v1, 1);
	dijkstra(v2, 2);
	result += d[1][v2];
	int numberV1 = d[0][v1] + d[2][N];
	int numberV2 = d[0][v2] + d[1][N];
	if (numberV1 < numberV2) {
		result += numberV1;
	}
	else {
		result += numberV2;
	}

	if (d[0][N] == INF || d[1][N] == INF || d[2][N] == INF) {
		printf("-1\n");
	}
	else {
		printf("%d\n", result);
	}
}
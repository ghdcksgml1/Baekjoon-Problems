#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int V, E;
int K;
int u, v, w;
vector<pair<int, int>> a[20001];
int d[20001];
int INF = 1000000000;

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			int next = a[current][i].second;
			int nextDistance = distance + a[current][i].first;
			if (d[next] > nextDistance) {
				d[next] = nextDistance;
				pq.push({ -nextDistance,next });
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &V, &E);
	scanf("%d",&K);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		a[u].push_back(make_pair(w, v));
	}
	for (int i = 1; i <= V; i++) {
		d[i] = INF;
	}
	dijkstra(K);
	for (int i = 1; i <= V; i++) {
		if (d[i] != INF) {
			printf("%d\n", d[i]);
		}
		else {
			printf("INF\n");
		}
	}
}
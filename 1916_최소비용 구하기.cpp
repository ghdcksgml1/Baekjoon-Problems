#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> a[1001];
int d[1001];
int INF = 1000000000;

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
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
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
}

int main(void) {
	int n1, n2, n3;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &n1, &n2, &n3);
		a[n1].push_back({ n3,n2 });
	}
	cin >> n1 >> n2;
	dijkstra(n1);
	printf("%d\n", d[n2]);
}
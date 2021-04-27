#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, X;
int d[1001];
int result[1001];
int INF = 1000000000;
vector<pair<int, int>> a[1001];

void dijkstra(int start) {
	d[start]=0;
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
	int n1, n2, n3;
	cin >> N >> M >> X;
	
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &n1, &n2, &n3);
		a[n1].push_back(make_pair(n3, n2));
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			d[j] = INF;
		}
		if (i == X) {
			dijkstra(i);
			for (int k = 1; k <= N; k++) {
				result[k] += d[k];
			}
		}
		else {
			dijkstra(i);
			result[i] += d[X];
		}
	}
	priority_queue<int> pq2;
	for (int i = 1; i <= N; i++) {
		pq2.push(result[i]);
	}
	printf("%d\n", pq2.top());
}
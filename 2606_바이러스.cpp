#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;
vector<int> a[101];
bool d[101];

int main(void) {
	int n1, n2;
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &n1, &n2);
		a[n1].push_back(n2);
		a[n2].push_back(n1);
	}
	queue<int> q;
	int result = 0;
	q.push(1);
	d[1] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int dir = 0; dir < a[cur].size(); dir++) {
			int y = a[cur][dir];
			if (!d[y]) {
				q.push(y);
				result++;
				d[y] = 1;
			}
		}
	}
	printf("%d\n", result);
}
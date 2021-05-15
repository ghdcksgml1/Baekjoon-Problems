#include <iostream>
#include <queue>
using namespace std;
int N, M, V;
priority_queue<int,vector<int>,greater<int>> v[1001];
priority_queue<int, vector<int>, greater<int>> v2[1001];
queue<int> q;
bool visited[1001];
bool visited2[1001];
void dfs(int x) {
	if (!visited[x]) {
		visited[x] = true;
		cout << x << ' ';
		while(!v[x].empty()) {
			int cur = v[x].top(); v[x].pop();
			dfs(cur);
		}
	}
}
void bfs(int x) {
	q.push(x);
	visited2[x] = true;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << ' ';
		while (!v2[cur].empty()) {
			int y = v2[cur].top(); v2[cur].pop();
			if (!visited2[y]) {
				q.push(y);
				visited2[y] = true;
			}
		}
	}
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n1, n2;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2;
		v[n1].push(n2);
		v[n2].push(n1);

		v2[n1].push(n2);
		v2[n2].push(n1);
	}
	dfs(V);
	cout << '\n';
	bfs(V);
	cout << '\n';
}
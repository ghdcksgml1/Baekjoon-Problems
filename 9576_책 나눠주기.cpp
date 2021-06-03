#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;
int T, N, M;
vector<int> book[MAX];
int d[MAX];
bool visited[MAX];

bool dfs(int x) {
	for (int i = 0; i < book[x].size(); i++) {
		int cur = book[x][i];
		if (visited[cur]) continue;
		visited[cur] = true;
		if (d[cur]==0 || dfs(d[cur])) {
			d[cur] = x;
			return true;
		}
	}
	return false;
}

void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> T;
	while(T--) {
		cin >> N >> M;
		for (int i = 1; i <= M; i++) {
			int n1, n2;
			cin >> n1 >> n2;
			for (int j = n1; j <= n2; j++)
				book[i].push_back(j);
		}

		int cnt = 0;
		for (int i = 1; i <= M; i++) {
			fill(visited, visited + MAX, false);
			if (dfs(i)) cnt++;
		}

		cout << cnt << '\n';

		for (int i = 1; i <= 1000; i++) {
			d[i] = 0, visited[i] = 0;
			for (int j = 1; j <= 1000; j++) book[i].clear();
		}
	}
}
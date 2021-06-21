#include <iostream>
#include <vector>
#define MAX 51
using namespace std;
int N, M;
int Min = 1000000000;
char graph[MAX][MAX];
vector<pair<int, int>> v1;
vector<pair<int, int>> v2;
bool visit_v2[101];
// 치킨거리를 계산해주는 함수
int chicken_distance() {
	vector<int> chicken(101, 10000);
	for (int i = 0; i < MAX; i++) {
		if (visit_v2[i]) {
			for (int j = 0; j < v1.size(); j++) {
				chicken[j] = min(abs(v1[j].first - v2[i].first) + abs(v1[j].second - v2[i].second), chicken[j]);
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < v1.size(); i++) {
		sum += chicken[i];
	}
	return sum;
}
// 백트래킹
void backtracking(int x, int prev) {
	// M만큼 치킨집을 선택했으면 치킨거리의 최소값 최신화
	if (x == M) {
		Min = min(Min, chicken_distance());
		return;
	}
	// nCr을 구현
	for (int i = prev; i < v2.size(); i++) {
		if (!visit_v2[i]) {
			visit_v2[i] = true;
			backtracking(x + 1, i);
			visit_v2[i] = false;
		}
	}
}
void init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main(void) {
	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == '1') {
				v1.push_back({ i,j });
			}
			if (graph[i][j] == '2') {
				v2.push_back({ i,j });
			}
		}
	}
	backtracking(0, 0);
	cout << Min << '\n';
	return 0;
}
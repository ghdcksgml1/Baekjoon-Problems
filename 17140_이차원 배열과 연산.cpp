#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;
int R, C, K;
int row, col; // 현재의 R,C
int graph[MAX][MAX];

int cnt_arr[MAX]; // counting sort를 위한 배열

vector<pair<int, int>> v;
// compare 함수
bool compare(pair<int,int> a, pair<int,int> b) {
	// second기준으로 오름차순, second가 같다면 first기준으로 오름차순
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}
// R 연산
void sort_R() {
	for (int i = 0; i < row; i++) {
		v.clear(); // 벡터 초기화
		for (int j = 0; j < col; j++) {
			cnt_arr[graph[i][j]]++;
			graph[i][j] = 0;
		}
		for (int j = 1; j < MAX; j++) {
			if (cnt_arr[j] > 0) {
				v.push_back({ j,cnt_arr[j] });
				cnt_arr[j] = 0;
			}
		}
		sort(v.begin(), v.end(), compare);
		int graph_index = 0;
		for (int j = 0; j < v.size(); j++) {
			graph[i][graph_index] = v[j].first;
			graph[i][graph_index+1] = v[j].second;
			graph_index += 2;
			if (graph_index >= MAX) break;
		}
	}
	// 바뀐 graph 배열에서의 col의 최댓값
	int cnt_col;
	col = 0;
	for (int i = 0; i < MAX; i++) {
		cnt_col = 0;
		for (int j = 0; j < MAX; j++) {
			if (graph[i][j] == 0) break;
			cnt_col++;
		}
		col = max(col, cnt_col);
	}
}
// C 연산
void sort_C() {
	for (int i = 0; i < col; i++) {
		v.clear(); // 벡터 초기화
		for (int j = 0; j < row; j++) {
			cnt_arr[graph[j][i]]++;
			graph[j][i] = 0;
		}
		for (int j = 1; j < MAX; j++) {
			if (cnt_arr[j] > 0) {
				v.push_back({ j,cnt_arr[j] });
				cnt_arr[j] = 0;
			}
		}
		sort(v.begin(), v.end(), compare);
		int graph_index = 0;
		for (int j = 0; j < v.size(); j++) {
			graph[graph_index][i] = v[j].first;
			graph[graph_index + 1][i] = v[j].second;
			graph_index += 2;
			if (graph_index >= MAX) break;
		}
	}
	// 바뀐 graph 배열에서 row의 최댓값
	int cnt_row;
	row = 0;
	for (int i = 0; i < MAX; i++) {
		cnt_row = 0;
		for (int j = 0; j < MAX; j++) {
			if (graph[j][i] == 0) break;
			cnt_row++;
		}
		row = max(row, cnt_row);
	}
}
void init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main(void) {
	init();
	cin >> R >> C >> K;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> graph[i][j];
		}
	}
	row = 3; col = 3;
	int cnt_100 = 0;
	while (cnt_100 <= 100) {
		// 원하는 좌표에 원하는 값이 오게되면
		if (graph[R-1][C-1] == K) {
			cout << cnt_100 << '\n';
			return 0;
		}
		cnt_100 += 1;
		if (row >= col) {
			sort_R();
		}
		else {
			sort_C();
		}
	}
	cout << "-1" << '\n';
}
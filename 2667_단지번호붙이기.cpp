#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N; // 지도의 크기
char n_arr[30][30];
vector<int> cnt; // 단지별 집의 수
int num = 0; // 단지의 개수
void dfs(int x,int y,int numm) {
	// 지도 범위를 벗어나면 return
	if (x < 0 || y < 0 || x >= N || y >= N) return;
	// 지도가 0이 아니면
	if (n_arr[x][y] != '0') {
		n_arr[x][y] = '0'; // 방문표시
		cnt[numm]++; // 단지의 집의 개수 증가
		dfs(x + 1, y, numm); // 오른쪽
		dfs(x, y + 1, numm); // 위쪽
		dfs(x - 1, y, numm); // 왼쪽
		dfs(x, y - 1, numm); // 아래쪽
	}
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n_arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (n_arr[i][j] == '1') {
				cnt.push_back(0);
				dfs(i, j,num);
				num++;
			}
		}
	}
	cout << num << '\n';
	// 오름차순으로 정렬
	sort(cnt.begin(), cnt.end());
	for (int i = 0; i < cnt.size(); i++) {
		cout << cnt[i] << '\n';
	}
}
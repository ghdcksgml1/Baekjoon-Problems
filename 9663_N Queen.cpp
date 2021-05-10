#include <iostream>

using namespace std;

int N;
int cnt = 0;
bool isused1[40];
bool isused2[40]; // 왼쪽에서 오른쪽 대각선
bool isused3[40]; // 오른쪽에서 왼쪽 대각선
void backtracking(int x) {
	if (x==N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N;i++) {
		if (isused1[i] || isused2[i + x] || isused3[x - i + N - 1]) continue;
		isused1[i] = 1;
		isused2[i + x] = 1;
		isused3[x - i + N - 1] = 1;
		backtracking(x + 1);
		isused1[i] = 0;
		isused2[i + x] = 0;
		isused3[x - i + N - 1] = 0;
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	backtracking(0);
	cout << cnt << '\n';
}
#include <iostream>

using namespace std;

int T,n;
int cnt = 0;

void backtracking(int sum) {
	if (sum >= n) {
		if (sum == n)
			cnt++;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		backtracking(sum + i);
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cnt = 0;
		cin >> n;
		backtracking(0);
		cout << cnt << '\n';
	}
}
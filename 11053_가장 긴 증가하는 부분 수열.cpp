#include <iostream>
#include <queue>
using namespace std;
int N;
int A[1005];
int dp[1005];
priority_queue<int> pq;
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	// dynamic programming
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i]) {
				if (dp[j] >= dp[i]) {
					dp[i] = dp[j]+1;
				}
			}
		}
		pq.push(dp[i]);
	}
	if (!pq.empty()) {
		cout << pq.top() << '\n';
	}
	else {
		cout << dp[1] << '\n';
	}
	return 0;
}
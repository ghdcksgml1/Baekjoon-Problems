#include <iostream>
using namespace std;
int N;
int T[15];
int P[15];
int dp[15];
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
	for (int i = N; i >= 0; i--) {
		if (i + T[i] > N) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + T[i]] + P[i], dp[i + 1]);
		}
	}
	cout << dp[0] << '\n';
}
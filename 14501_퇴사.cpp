#include <iostream>
using namespace std;
int N;
int T[16];
int P[16];
int dp[16];
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	for (int i = N; i >= 1; i--) {
		if (i + T[i]-1 > N) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + T[i]] + P[i], dp[i + 1]);
		}
	}
	cout << dp[1] << '\n';
}
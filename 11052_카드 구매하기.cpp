#include <iostream>
using namespace std;
int N;
int P_arr[1005] = { 0, };
int dp[1005] = { 0, };

void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P_arr[i];
	}
	// dynamic programming
	dp[1] = P_arr[1]; dp[2] = max(P_arr[1] + P_arr[1], P_arr[2]);
	for (int i = 3; i <= N; i++) {
		int P = P_arr[i];
		for (int j = 1; j <= i / 2; j++) {
			P = max(P, dp[j] + dp[i - j]);
		}
		dp[i] = P;
	}
	//
	cout << dp[N] << '\n';
	
}
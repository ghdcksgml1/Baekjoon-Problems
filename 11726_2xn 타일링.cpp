#include <iostream>

using namespace std;
int n_dp[1001];
int n;
int dp(int x) {
	if (n_dp[x] != 0) return n_dp[x];
	return n_dp[x] = (dp(x - 2) + dp(x - 1))%10007;
}
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> n;
	n_dp[1] = 1; n_dp[2] = 2;
	cout << dp(n) << '\n';
}
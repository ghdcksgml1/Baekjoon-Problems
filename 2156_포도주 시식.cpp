#include <iostream>
using namespace std;
int n;
int n_arr[10001];
int dp[10001];
int max(int a, int b, int c) {
	if (a > b) {
		if (a > c) return a;
		else return c;
	}
	else {
		if (b > c) return b;
		else return c;
	}
}
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> n_arr[i];
	}
	dp[0] = n_arr[0];
	dp[1] = n_arr[0] + n_arr[1];
	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 3] + n_arr[i - 1] + n_arr[i],dp[i-2]+n_arr[i],dp[i-1] );
	}
	cout << dp[n - 1] << '\n';
}
// 
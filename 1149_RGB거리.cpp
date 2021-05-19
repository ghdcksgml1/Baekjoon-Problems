#include <iostream>
using namespace std;
int N;
int n_arr[1000][3];
int dp[1000][3];
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> n_arr[i][j];
		}
	}
	// 초기값
	dp[0][0] = n_arr[0][0]; dp[0][1] = n_arr[0][1]; dp[0][2] = n_arr[0][2];
	// 점화식
	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + n_arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + n_arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + n_arr[i][2];
	}
	// N에서 최솟값 찾기
	int minn = dp[N-1][0];
	for (int i = 1; i < N; i++) {
		minn = min(minn, dp[N-1][i]);
	}
	/*************************/
	cout << minn << '\n';
}
#include <iostream>
using namespace std;
int n_arr[501][501];
int dp[501][501];
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> n_arr[i][j];
		}
	}
	if (N == 1) {
		cout << n_arr[1][1] << '\n';
		return 0;
	}
	// 초기 값
	dp[1][1] = n_arr[1][1];
	dp[2][1] = n_arr[1][1] + n_arr[2][1];
	dp[2][2] = n_arr[1][1] + n_arr[2][2];
	// Dynamic Programming 점화식
	for (int i = 3; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				dp[i][1] = dp[i - 1][1] + n_arr[i][1];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + n_arr[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + n_arr[i][j];
			}
		}
	}
	// 마지막 배열에서의 최댓값 찾기
	int max_num = dp[N][1];
	for (int i = 2; i <= N; i++) {
		max_num = max(max_num, dp[N][i]);
	}
	cout << max_num<< '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
vector<int> n_arr(101,0);
int dp[10001];
// 1: 1 2: 11 2 , 3: 111 21 , 4: 1111 211 22 , 5: 11111 2111 221 5 , 6: 111111 21111 2211 222 51
// 7: 1111111 211111 22111 2221 511 52 , 8: 11111111 2111111 221111 22211 2222 5111 521
// 9: 111111111 21111111 2211111 222111 22221 51111 5211 522 
//10: 1111111111 211111111 22111111 2221111 222211 22222 511111 52111 5221 55

void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> n_arr[i];
	}
	dp[0] = 1;
	
	sort(n_arr.begin(),n_arr.end());
	n_arr.erase(unique(n_arr.begin(), n_arr.end()),n_arr.end());
	for (int i = 0; i < n_arr.size(); i++) {
		for (int j = 1; j <= k; j++) {
			if (j - n_arr[i] >= 0) {
				dp[j] = dp[j] + dp[j - n_arr[i]];
			}
		}
	}
	
	cout << dp[k] << '\n';
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int T,num;
vector<pair<int, int>> dp;
pair<int,int> fibonacci(int n) {
    if (n == 0) {
        dp[n].first = 1;
        return dp[n];
    }
    else if (n == 1) {
        dp[n].second = 1;
        return dp[n];
    }
    if (dp[n].first != 0 || dp[n].second != 0) return dp[n];
    dp[n].first = fibonacci(n - 1).first + fibonacci(n - 2).first;
    dp[n].second = fibonacci(n - 1).second + fibonacci(n - 2).second;
    return dp[n];
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> T;
    for (int i = 0; i < 40; i++) {
        dp.push_back({ 0,0 });
    }
	for (int i = 0; i < T; i++) {
		cin >> num;
        cout << fibonacci(num).first << ' ' << fibonacci(num).second << '\n';
	}
}
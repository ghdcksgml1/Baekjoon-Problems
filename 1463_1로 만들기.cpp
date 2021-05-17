#include <iostream>
#include <queue>
using namespace std;
int N;
int visited[1000001];
queue<pair<int, int>> q;
int dp(int x) {
	if (x == 1) return 0;
	if (x == 2) return 1;
	if (x == 3) return 1;
	if (visited[x] != 0) return visited[x];
	
	
	return dp(x - 1) + 1;
	if (x % 2 == 0) return (dp(x / 2) + 1);
	if (x % 3 == 0) return (dp(x / 3) + 1);
}

int main(void) {
	cin >> N;
	cout << dp(N) << '\n';
}
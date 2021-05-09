#include <iostream>
#include <vector>
#include <string>

using namespace std;
int N,S;
int num[21];
int cnt = 0;

void backtrack(int x,int sum) {
	if (x == N) {
		if (sum == S) {
			cnt++;
		}
		return;
	}
	backtrack(x + 1, sum);
	backtrack(x + 1, sum + num[x]);

}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	backtrack(0, 0);
	if (S == 0) cnt--;
	cout << cnt << '\n';
}
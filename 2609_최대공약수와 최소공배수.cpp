#include <iostream>

using namespace std;

int N, M;
int minn;
int result = 1;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	if (N > M) minn = M;
	else minn = N;
	for (int i = 2; i <= minn; i++) {
		while(N % i == 0 && M % i == 0) {
			N = N / i;
			M = M / i;
			result = result * i;
		}
	}
	cout << result << ' ' << result * N * M << '\n';
}
#include <iostream>

using namespace std;
int N, K;
int cnt = 0;
int n_arr[10];
bool compare(int a, int b) {
	return a > b;
}
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		cin >> n_arr[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		if (K == 0) break;
		if (K >= n_arr[i]) {
			cnt = cnt + K / n_arr[i];
			K = K % n_arr[i];
		}
	}
	cout << cnt << '\n';
}
#include <iostream>
#include <algorithm>
using namespace std;
int N, C;
int N_arr[200001];

void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> N_arr[i];
	}
	sort(N_arr, N_arr + N);
	// 초기값 설정
	int answer = 0;
	int left = 1; 
	int right = N_arr[N - 1] - N_arr[0]; 
	/**********************************/
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int start = N_arr[0];

		for (int i = 1; i < N; i++) {
			int distance = N_arr[i] - start;
			if (distance >= mid) {
				cnt++;
				start = N_arr[i];
			}
		}

		if (cnt >= C) {
			answer = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << answer << '\n';
}
#include <iostream>
#include <queue>
using namespace std;
int n,N;
int n_arr[100001];
priority_queue<int> pq;
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> n;
	int sum = 0;
	int trigger = 0;
	for (int i = 0; i < n; i++) {
		cin >> N;
		if (i == 0) {
			n_arr[0] = N;
			pq.push(n_arr[0]);
			continue;
		}
		if (N < N + n_arr[i - 1]) {
			n_arr[i] = N + n_arr[i - 1];
			pq.push(n_arr[i]);
		}
		else {
			n_arr[i] = N;
			pq.push(n_arr[i]);
		}
	}
	cout << pq.top() << '\n';
}
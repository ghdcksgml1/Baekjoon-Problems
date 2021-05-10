#include <iostream>
#include <queue>

using namespace std;

int N,n;
int maxx;
int cnt = 0;
priority_queue<int> pq;
int n_arr[1001];

void func(int x) {
	if (x == 1) {
		n_arr[1] = 1;
		return func(x + 1);
	}
	if (x >= maxx) {
		return;
	}
	for (int i = 2; i*x <= maxx;i++) {
		n_arr[i * x] = 1;
	}
	return func(x + 1);
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		pq.push(n);
	}
	maxx = pq.top();
	func(1);
	for (int i = 0; i < N; i++) {
		if (n_arr[pq.top()] == 0) {
			cnt++;
		}
		pq.pop();
	}
	for (int i = 1; i <= maxx; i++) {
		cout << i << " : " << n_arr[i] << ", ";
		if (i % 10 == 0) {
			cout << '\n';
		}
	}
	
	cout << cnt << '\n';
}
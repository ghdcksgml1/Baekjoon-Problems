#include <iostream>
#include <queue>
using namespace std;
int N;
int sum = 0;
priority_queue<int, vector<int>, greater<int>> pq;
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		pq.push(n);
	}
	if (pq.size() == 1) {
		cout << "0" << '\n';
	}
	else {
		while (pq.size() != 1) {
			int cur1 = pq.top(); pq.pop();
			int cur2 = pq.top(); pq.pop();
			pq.push(cur1 + cur2);
			sum += cur1 + cur2;
		}
		cout << sum << '\n';
	}
}
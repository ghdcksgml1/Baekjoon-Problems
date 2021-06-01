#include <iostream>
#include <queue>
using namespace std;
int N;
priority_queue<int> pq;

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
		if (n == 0) {
			if (!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else {
				cout << "0" << '\n';
			}
		}
		else {
			pq.push(n);
		}
	}
}
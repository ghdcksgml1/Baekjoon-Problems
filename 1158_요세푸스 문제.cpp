#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	queue<int> q;
	int N, K;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	cin >> K;
	cout << '<';
	while (1) {
		for (int i = 1; i < K; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (!q.empty()) {
			cout << ", ";
		}
		else {
			break;
		}
	}
	cout << '>';
}
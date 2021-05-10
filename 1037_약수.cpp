#include <iostream>
#include <queue>

using namespace std;
int N,n;
priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		pq1.push(n);
		pq2.push(n);
	}
	cout << pq1.top()*pq2.top() << '\n';
}
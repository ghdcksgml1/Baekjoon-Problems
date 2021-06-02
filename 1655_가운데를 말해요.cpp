#include <iostream>
#include <queue>
using namespace std;
int N;
priority_queue<int> pq_small;
priority_queue<int,vector<int>,greater<int>> pq_large;
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
		// i==0, i==1 일때는 pq가 비어있을 수 있으므로 따로 처리
		if (i == 0) {
			pq_large.push(n);
			cout << pq_large.top() << '\n';
			continue;
		}
		else if (i == 1) {
			if (n > pq_large.top()) {
				pq_small.push(pq_large.top());
				pq_large.pop();
				pq_large.push(n);
			}
			else {
				pq_small.push(n);
			}
			cout << pq_small.top() << '\n';
			continue;
		}

		if (pq_large.size() > pq_small.size()) {
			if (n > pq_large.top()) { // pq_large의 최솟값이 n보다 작다면
				pq_small.push(pq_large.top()); // pq_large의 최솟값을 pq_small로 옮기고
				pq_large.pop(); 
				pq_large.push(n); // pq_large에 n을 추가
			}
			else {
				pq_small.push(n);
			}
			cout << pq_small.top() << '\n';
		}
		else if (pq_large.size() == pq_small.size()) {
			if (n < pq_small.top()) { // n이 pq_small의 최댓값보다 작다면
				pq_large.push(pq_small.top()); // pq_small의 최댓값을 pq_large로 옮기고
				pq_small.pop();
				pq_small.push(n); // pq_small 에 n을 추가
			}
			else {
				pq_large.push(n);
			}
			cout << pq_large.top() << '\n';
		}
	}
}
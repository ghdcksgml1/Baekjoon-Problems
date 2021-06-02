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
		// i==0, i==1 �϶��� pq�� ������� �� �����Ƿ� ���� ó��
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
			if (n > pq_large.top()) { // pq_large�� �ּڰ��� n���� �۴ٸ�
				pq_small.push(pq_large.top()); // pq_large�� �ּڰ��� pq_small�� �ű��
				pq_large.pop(); 
				pq_large.push(n); // pq_large�� n�� �߰�
			}
			else {
				pq_small.push(n);
			}
			cout << pq_small.top() << '\n';
		}
		else if (pq_large.size() == pq_small.size()) {
			if (n < pq_small.top()) { // n�� pq_small�� �ִ񰪺��� �۴ٸ�
				pq_large.push(pq_small.top()); // pq_small�� �ִ��� pq_large�� �ű��
				pq_small.pop();
				pq_small.push(n); // pq_small �� n�� �߰�
			}
			else {
				pq_large.push(n);
			}
			cout << pq_large.top() << '\n';
		}
	}
}
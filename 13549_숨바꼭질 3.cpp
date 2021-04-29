#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
typedef pair<int, int> P;

int BFS() {
	priority_queue<P, vector<P>, greater<P>> q;
	vector<bool> visited(100001, false);
	q.push({ 0,n });
	visited[n] = true;
	while (!q.empty()) {
		P curr = q.top();
		q.pop();
		if (curr.second == k)
			return curr.first;
		for (int i = 0; i < 3; i++) {
			P next = { 0, 0 };
			if (i == 0) next = { curr.first,curr.second * 2 };
			else if (i == 1) next = { curr.first + 1,curr.second - 1 };
			else next = { curr.first + 1,curr.second + 1 };

			if (next.second < 0 || next.second>100000) continue;
			if (visited[next.second]) continue;

			q.push(next);
			visited[next.second] = true;
		}
	}
	return 0;
}

int main(void) {
	cin >> n >> k;
	cout << BFS() << '\n';
	return 0;
}
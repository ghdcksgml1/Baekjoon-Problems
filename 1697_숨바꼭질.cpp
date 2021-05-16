#include <iostream>
#include <queue>
using namespace std;
int N, K;
bool visited[100010];
int main(void) {
	cin >> N >> K;
	if (N > K) {
		cout << N - K << '\n';
		return 0;
	}
	queue<pair<int,int>> q;
	q.push({ N,0 });
	while (q.front().first != K) {
		if (visited[q.front().first]) {
			q.pop();
			continue;
		}
		visited[q.front().first] = true;
		auto cur = q.front(); q.pop();
		if (cur.first < (K/2)+2 && !visited[cur.first *2]) {
			q.push({ cur.first * 2 ,cur.second + 1 });
			
		}
		if (cur.first > 0 && !visited[cur.first - 1]) {
			q.push({ cur.first - 1 ,cur.second + 1 });
		}
		if (cur.first < K && !visited[cur.first+1]) {
			q.push({ cur.first + 1 ,cur.second + 1 });
		}
	}
	cout << q.front().second << '\n';
}
#include <iostream>
#include <queue>

using namespace std;

int T, N, M;
int num;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			cin >> num;
			q.push({ num,j }); // 각 위치를 key값으로 쓴다.
			pq.push(num);
		}
		int index = 0; // 몇번째로 빠져나오는지를 저장해주는 변수
		while(!q.empty()) {
			// 우선순위 큐의 top과 큐의 front 값이 같을때까지 반복
			while (q.front().first != pq.top()) {
				q.push(q.front());
				q.pop();
			}
			// q의 key부분이 찾고자하는 M일때
			if (q.front().second == M) {
				index++;
				cout << index << '\n';
				break; // 출력해준뒤 탈출
			}
			// q의 key부분이 찾고하는 부분이 아니면
			else {
				index++;
				q.pop(); pq.pop();
				// 큐와 우선순위 큐를 빼냄
				// 다음으로 출력되는 큰수를 찾기위해
			}
		}
	}
}
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N;
int cnt = 0;
typedef pair<int, int> pir;
vector<pir> v;
vector<pir> T;
priority_queue<int> pq;
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N;
	for (int i = 0; i <= N; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		if (i == N) {
			T.push_back({ n1,n2 });
		}
		else {
			v.push_back({ n1,n2 });
		}
	}
	sort(v.begin(), v.end());
	int idx = 0;
	while(T[0].second < T[0].first){
		
		if (idx == N && !pq.empty()) {
			T[0].second += pq.top(); pq.pop();
			cnt++;
		}
		else if (idx == N && pq.empty()) {
			cout << "-1" << '\n';
			return 0;
		}
		else {
			if (T[0].second >= v[idx].first) {
				pq.push(v[idx].second);
				idx++;
			}
			else {
				while (T[0].second < v[idx].first) {
					if (!pq.empty()) {
						T[0].second += pq.top();
						pq.pop();
						cnt++;
					}
					else {
						cout << "-1" << '\n';
						return 0;
					}
				}
			}
		}
	}
	cout << cnt << '\n';
}
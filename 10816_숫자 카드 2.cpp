#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M,K, card;
vector<int> v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> card;
		v.push_back(card);
	}
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> K;
		auto cur1 = lower_bound(v.begin(), v.end(), K);
		auto cur2 = upper_bound(v.begin(), v.end(), K);
		cout << cur2 - cur1 << ' ';
	}
}
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, K;
typedef pair<int, int> pir;
priority_queue<int> jewelry;
vector<pir> gem;
vector<int> bag;

void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}

int main(void) {
	init();
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		gem.push_back({ n1,n2 });
	}
	for (int i = 0; i < K; i++) {
		int n;
		cin >> n;
		bag.push_back(n);
	}
	
	sort(gem.begin(), gem.end());
	sort(bag.begin(), bag.end());

	int idx = 0;
	long long sum = 0;
	for (int i = 0; i < K; i++) {
		while (idx < N && gem[idx].first <= bag[i]) {
			jewelry.push(gem[idx++].second);
		}
		if (!jewelry.empty()) {
			sum += jewelry.top();
			jewelry.pop();
		}
	}
	cout << sum << '\n';
}

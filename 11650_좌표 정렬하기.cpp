#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool compare(pair<int, int>&a, pair<int, int>&b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	vector<pair<int, int>> v;
	int n1, n2;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n1 >> n2;
		v.push_back({ n1,n2 });
	}
	sort(v.begin(), v.end(), compare);
	for (auto i : v) {
		cout << i.first << ' ' << i.second << '\n';
	}
}
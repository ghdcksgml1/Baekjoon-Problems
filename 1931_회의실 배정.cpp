#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<pair<int, int>> v;
bool compare(pair<int,int> a, pair<int,int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
// 1,3 2,4 4,5
int main(void) {
	init();
	int n1, n2;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n1 >> n2;
		v.push_back({ n1,n2 });
	}
	sort(v.begin(), v.end(), compare);
	int cnt = 0;
	int minn = 0;
	for (int i = 0; i < N; i++) {
		if (minn <= v[i].first) {
			cnt++;
			minn = v[i].second;
		}
	}
	cout << cnt << '\n';
}
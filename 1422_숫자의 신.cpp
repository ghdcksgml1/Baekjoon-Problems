#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, K;
vector<string> v;
priority_queue<pair<int,string>> pq;
bool compare(string a, string b) {
	if (a != b) {
		int Max = max(a.size(), b.size());
		for (int i = 0; i < Max; i++) {
			int a_index = i % a.size();
			int b_index = i % b.size();
			if (a[a_index] > b[b_index]) return true;
			else if(a[a_index] < b[b_index]) return false;
		}
		if ((a + b) < (b + a)) {
			return false;
		}
		else {
			return true;
		}
	}
	return false;
}
int main(void) {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		v.push_back(name);
		pq.push({ name.size(),name });
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; i++) {
		if (!pq.empty() && v[i] == pq.top().second) {
			for (int j = 0; j <= (K - N); j++) {
				cout << v[i];
			}
			while (!pq.empty()) {
				pq.pop();
			}
		}
		else {
			cout << v[i];
		}
	}
	cout << '\n';
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int n;
int num;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto i : v) {
		cout << i << '\n';
	}
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int n[100050];
int cnt = 0;
vector<int> v;
int ucl(int a, int b) {
	if (b == 0)
		return a;
	else
		return ucl(b, a%b);
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}
	sort(n, n + N);
	for (int i = 0; i < N; i++) {
		if (i != 0) {
			v.push_back(n[i] - n[i - 1]);
		}
	}
	int tmp = v[0];
	for (int i = 1; i < v.size(); i++) {
		tmp = ucl(tmp, v[i]);
	}
	for (int i = 0; i < v.size(); i++) {
		cnt += v[i] / tmp - 1;
	}
	cout << cnt << '\n';
}
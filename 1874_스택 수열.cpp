#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
int n;
stack<int> s1;
stack<int> s2;
vector<char> v;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = N; i > 0; i--) {
		s1.push(i);
	}
	for (int i = 0; i < N; i++) {
		int is1 = 0;
		int is2 = 0;
		cin >> n;
		while (!s1.empty() && s1.top() <= n) {
			s2.push(s1.top());
			s1.pop();
			v.push_back('+');
			is1 = 1;
		}
		while (!s2.empty() && s2.top() >= n) {
			s2.pop();
			v.push_back('-');
			is2 = 1;
		}
		if (is1 == 0 && is2 == 0) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	for (auto i : v) {
		cout << i << '\n';
	}
}
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N;


int main(void) {
	string name = "";
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int is1 = 0;
		stack<char> s;
		cin >> name;
		for (int j = 0; j < name.size(); j++) {
			if (name[j] == '(') {
				s.push('(');
			}
			else if (name[j] == ')') {
				if (!s.empty()) {
					s.pop();
				}
				else {
					is1 = 1;
				}
			}
		}
		if (s.empty() && is1==0) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	
}
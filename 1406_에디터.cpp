#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	int M;
	string name = "";
	stack<char> s1;
	stack<char> s2;
	cin >> name;
	for (int i = 0; i < name.size(); i++) {
		s1.push(name[i]);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> name;
		if (name == "L") {
			if (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		else if (name == "D") {
			if (!s2.empty()) {
				s1.push(s2.top());
				s2.pop();
			}
		}
		else if (name == "B") {
			if (!s1.empty()) {
				s1.pop();
			}
		}
		else if (name == "P") {
			cin >> name;
			s1.push(name[0]);
		}
	}
	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
	while (!s2.empty()) {
		cout << s2.top();
		s2.pop();
	}
}
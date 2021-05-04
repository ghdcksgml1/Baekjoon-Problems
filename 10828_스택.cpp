#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N;

int main(void) {
	stack<int> st;
	string name = "";
	int num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> name;
		if (name == "push") {
			cin >> num;
			st.push(num);
		}
		else if (name == "top") {
			if (!st.empty()) {
				cout << st.top() << '\n';
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (name == "pop") {
			if (!st.empty()) {
				cout << st.top() << '\n';
				st.pop();
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (name == "size") {
			cout << st.size() << '\n';
		}
		else if (name == "empty") {
			if (st.empty()) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}
	}
}
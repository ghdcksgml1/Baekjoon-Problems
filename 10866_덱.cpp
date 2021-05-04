#include <iostream>
#include <deque>
#include <string>

using namespace std;

int N,num;

int main(void) {
	deque<int> dq;
	string name = "";
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name;
		if (name == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (name == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (name == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (name == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (name == "size") {
			cout << dq.size() << '\n';
		}
		else if (name == "empty") {
			if (!dq.empty()) {
				cout << "0" << '\n';
			}
			else {
				cout << "1" << '\n';
			}
		}
		else if (name == "front") {
			if (!dq.empty()) {
				cout << dq.front() << '\n';
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (name == "back") {
			if (!dq.empty()) {
				cout << dq.back() << '\n';
			}
			else {
				cout << "-1" << '\n';
			}
		}
	}
}
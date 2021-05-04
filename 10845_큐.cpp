#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N,num;

int main(void) {
	string name = "";
	queue<int> q;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name;
		if (name == "push") {
			cin >> num;
			q.push(num);
		}
		else if (name == "pop") {
			if (q.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (name == "size") {
			cout << q.size() << '\n';
		}
		else if (name == "empty") {
			if (q.empty()) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}
		else if (name == "front") {
			if (q.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << q.front() << '\n';
			}
		}
		else if (name == "back") {
			if (q.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << q.back() << '\n';
			}
		}
	}
}
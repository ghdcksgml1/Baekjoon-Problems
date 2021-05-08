#include <iostream>
#include <queue>
#include <string>

using namespace std;

int T,num;
string name = "";
string arr = "";

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> T;
	
	for (int j = 0; j < T; j++) {
		deque<int> q1;
		cin >> name;
		cin >> num;
		cin >> arr;
		for (int i = 1; arr[i] !='\0'; i++) {
			int x = 0;
			while (arr[i] >= '0' and arr[i] <= '9') {
				x *= 10;
				x += int(arr[i] - '0');
				i++;
			}
			if (x != 0) {
				q1.push_back(x);
			}
		}
		int trigger = 0;
		int iserr = 0;
		for (int i = 0; i < name.size(); i++) {
			if (name[i] == 'R') {
				if (trigger == 0) {
					trigger = 1;
				}
				else {
					trigger = 0;
				}
			}
			else if (!q1.empty() && name[i] == 'D') {
				if (trigger == 0) {
					q1.pop_front();
				}
				else {
					q1.pop_back();
				}
			}
			else {
				cout << "error" << '\n';
				iserr = 1;
				break;
			}
		}
		if (iserr == 1) {
			continue;
		}
		if (q1.empty()) {
			cout << "[]" << '\n';
			continue;
		}
		if (trigger == 0) {
			cout << '[';
			while (!q1.empty()) {
				cout << q1.front();
				q1.pop_front();
				if (!q1.empty()) {
					cout << ',';
				}
			}
			cout << ']';
		}
		else {
			cout << '[';
			while (!q1.empty()) {
				cout << q1.back();
				q1.pop_back();
				if (!q1.empty()) {
					cout << ',';
				}
			}
			cout << ']';
		}
		cout << '\n';
	}
}
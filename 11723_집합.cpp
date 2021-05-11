#include <iostream>
#include <string>
using namespace std;
int M;
string name = "";
int n;
int x[21];
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> name;
		if (name == "add") {
			cin >> n;
			x[n] = 1;
		}
		else if (name == "remove") {
			cin >> n;
			x[n] = 0;
		}
		else if (name == "check") {
			cin >> n;
			if (x[n] == 1) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}
		else if (name == "toggle") {
			cin >> n;
			if (x[n] == 1) {
				x[n] = 0;
			}
			else {
				x[n] = 1;
			}
		}
		else if (name == "all") {
			for (int j = 1; j <= 20; j++) {
				x[j] = 1;
			}
		}
		else if (name == "empty") {
			for (int j = 1; j <= 20; j++) {
				x[j] = 0;
			}
		}
	}
}
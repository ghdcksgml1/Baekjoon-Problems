#include <iostream>
#include <vector>
#include <string>

using namespace std;

int K;
vector<int> lotto(13, 0);
vector<int> visited(13, 0);

void cal(int c, string answer, int start) {
	if (c == 6) {
		cout << answer << '\n';
		return;
	}
	for (int i = start; i < K; i++) {
		if (visited[i] == 1)
				continue;
		visited[i] = 1;
		cal(c + 1, answer + to_string(lotto[i]) + " ", i + 1);
		visited[i] = 0;
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	while (true) {
		cin >> K;
		if (K == 0)
			break;
		for (int i = 0; i < K; i++) {
			cin >> lotto[i];
			visited[i] = 0;
		}
		cal(0, "", 0);
		cout << '\n';
	}
}
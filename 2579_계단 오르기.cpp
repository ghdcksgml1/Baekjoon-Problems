#include <iostream>
#include <vector>
using namespace std;
int n[305][3];
int stair_score[305];

int main(void) {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stair_score[i];
	}
	if (N == 1) {
		cout << stair_score[1];
		return 0;
	}
	n[1][1] = stair_score[1];
	n[1][2] = 0;
	n[2][1] = stair_score[2];
	n[2][2] = stair_score[1] + stair_score[2];
	for (int i = 3; i <= N; i++) {
		n[i][1] = max(n[i - 2][1], n[i - 2][2]) + stair_score[i];
		n[i][2] = n[i - 1][1] + stair_score[i];
	}
	cout << max(n[N][1], n[N][2]) << '\n';
}
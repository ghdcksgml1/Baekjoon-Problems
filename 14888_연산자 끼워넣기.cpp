#include <iostream>
#include <vector>
using namespace std;
int N;
int A[11];
int	operators[4];
bool visit[11];
int Max = -1000000000;
int Min = 1000000000;

void backtracking(int x,int sum) {
	if (x == N-1) {
		Max = max(sum, Max);
		Min = min(sum, Min);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (operators[i]>0) {
			operators[i]--;
			if (i == 0) backtracking(x + 1, sum +A[x + 1]);
			else if (i == 1) backtracking(x + 1, sum - A[x + 1]);
			else if (i == 2) backtracking(x + 1, sum * A[x + 1]);
			else if (i == 3) backtracking(x + 1, sum / A[x + 1]);
			operators[i]++;
		}
	}
}
void init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	// 0:µ¡¼À,1:»¬¼À,2:°ö¼À,3:³ª´°¼À
	cin >> operators[0] >> operators[1] >> operators[2] >> operators[3];

	backtracking(0, A[0]);
	cout << Max << '\n';
	cout << Min << '\n';
}
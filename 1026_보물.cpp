#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N,num;
vector<int> A[2];
bool compare(int i, int j) {
	return j < i;
}

int main(void) {
	cin >> N;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			A[i].push_back(num);
		}
	}
	sort(A[0].begin(), A[0].end());
	sort(A[1].begin(), A[1].end(), compare);
	int result = 0;
	for (int i = 0; i < N; i++) {
		result += A[0][i] * A[1][i];
	}
	cout << result << '\n';
}
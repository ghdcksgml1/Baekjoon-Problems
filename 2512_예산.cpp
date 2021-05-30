#include <iostream>
using namespace std;
int N,M;
int N_arr[10001];
void binarySearch(int start, int end) {
	if (start > end) {
		cout << end << '\n';
		return;
	}
	int sum = 0;
	int middle = (start + end) / 2;
	for (int i = 0; i < N; i++) {
		if (N_arr[i] > middle) {
			sum += middle;
		}
		else {
			sum += N_arr[i];
		}
	}
	if (sum <= M) {
		binarySearch(middle+1, end);
	}
	else {
		binarySearch(start, middle-1);
	}
}
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N;
	int Max = 0;
	for (int i = 0; i < N; i++) {
		cin >> N_arr[i];
		if (N_arr[i] > Max) Max = N_arr[i];
	}
	cin >> M;
	binarySearch(0, Max);
}
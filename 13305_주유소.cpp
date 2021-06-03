#include <iostream>
#define MAX 100001
using namespace std;
typedef long long ll;
int N;
ll D_arr[MAX]; // 거리
ll S_arr[MAX]; // 주유소
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> D_arr[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> S_arr[i];
	}
	ll min = S_arr[0];
	ll sum = 0;
	for (int i = 0; i < N - 1; i++) {
		sum += min * D_arr[i];
		if (min > S_arr[i + 1])	min = S_arr[i + 1];
	}
	cout << sum << '\n';
}
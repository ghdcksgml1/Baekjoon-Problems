#include <iostream>
using namespace std;
int N;
int N_arr[1000000];
int inspector;
int sub_inspector;
long long cnt = 0;
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> N_arr[i];
	}
	cin >> inspector >> sub_inspector;
	for (int i = 0; i < N; i++) {
		if (inspector >= N_arr[i]) {
			cnt += 1;
		}
		else {
			N_arr[i] = N_arr[i] - inspector; cnt++;
			int mod = N_arr[i] / sub_inspector;
			if ((N_arr[i] % sub_inspector) > 0) cnt++;
			cnt += mod;
		}
	}
	cout << cnt << '\n';
}
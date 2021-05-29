#include <iostream>
using namespace std;
typedef long long ll;
ll K, N;
ll N_len = 0;
ll K_arr[10001];
void BinarySearch(ll start, ll end) {
	if (start > end) {
		cout << end << '\n';
		return;
	}
	ll l_cnt = 0;
	ll middle = (start + end) / 2;
	for (int i = 0; i < K; i++) {
		l_cnt += (K_arr[i] / middle);
	}
	if (l_cnt >= N) {
		BinarySearch(middle + 1, end);
	}
	else {
		BinarySearch(start, middle - 1);
	}

}
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> K >> N;
	ll N_max_Num = 0;
	for (int i = 0; i < K; i++) {
		cin >> K_arr[i];
		if (K_arr[i] > N_max_Num) 
			N_max_Num = K_arr[i];
	}
	BinarySearch(1, N_max_Num);
}
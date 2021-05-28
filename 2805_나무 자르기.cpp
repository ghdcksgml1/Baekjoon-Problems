#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll N, M, res;
ll N_arr[1000001];
void bisect(ll lo, ll hi) {
	if (lo > hi) return;
	ll mid = (lo + hi) / 2;
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		if (N_arr[i] > mid)
			sum += (N_arr[i] - mid);
	}
	if (sum >= M) {
		if (res < mid) res = mid;
		bisect(mid + 1, hi);
	}
	else bisect(lo, mid - 1);
}
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> N_arr[i];
	}
	sort(N_arr, N_arr + N);
	bisect(0, N_arr[N - 1]);
	cout << res<<'\n';
	
}
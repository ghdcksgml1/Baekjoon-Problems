#include <iostream>
#include <vector>
using namespace std;
int N;
bool num[4000001];
vector<int> prime_num;
int main(void) {
	int cnt = 0;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	// 에라토스테네스의 체
	// O(n log(log n))
	for (int i = 2; i*i <= N; i++) {
		if (num[i] != 0) continue;
		for (int j = 2; i*j <= N; j++) {
			num[i * j] = 1;
		}
	}
	for (int i = 2; i <= N; i++) {
		if (num[i] == 0) {
			prime_num.push_back(i);
		}
	}
	// 두 포인터
	int size = prime_num.size();
	int start = 0; int end = 0; int sum = 0;
	while (1) {
		if (sum >= N) sum -= prime_num[start++];
		else if (end == size)break;
		else sum += prime_num[end++];
		if (sum == N) cnt++;
	}

	/********************************/
	cout << cnt << '\n';
	return 0;
}
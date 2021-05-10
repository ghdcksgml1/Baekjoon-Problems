#include <iostream>

using namespace std;

int M, N;
bool prime_Num[1000001];

void primeNumber() {
	for (int i = 2; i <= N; i++) {
		if (!prime_Num[i]) {
			for (int j = 2; j * i <= N; j++) {
				prime_Num[i * j] = true;
			}
		}
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> M >> N;
	primeNumber();
	for (int i = M; i <= N; i++) {
		if (prime_Num[i] == 0) {
			cout << i << '\n';
		}
	}
}
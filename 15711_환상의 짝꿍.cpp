#include <iostream>
#include <vector>
using namespace std;
int T;
long long int n1, n2;
vector<int> prime;
bool eratos[2000001];
// sqrt(2x10^12)은 대략 2000000 정도이기때문에 
void eratosthenes(void) {
	eratos[0] = eratos[1] = true;
	for (int i = 2; i <= 2000000; i++) {
		if (eratos[i] == false) {
			prime.push_back(i);
			for (int j = 2; j*i <= 2000000; j++) {
				eratos[j*i] = true;
			}
		}
	}
}
// 2000000미만이면 구해져있는 값이 있고,
// 이상이면 구해져있는 값이 없기때문에
bool isPrime(long long int x) {
	if (x <= 2000000) return !eratos[x];
	for (int i = 0; i< prime.size(); i++) {
		if (x % prime[i] == 0) return false;
	}
	return true;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	eratosthenes();
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n1 >> n2;
		long long int sum = n1 + n2;
		if (sum == 2) {
			cout << "NO" << '\n';
			continue;
		}
		if (sum % 2 == 0) {
			cout << "YES" << '\n';
		}
		else {
			if (isPrime(sum-2)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}
}
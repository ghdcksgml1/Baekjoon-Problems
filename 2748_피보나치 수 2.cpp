#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

long long a[91];
long long dp(long long x) {
	if (x == 0) return 0;
	if (x == 1) return 1;
	if (a[x] != 0) return a[x];
	return a[x] = dp(x - 1) + dp(x - 2);
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%lld\n", dp(n));
}
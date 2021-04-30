#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int a, b, c;
int result = 0;
long long int pow(long long int x, long long int m) {
	if (m == 0)
		return 1;
	else if (m == 1)
		return x;
	if (m % 2 > 0)
	// 지수가 홀수일 경우 한번 더 곱해줘야하므로
		return pow(x, m - 1) * x;
	// 짝수일 경우에는 반반 나눠 두개 곱해주기
	long long int half = pow(x, m / 2);
	// overflow 방지
	half %= c;
	return (half * half) % c;
}
int main(void) {
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld\n", pow(a, b) % c);
	return 0;
}
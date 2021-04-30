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
	// ������ Ȧ���� ��� �ѹ� �� ��������ϹǷ�
		return pow(x, m - 1) * x;
	// ¦���� ��쿡�� �ݹ� ���� �ΰ� �����ֱ�
	long long int half = pow(x, m / 2);
	// overflow ����
	half %= c;
	return (half * half) % c;
}
int main(void) {
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld\n", pow(a, b) % c);
	return 0;
}
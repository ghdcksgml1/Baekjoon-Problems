#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N[500001];
int n;

int main(void) {
	int m;
	int num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &N[i]);
	}
	sort(N, N + n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &num);
		if (binary_search(N,N+m,num)) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;
int n[2002];

int main(void) {
	int num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d",&num);
		n[num + 1000]++;
	}
	for (int i = 0; i < 2002; i++) {
		if (n[i] > 0) {
			printf("%d\n", i - 1000);
		}
	}
}
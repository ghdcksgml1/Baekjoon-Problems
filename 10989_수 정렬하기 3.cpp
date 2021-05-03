#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int index[10001];

int main(void) {
	int N;
	int value;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &value);
		index[value]++;
	}
	for (int i = 0; i < 10001; i++) {
		if (index[i] >= 1) {
			for (int j = 0; j < index[i]; j++) {
				printf("%d\n", i);
			}
		}
	}
	return 0;
}
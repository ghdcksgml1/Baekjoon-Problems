#include <stdio.h>


int main(void) {
	int N;
	int n3 = 0, n5 = 0;

	scanf("%d", &N);
	n5 = N / 5;
	while (1) {
		if ((N - 5 * n5) == 0) {
			printf("%d\n", n3 + n5);
			break;
		}
		else if((N - 5 * n5)%3 == 0) {
			n3 = (N - 5 * n5) / 3;
			printf("%d\n", n3 + n5);
			break;
		}
		else {
			n5--;
		}
		if (n5 < 0) {
			printf("%d\n", n5);
			break;
		}
	}
	

	return 0;
}
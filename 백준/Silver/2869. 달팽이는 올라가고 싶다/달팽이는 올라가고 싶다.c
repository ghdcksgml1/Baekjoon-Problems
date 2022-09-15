#include <stdio.h>

int main(void) {
	int a,b, v;
	int count = 0;
	int sum = 0;
	scanf("%d %d %d", &a, &b, &v);

	
	//(a-b)*i>=v
	if ((v - a) % (a - b) == 0) count = (v - a) / (a - b) + 1;
	else if ((v - a) % (a - b) > 0) count = (v - a) / (a - b) + 2;


	printf("%d\n", count);

	return 0;
}
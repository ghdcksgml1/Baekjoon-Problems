#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>

using namespace std;

int tree[2187][2187];
int N;
int n_1 = 0;
int n0 = 0;
int n1 = 0;

void ninetree(int x, int y, int size) {
	int num1=0, num2=0, num3=0; // num1: -1, num2: 0, num3: 1
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (tree[i][j] == -1) {
				num1++;
			}
			else if (tree[i][j] == 0){
				num2++;
			}
			else {
				num3++;
			}
		}
	}
	if (num1 == size*size) {
		n_1++;
		return;
	}
	else if (num2 == size*size) {
		n0++;
		return;
	}
	else if (num3 == size*size) {
		n1++;
		return;
	}
	int div = size / 3;
	ninetree(x, y, div);// 0,0
	ninetree(x+div, y, div);// 3,0
	ninetree(x+2*div, y, div);// 6,0
	ninetree(x, y+div, div);// 0,3
	ninetree(x+div, y+div, div);// 3,3
	ninetree(x+2*div, y+div, div);// 6,3
	ninetree(x, y+2*div, div);// 0,6
	ninetree(x+div, y+2*div, div);// 3,6
	ninetree(x+2*div, y+2*div, div);// 6,6
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &tree[i][j]);
		}
	}
	
	
	ninetree(0, 0, N);
	printf("%d\n%d\n%d\n", n_1, n0, n1);
}

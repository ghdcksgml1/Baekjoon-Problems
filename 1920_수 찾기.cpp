#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int n[100000];
int d[100000];
int result = 0;
void binarysearch(int x,int start ,int end) {
	if (start == end) {
		if (n[start] == x) {
			d[result] = 1;
			result++;
			return;
		}
		else {
			d[result] = 0;
			result++;
			return;
		}
	}
	int middle = (end+start) / 2;
	if (x > n[middle]) {
		binarysearch(x, middle + 1,end);
	}
	else {
		binarysearch(x, 0, middle);
	}
}

int main(void) {
	int nn;
	scanf("%d",&N);
	for (int i=0; i < N; i++) {
		scanf("%d", &n[i]);
	}
	sort(n,n+N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &nn);
		binarysearch(nn, 0, N);
	}
	for (int i = 0; i < M; i++) {
		printf("%d\n", d[i]);
	}
}
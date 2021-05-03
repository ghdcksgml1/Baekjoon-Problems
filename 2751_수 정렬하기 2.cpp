#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;
int a[1000001];
int sorted[1000001];

void merge(int start,int end,int middle) {
	int i = start;
	int j = middle + 1;
	int k = start;
	while (i <= middle && j <= end) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else{
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
// i의 값이 middle보다 크다 = i 값이 다 들어갔다는소리
		for (int t = j; t <= end; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	//정렬된 배열 삽입
	for (int t = start; t <= end; t++) {
		a[t] = sorted[t];
	}
}
void mergeSort(int start, int end) {
	if (start < end) {
		int middle =  (start+end) / 2;
		mergeSort(start, middle);
		mergeSort(middle+1, end);
		merge(start, end, middle);
	}
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	mergeSort(0, N - 1);
	for (int i = 0; i < N; i++) {
		printf("%d\n", a[i]);
	}
}
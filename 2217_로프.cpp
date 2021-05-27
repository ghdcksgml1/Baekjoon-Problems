#include <iostream>
#include <queue>
using namespace std;
int N;
int N_arr[100001];
int sorted[100001];
priority_queue<int> pq;
void merge(int start, int end, int middle) {
	int i = start;
	int j = middle+1;
	int k = start;
	while (i <= middle && j <= end) {
		if (N_arr[i] >= N_arr[j]) {
			sorted[k] = N_arr[i];
			i++;
		}
		else {
			sorted[k] = N_arr[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		for (int t = j; t <= end; t++) {
			sorted[k] = N_arr[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = N_arr[t];
			k++;
		}
	}
	for (int i = start; i <= end; i++) {
		N_arr[i] = sorted[i];
	}
}
void mergeSort(int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;
		mergeSort(start, middle);
		mergeSort(middle+1, end);
		merge(start, end, middle);
	}
}
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> N_arr[i];
	}
	mergeSort(0, N - 1);
	for (int i = 0; i < N; i++) {
		pq.push(N_arr[i] * (i + 1));
	}
	cout << pq.top() << '\n';
}
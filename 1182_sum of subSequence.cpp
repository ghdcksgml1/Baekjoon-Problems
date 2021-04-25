#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int N, S;
int arr[21];
int cnt;

void func(int cur, int tot) {
	if (cur == N) {
		if (tot == S) {
			cnt++;
		}
		return;
	}
	func(cur + 1, tot);
	func(cur + 1, tot + arr[cur]);
}

int main(void) {
	int result = 0;
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	
	func(0, 0);
	if (S == 0) cnt--;
	cout << cnt;
}
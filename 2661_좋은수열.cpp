#include <iostream>
#include <queue>
#include <string>
using namespace std;
int N;
int cnt = 0;
void backTracking(int x,string str,int ind) {
	int len = str.length(); // 현재 str의 길이 저장
	// 나쁜수열을 찾아내는 과정 
	for (int i = 1; i <= len / 2; i++) {
		// 나쁜수열의 조건
		if (str.substr(len - i, i) == str.substr(len - (i * 2), i)) {
			return;
		}
	}
	// 좋은수열을 찾으면 첫번째 찾은값이 가장 작은값이므로
	// cnt를 1로 만들어 빠져나갈수 있게 설정
	if (x == N) {
		cout << str << '\n';
		cnt = 1;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (i == ind) continue;
		backTracking(x + 1, str+to_string(i),i);
		if (cnt == 1) return; // 함수를 들어갔다 나온 cnt의 결과가 1이면 종료
	}
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	backTracking(0, "",0);
}
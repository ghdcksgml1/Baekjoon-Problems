#include <iostream>
#include <queue>
#include <string>
using namespace std;
int N;
int cnt = 0;
void backTracking(int x,string str,int ind) {
	int len = str.length(); // ���� str�� ���� ����
	// ���ۼ����� ã�Ƴ��� ���� 
	for (int i = 1; i <= len / 2; i++) {
		// ���ۼ����� ����
		if (str.substr(len - i, i) == str.substr(len - (i * 2), i)) {
			return;
		}
	}
	// ���������� ã���� ù��° ã������ ���� �������̹Ƿ�
	// cnt�� 1�� ����� ���������� �ְ� ����
	if (x == N) {
		cout << str << '\n';
		cnt = 1;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (i == ind) continue;
		backTracking(x + 1, str+to_string(i),i);
		if (cnt == 1) return; // �Լ��� ���� ���� cnt�� ����� 1�̸� ����
	}
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	backTracking(0, "",0);
}
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N; // ������ ũ��
char n_arr[30][30];
vector<int> cnt; // ������ ���� ��
int num = 0; // ������ ����
void dfs(int x,int y,int numm) {
	// ���� ������ ����� return
	if (x < 0 || y < 0 || x >= N || y >= N) return;
	// ������ 0�� �ƴϸ�
	if (n_arr[x][y] != '0') {
		n_arr[x][y] = '0'; // �湮ǥ��
		cnt[numm]++; // ������ ���� ���� ����
		dfs(x + 1, y, numm); // ������
		dfs(x, y + 1, numm); // ����
		dfs(x - 1, y, numm); // ����
		dfs(x, y - 1, numm); // �Ʒ���
	}
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n_arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (n_arr[i][j] == '1') {
				cnt.push_back(0);
				dfs(i, j,num);
				num++;
			}
		}
	}
	cout << num << '\n';
	// ������������ ����
	sort(cnt.begin(), cnt.end());
	for (int i = 0; i < cnt.size(); i++) {
		cout << cnt[i] << '\n';
	}
}
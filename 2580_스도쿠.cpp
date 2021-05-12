#include <iostream>
#include <vector>
using namespace std;
int n_arr[9][9]; // ������ ��
vector<pair<int, int>> q; // 0 ���� ��ǥ
int trigger = 0; // Ʈ���Ÿ� ���� ���� �߸��Ǿ������ �������� �� �ֵ����Ѵ�.
void backTracking(int x) {
	if (x == q.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << n_arr[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}
	int v[9] = { 0, }; // 1 2 3 4 5 6 7 8 9
	vector<int> not_selected;
	// ��,�� �˻�
	for (int i = 0; i < 9; i++) {
		if (n_arr[q[x].first][i] != 0) {
			v[n_arr[q[x].first][i] - 1] = 1;
		}
		if (n_arr[i][q[x].second] != 0) {
			v[n_arr[i][q[x].second] - 1] = 1;
		}
	}
	// 3x3 �˻�
	int x_x = (q[x].first / 3) * 3;
	int y_y = (q[x].second / 3) * 3;
	for (int i = x_x; i < (x_x + 3); i++) {
		for (int j = y_y; j < (y_y + 3); j++) {
			if (n_arr[i][j] != 0) {
				v[n_arr[i][j] - 1] = 1;
			}
		}
	}
	// ���õ��� ���� ������ �־��ش�.
	for (int i = 0; i < 9; i++) {
		if (v[i] == 0) {
			not_selected.push_back(i+1);
		}
	}
	// ��ĭ�� ���� ���� ��Ȯ�ϴٸ�, x�� ��� �����ϹǷ�,
	// for���� �����ԵǸ�, trigger�� 1�� �ٲ� ���������� �������ش�.
	for (int i = 0; i < not_selected.size(); i++) {
		n_arr[q[x].first][q[x].second] = not_selected[i];
		backTracking(x + 1);
		if (trigger == 1) {
			n_arr[q[x].first][q[x].second] = 0;
			trigger = 0;
		}
	}
	trigger = 1;
}

int main(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> n_arr[i][j];
			if (n_arr[i][j] == 0) {
				q.push_back({ i,j });
			}
		}
	}
	backTracking(0);
}
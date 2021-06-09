#include <iostream>

using namespace std;
int n, m, x, y, k, call;

int dice[7];
int temp[7];

int map[21][21];

// ���ǿ� ����,
// ������ �ٴ��� 0�ΰ��, �ֻ����� �ظ��� �����ϰ�,
// 0�� �ƴҰ��, �ֻ����� �ظ鿡 ������ ���� �����ϰ�, ������ 0���� �ٲ۴�.
// �ֻ����� ������ dice[1]�� ���.
void change_floor() {
	if (map[x][y] == 0) {
		map[x][y] = dice[6];
	}
	else {
		dice[6] = map[x][y];
		map[x][y] = 0;
	}
	cout << dice[1] << '\n';
	return;
}
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> call;
		// �� : 1, �� : 2, �� : 3, �� : 4
		if (call == 1) { // ��
			if (y + 1 < m) {
				y += 1;
				temp[1] = dice[1];
				temp[3] = dice[3];
				temp[4] = dice[4];
				temp[6] = dice[6];

				dice[1] = temp[4];
				dice[3] = temp[1];
				dice[4] = temp[6];
				dice[6] = temp[3];
				change_floor();
			}
		}
		else if (call == 2) { // ��
			if (y - 1 >= 0) {
				y -= 1;
				temp[1] = dice[1];
				temp[3] = dice[3];
				temp[4] = dice[4];
				temp[6] = dice[6];

				dice[1] = temp[3];
				dice[3] = temp[6];
				dice[4] = temp[1];
				dice[6] = temp[4];
				change_floor();
			}
		}
		else if (call == 3) { // ��
			if (x - 1 >= 0) {
				x -= 1;
				temp[1] = dice[1];
				temp[2] = dice[2];
				temp[5] = dice[5];
				temp[6] = dice[6];

				dice[1] = temp[5];
				dice[2] = temp[1];
				dice[5] = temp[6];
				dice[6] = temp[2];
				change_floor();
			}
		}
		else if (call == 4) { // ��
			if (x + 1 < n) {
				x += 1;
				temp[1] = dice[1];
				temp[2] = dice[2];
				temp[5] = dice[5];
				temp[6] = dice[6];

				dice[1] = temp[2];
				dice[2] = temp[6];
				dice[5] = temp[1];
				dice[6] = temp[5];
				change_floor();
			}
		}
	}
}

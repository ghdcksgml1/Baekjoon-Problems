#include <iostream>

using namespace std;
int n, m, x, y, k, call;

int dice[7];
int temp[7];

int map[21][21];

// 조건에 따라서,
// 지도의 바닥이 0인경우, 주사위의 밑면을 복사하고,
// 0이 아닐경우, 주사위의 밑면에 지도의 값을 복사하고, 지도는 0으로 바꾼다.
// 주사위의 윗면인 dice[1]을 출력.
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
		// 동 : 1, 서 : 2, 북 : 3, 남 : 4
		if (call == 1) { // 동
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
		else if (call == 2) { // 서
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
		else if (call == 3) { // 북
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
		else if (call == 4) { // 남
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

#include <iostream>

using namespace std;
int T, N;
char cube[6][3][3];
string rotation;
char tmp[3];

void setting_cube() {
	char cube_color[6] = { 'w','y','r','o','g','b' };

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cube[i][j][k] = cube_color[i];
			}
		}
	}
}
void rotate_myself_90(int dir, char p_Or_m) {
	int temp[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp[i][j] = cube[dir][i][j];
		}
	}

	if (p_Or_m == '+') {
		cube[dir][0][0] = temp[2][0]; cube[dir][1][0] = temp[2][1]; cube[dir][2][0] = temp[2][2];
		cube[dir][0][1] = temp[1][0]; cube[dir][1][1] = temp[1][1]; cube[dir][2][1] = temp[1][2];
		cube[dir][0][2] = temp[0][0]; cube[dir][1][2] = temp[0][1]; cube[dir][2][2] = temp[0][2];
		return;
	}
	else {
		cube[dir][0][0] = temp[0][2]; cube[dir][1][0] = temp[0][1]; cube[dir][2][0] = temp[0][0];
		cube[dir][0][1] = temp[1][2]; cube[dir][1][1] = temp[1][1]; cube[dir][2][1] = temp[1][0];
		cube[dir][0][2] = temp[2][2]; cube[dir][1][2] = temp[2][1]; cube[dir][2][2] = temp[2][0];
		return;
	}
}
/*
U+ : F:123 > L:123 > B:987 > R:123
U- : F:123 > R:123 > B:987 > L:123

D+ : F:789 > R:789 > B:321 > L:789
D- : F:789 > L:789 > B:321 > R:789

F+ : U:789 > R:147 > D:321 > L:963
F- : U:789 > L:963 > D:321 > R:147

B+ : U:123 > L:741 > D:987 > R:369
B- : U:123 > R:369 > D:987 > L:741

L+ : U:147 > F:147 > D:147 > B:147
L- : U:147 > B:147 > D:147 > F:147

R+ : U:369 > B:369 > D:369 > F:369
R- : U:369 > F:369 > D:369 > B:369
U:0 , D:1 , F:2 , B:3 , L:4 , R:5
*/
void rotate_cube(int dir, char p_Or_m) {
	if (dir == 0) {
		if (p_Or_m == '+') {
			for (int i = 0; i < 3; i++) tmp[i] = cube[2][0][i];
			for (int i = 0; i < 3; i++) cube[2][0][i] = cube[5][0][i];
			for (int i = 0; i < 3; i++) cube[5][0][i] = cube[3][2][2 - i];
			for (int i = 0; i < 3; i++) cube[3][2][2 - i] = cube[4][0][i];
			for (int i = 0; i < 3; i++) cube[4][0][i] = tmp[i];
			return;
		}
		else {
			for (int i = 0; i < 3; i++) tmp[i] = cube[2][0][i];
			for (int i = 0; i < 3; i++) cube[2][0][i] = cube[4][0][i];
			for (int i = 0; i < 3; i++) cube[4][0][i] = cube[3][2][2 - i];
			for (int i = 0; i < 3; i++) cube[3][2][2 - i] = cube[5][0][i];
			for (int i = 0; i < 3; i++) cube[5][0][i] = tmp[i];
			return;
		}
	}
	if (dir == 1) {
		if (p_Or_m == '+') {
			for (int i = 0; i < 3; i++) tmp[i] = cube[2][2][i];
			for (int i = 0; i < 3; i++) cube[2][2][i] = cube[4][2][i];
			for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][0][2 - i];
			for (int i = 0; i < 3; i++) cube[3][0][2 - i] = cube[5][2][i];
			for (int i = 0; i < 3; i++) cube[5][2][i] = tmp[i];
			return;
		}
		else {
			for (int i = 0; i < 3; i++) tmp[i] = cube[2][2][i];
			for (int i = 0; i < 3; i++) cube[2][2][i] = cube[5][2][i];
			for (int i = 0; i < 3; i++) cube[5][2][i] = cube[3][0][2 - i];
			for (int i = 0; i < 3; i++) cube[3][0][2 - i] = cube[4][2][i];
			for (int i = 0; i < 3; i++) cube[4][2][i] = tmp[i];
			return;
		}
	}
	// U:0 , D:1 , F:2 , B:3 , L:4 , R:5
	if (dir == 2) {
		if (p_Or_m == '+') {
			for (int i = 0; i < 3; i++) tmp[i] = cube[0][2][i];
			for (int i = 0; i < 3; i++) cube[0][2][i] = cube[4][2 - i][2];
			for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[1][0][2 - i];
			for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[5][i][0];
			for (int i = 0; i < 3; i++) cube[5][i][0] = tmp[i];
			return;
		}
		else {
			for (int i = 0; i < 3; i++) tmp[i] = cube[0][2][i];
			for (int i = 0; i < 3; i++) cube[0][2][i] = cube[5][i][0];
			for (int i = 0; i < 3; i++) cube[5][i][0] = cube[1][0][2 - i];
			for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[4][2 - i][2];
			for (int i = 0; i < 3; i++) cube[4][2 - i][2] = tmp[i];
			return;
		}
	}
	// U:0 , D:1 , F:2 , B:3 , L:4 , R:5
	if (dir == 3) {
		if (p_Or_m == '+') {
			for (int i = 0; i < 3; i++) tmp[i] = cube[0][0][i];
			for (int i = 0; i < 3; i++) cube[0][0][i] = cube[5][i][2];
			for (int i = 0; i < 3; i++) cube[5][i][2] = cube[1][2][2 - i];
			for (int i = 0; i < 3; i++) cube[1][2][2 - i] = cube[4][2 - i][0];
			for (int i = 0; i < 3; i++) cube[4][2 - i][0] = tmp[i];
			return;
		}
		else {
			for (int i = 0; i < 3; i++) tmp[i] = cube[0][0][i];
			for (int i = 0; i < 3; i++) cube[0][0][i] = cube[4][2 - i][0];
			for (int i = 0; i < 3; i++) cube[4][2 - i][0] = cube[1][2][2 - i];
			for (int i = 0; i < 3; i++) cube[1][2][2 - i] = cube[5][i][2];
			for (int i = 0; i < 3; i++) cube[5][i][2] = tmp[i];
			return;
		}
	}
	// U:0 , D:1 , F:2 , B:3 , L:4 , R:5
	if (dir == 4) {
		if (p_Or_m == '+') {
			for (int i = 0; i < 3; i++) tmp[i] = cube[0][i][0];
			for (int i = 0; i < 3; i++) cube[0][i][0] = cube[3][i][0];
			for (int i = 0; i < 3; i++) cube[3][i][0] = cube[1][i][0];
			for (int i = 0; i < 3; i++) cube[1][i][0] = cube[2][i][0];
			for (int i = 0; i < 3; i++) cube[2][i][0] = tmp[i];
			return;
		}
		else {
			for (int i = 0; i < 3; i++) tmp[i] = cube[0][i][0];
			for (int i = 0; i < 3; i++) cube[0][i][0] = cube[2][i][0];
			for (int i = 0; i < 3; i++) cube[2][i][0] = cube[1][i][0];
			for (int i = 0; i < 3; i++) cube[1][i][0] = cube[3][i][0];
			for (int i = 0; i < 3; i++) cube[3][i][0] = tmp[i];
			return;
		}
	}
	// U:0 , D:1 , F:2 , B:3 , L:4 , R:5
	if (dir == 5) {
		if (p_Or_m == '+') {
			for (int i = 0; i < 3; i++) tmp[i] = cube[0][i][2];
			for (int i = 0; i < 3; i++) cube[0][i][2] = cube[2][i][2];
			for (int i = 0; i < 3; i++) cube[2][i][2] = cube[1][i][2];
			for (int i = 0; i < 3; i++) cube[1][i][2] = cube[3][i][2];
			for (int i = 0; i < 3; i++) cube[3][i][2] = tmp[i];
			return;
		}
		else {
			for (int i = 0; i < 3; i++) tmp[i] = cube[0][i][2];
			for (int i = 0; i < 3; i++) cube[0][i][2] = cube[3][i][2];
			for (int i = 0; i < 3; i++) cube[3][i][2] = cube[1][i][2];
			for (int i = 0; i < 3; i++) cube[1][i][2] = cube[2][i][2];
			for (int i = 0; i < 3; i++) cube[2][i][2] = tmp[i];
			return;
		}
	}
}
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}

int main(int argc, const char * argv[]) {
	init();

	cin >> T;
	while (T--) {
		setting_cube();
		cin >> N;
		while (N--) {
			cin >> rotation;
			int direction = 0;
			if (rotation[0] == 'U') direction = 0;
			if (rotation[0] == 'D') direction = 1;
			if (rotation[0] == 'F') direction = 2;
			if (rotation[0] == 'B') direction = 3;
			if (rotation[0] == 'L') direction = 4;
			if (rotation[0] == 'R') direction = 5;
			rotate_myself_90(direction, rotation[1]);
			rotate_cube(direction, rotation[1]);

		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[0][i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}
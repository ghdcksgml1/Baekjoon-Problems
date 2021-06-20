#include <iostream>
#include <string>
#define MAX 101
using namespace std;
int N;
int x, y, d, g;
int square_cnt = 0;
int graph[MAX][MAX];

// string���� ��߹��⺰ ������ �̵������� �� �ִ�.
// 0: x��ǥ�� �����ϴ� ���� (��)
// 1: y��ǥ�� �����ϴ� ����(��)
// 2 : x��ǥ�� �����ϴ� ����(��)
// 3 : y��ǥ�� �����ϴ� ����(��)
// ex. dp[0][1] = "01" , dp[0][2] = "0121"
string dp[4][11]; 

// ���簢���� ������ ���ϴ� �Լ�
void square_check() {
	for (int i = 0; i < MAX-1; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			// �������ִ� 4������ graph�� ���� ��� 1�̸� 1x1 ���簢���̴�.
			if (graph[i][j] == 1 && graph[i][j + 1] == 1 && graph[i + 1][j] == 1 && graph[i + 1][j + 1] == 1) {
				square_cnt++;
			}
		}
	}
}
// ���밡 �ö󰡸� ���� ������ �巡�� Ŀ�긦 90�� ȸ������ �ٿ��ִ� �Լ�
void curve_90(int direction, int generation) {
	string prev = dp[direction][generation - 1];
	// ���ǻ��� : �� �������� �������!!
	// ���������ؾ� ��Ģ�� �����.
	// ex. dp[0][2] �϶� 1,2,3,4 4���� �̵��� �ϴµ�
	// dp[0][2]�� dp[0][1]�� �ð�������� 90�� ��ŭ ȸ�� �������Ƿ�
	// dp[0][2]�� 3��°�� 2��°�� �ð�������� 90�� ��ŭ ȸ����Ų ����
	// dp[0][2]�� 4��°�� 1��°�� �ð�������� 90�� ��ŭ ȸ����Ų �����̴�.
	for (int i = prev.size() - 1; i >= 0; i--) {
		if (prev[i] == '0') {
			prev += "1";
		}
		else if (prev[i] == '1') {
			prev += "2";
		}
		else if (prev[i] == '2') {
			prev += "3";
		}
		else if (prev[i] == '3') {
			prev += "0";
		}
	}
	dp[direction][generation] = prev;
}

void dynamicProgramming(int direction,int generation) {
	if (generation == 0) {
		dp[direction][generation] = to_string(direction);
		return;
	}
	// dp���� ����Ǿ� ������
	if (dp[direction][generation] != "") return;
	// dp���� ����Ǿ� ���� ���� ��
	else {
		// ����-1 ������ ���� ���Ϸ�����.
		dynamicProgramming(direction, generation - 1);
		// ���� ������ ���� ���Ѵ�.
		curve_90(direction, generation);
		return;
	}

}
// dp�� ����Ǿ� �ִ´�� �����̸鼭, graph�� 1�� �������ִ� �Լ�
void go_dragonCurve(int g_x, int g_y, string dir) {
	graph[g_y][g_x] = 1;
	for (int i = 0; dir[i] != NULL; i++) {
		if (dir[i] == '0') {
			g_x += 1;
			graph[g_y][g_x] = 1;
		}
		else if (dir[i] == '1') {
			g_y -= 1;
			graph[g_y][g_x] = 1;
		}
		else if (dir[i] == '2') {
			g_x -= 1;
			graph[g_y][g_x] = 1;
		}
		else if (dir[i] == '3') {
			g_y += 1;
			graph[g_y][g_x] = 1;
		}
	}
}

void init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main(void) {
	init();
	cin >> N;
	while (N--) {
		cin >> x >> y >> d >> g;
		dynamicProgramming(d, g);
		go_dragonCurve(x, y, dp[d][g]);
	}
	square_check();
	cout << square_cnt << '\n';
	return 0;
}

#include <iostream>
#include <string>
#define MAX 101
using namespace std;
int N;
int x, y, d, g;
int square_cnt = 0;
int graph[MAX][MAX];

// string에는 출발방향별 세대의 이동방향이 들어가 있다.
// 0: x좌표가 증가하는 방향 (→)
// 1: y좌표가 감소하는 방향(↑)
// 2 : x좌표가 감소하는 방향(←)
// 3 : y좌표가 증가하는 방향(↓)
// ex. dp[0][1] = "01" , dp[0][2] = "0121"
string dp[4][11]; 

// 정사각형의 개수를 구하는 함수
void square_check() {
	for (int i = 0; i < MAX-1; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			// 인접해있는 4구간의 graph의 값이 모두 1이면 1x1 정사각형이다.
			if (graph[i][j] == 1 && graph[i][j + 1] == 1 && graph[i + 1][j] == 1 && graph[i + 1][j + 1] == 1) {
				square_cnt++;
			}
		}
	}
}
// 세대가 올라가면 이전 세대의 드래곤 커브를 90도 회전시켜 붙여주는 함수
void curve_90(int direction, int generation) {
	string prev = dp[direction][generation - 1];
	// 주의사항 : 꼭 역순으로 해줘야함!!
	// 역순으로해야 규칙이 생긴다.
	// ex. dp[0][2] 일때 1,2,3,4 4번의 이동을 하는데
	// dp[0][2]는 dp[0][1]을 시계방향으로 90도 만큼 회전 시켰으므로
	// dp[0][2]의 3번째는 2번째를 시계방향으로 90도 만큼 회전시킨 방향
	// dp[0][2]의 4번째는 1번째를 시계방향으로 90도 만큼 회전시킨 방향이다.
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
	// dp값이 저장되어 있을때
	if (dp[direction][generation] != "") return;
	// dp값이 저장되어 있지 않을 때
	else {
		// 현재-1 세대의 값을 구하러간다.
		dynamicProgramming(direction, generation - 1);
		// 현재 세대의 값을 구한다.
		curve_90(direction, generation);
		return;
	}

}
// dp에 저장되어 있는대로 움직이면서, graph에 1을 저장해주는 함수
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

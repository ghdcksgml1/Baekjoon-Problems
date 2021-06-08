#include <iostream>
#include <queue>
using namespace std;
int N;
int N_arr[100][100];
int apple_num,turn_num;

void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}

int main(void) {
	init();
	cin >> N;
	cin >> apple_num;
	while (apple_num--) {
		int n1;
		int n2;
		cin >> n1>> n2;
		N_arr[n1-1][n2-1] = 2; // 사과는 2로 표시
	}
	queue<pair<int, char>> direction_infor;
	cin >> turn_num;
	while (turn_num--) {
		int n1; char c1;
		cin >> n1 >> c1;
		direction_infor.push({ n1,c1 });
	}
	queue<pair<int,int>> tail; // 꼬리의 인덱스를 저장하는 큐
	int N_len = 1; // 처음 지렁이의 길이는 1
	int second = -1; // (0,0)에서 시작하므로
	int direction = 3; // 상:0 ,하:1 ,좌:2 ,우:3
	int i = 0; int j = 0;
	while (true) {
		second++;
		// 게임이 끝나는 조건
		if (N_arr[i][j] == 1 || i < 0 || j < 0 || i >= N || j >= N) {
			cout << second << '\n';
			return 0;
		}
		// 이동
		if (!tail.empty() && N_arr[i][j] != 2) {
			auto cur = tail.front();
			N_arr[cur.first][cur.second] = 0;
			tail.pop();
		}
		else if (N_arr[i][j] == 2)	N_len++;
		N_arr[i][j] = 1;
		tail.push({ i,j });
		// 방향정보
		if (!direction_infor.empty()) {
			auto infor = direction_infor.front();
			if (second == infor.first) {
				if (infor.second == 'D') {
					if (direction == 0) direction = 3;
					else if (direction == 1) direction = 2;
					else if (direction == 2) direction = 0;
					else if (direction == 3) direction = 1;
				}
				else {
					if (direction == 0) direction = 2;
					else if (direction == 1) direction = 3;
					else if (direction == 2) direction = 1;
					else if (direction == 3) direction = 0;
				}
				direction_infor.pop();
			}
		}
		// 방향에 맞춰 인덱스 값을 조정해준다.
		if (direction == 0) i--;
		else if (direction == 1) i++;
		else if (direction == 2) j--;
		else if (direction == 3) j++;
	}
}

/*
0aa0aaa000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000

*/
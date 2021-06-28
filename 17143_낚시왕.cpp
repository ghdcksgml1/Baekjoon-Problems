#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int R, C, M;
int r, c, s, d, z; // s 속력 d 이동방향 z 크기  1:위,2:아래,3:오른쪽,4:왼쪽
int row, col, spd, dir, siz, dist;
int cnt = 0;
int graph[MAX][MAX];

typedef pair<pair<pair<int, int>, pair<int, int>>, pair<int, int>> pp;
vector<pair<int,int>> eat[MAX][MAX]; // 상어의 인덱스와 상어의 크기를 저장해놓은 vector
vector<pp> shark_infor; // 상어의 정보

// 상어의 움직임
pp shark_moving(int row,int col,int spd,int dir,int siz,int dist) {
	// 위
	if (dir == 1) {
		if (row - dist > 0) {
			row -= dist;
			return { {{row,col},{spd,dir}},{siz, spd} };
		}
		else {
			dist -= (row - 1);
			row -= (row - 1);
			dir = 2;
			return shark_moving(row,col,spd,dir,siz,dist);
		}
	}
	// 아래
	else if (dir == 2) {
		if (row + dist <= R) {
			row += dist;
			return { {{row,col},{spd,dir}},{siz, spd} };
		}
		else {
			dist -= (R - row);
			row += (R - row);
			dir = 1;
			return shark_moving(row, col, spd, dir, siz, dist);
		}
	}
	// 왼쪽
	else if (dir == 3) {
		if (col + dist <= C) {
			col += dist;
			return { {{row,col},{spd,dir}},{siz, spd} };
		}
		else {
			dist -= (C - col);
			col += (C - col);
			dir = 4;
			return shark_moving(row, col, spd, dir, siz, dist);
		}
	}
	// 오른쪽
	else if (dir == 4) {
		if (col - dist > 0) {
			col -= dist;
			return { {{row,col},{spd,dir}},{siz, spd} };
		}
		else {
			dist -= (col - 1);
			col -= (col - 1);
			dir = 3;
			return shark_moving(row, col, spd, dir, siz, dist);
		}
	}
}

void init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main(void) {
	init();
	cin >> R >> C >> M;
	while (M--) {
		cin >> r >> c >> s >> d >> z;
		shark_infor.push_back({ {{r,c},{s,d}},{z, s} });
	}
	for (int fisher = 1; fisher <= C; fisher++) {
		// 낚시꾼의 열에서 가장 가까운 상어를 찾기위해
		sort(shark_infor.begin(), shark_infor.end()); 
		
		// 열이 같은 상어를 찾는다
		for (int i = 0; i < shark_infor.size(); i++) {
			col = shark_infor[i].first.first.second;
			siz = shark_infor[i].second.first;

			// 가장 먼저 찾은게 가장 가까운 상어이므로
			// if문을 적용한뒤 바로 break;
			if (col == fisher) {
				shark_infor[i] = { {{0,0},{0,0}},{0, 0} };
				cnt += siz; // 상어의 크기만큼 더해준다.
				break;
			}
		}

		// 모든 상어를 s만큼 움직이기
		for (int i = 0; i < shark_infor.size(); i++) {
			row = shark_infor[i].first.first.first; // r
			col = shark_infor[i].first.first.second; // c
			spd = shark_infor[i].first.second.first; // s
			dir = shark_infor[i].first.second.second; // d
			siz = shark_infor[i].second.first; // z
			dist = shark_infor[i].second.second;

			// col == 0 이면 잡아먹히거나, 잡힌상어이므로 continue;
			if (col == 0) continue;

			shark_infor[i] = shark_moving(row, col, spd, dir, siz, dist);

			// 이동을 마친 상어의 r,c,z 값
			row = shark_infor[i].first.first.first;
			col = shark_infor[i].first.first.second;
			siz = shark_infor[i].second.first;

			// eat vector에 값이 이미 들어 있다면, 상어가 같은 좌표에 위치하는 경우임
			if (eat[row][col].size() == 1) {
				// 사이즈가 기존보다 크다면
				if (eat[row][col][0].second < siz) {
					// 기존상어는 잡아먹히고, 사이즈가 큰 상어로 좌표와 사이즈를 업데이트
					shark_infor[eat[row][col][0].first] = { {{0,0},{0,0}},{0, 0} };
					eat[row][col][0] = { i,siz };
				}
				// 사이즈가 기존보다 작다면
				else {
					// 새로운 상어는 기존상어에게 잡아먹힘
					shark_infor[i] = { {{0,0},{0,0}},{0, 0} };
				}
			}
			// vector에 값이 없다면
			else {
				// 새로운 vector 추가
				eat[row][col].push_back({ i,siz });
			}
		}
		// 상어는 매 초마다 위치가 달라지므로, eat의 vector를 초기화해준다.
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				eat[i][j].clear();
			}
		}
	}
	cout << cnt << '\n';
}
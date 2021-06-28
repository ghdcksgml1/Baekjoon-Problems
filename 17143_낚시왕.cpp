#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int R, C, M;
int r, c, s, d, z; // s �ӷ� d �̵����� z ũ��  1:��,2:�Ʒ�,3:������,4:����
int row, col, spd, dir, siz, dist;
int cnt = 0;
int graph[MAX][MAX];

typedef pair<pair<pair<int, int>, pair<int, int>>, pair<int, int>> pp;
vector<pair<int,int>> eat[MAX][MAX]; // ����� �ε����� ����� ũ�⸦ �����س��� vector
vector<pp> shark_infor; // ����� ����

// ����� ������
pp shark_moving(int row,int col,int spd,int dir,int siz,int dist) {
	// ��
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
	// �Ʒ�
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
	// ����
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
	// ������
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
		// ���ò��� ������ ���� ����� �� ã������
		sort(shark_infor.begin(), shark_infor.end()); 
		
		// ���� ���� �� ã�´�
		for (int i = 0; i < shark_infor.size(); i++) {
			col = shark_infor[i].first.first.second;
			siz = shark_infor[i].second.first;

			// ���� ���� ã���� ���� ����� ����̹Ƿ�
			// if���� �����ѵ� �ٷ� break;
			if (col == fisher) {
				shark_infor[i] = { {{0,0},{0,0}},{0, 0} };
				cnt += siz; // ����� ũ�⸸ŭ �����ش�.
				break;
			}
		}

		// ��� �� s��ŭ �����̱�
		for (int i = 0; i < shark_infor.size(); i++) {
			row = shark_infor[i].first.first.first; // r
			col = shark_infor[i].first.first.second; // c
			spd = shark_infor[i].first.second.first; // s
			dir = shark_infor[i].first.second.second; // d
			siz = shark_infor[i].second.first; // z
			dist = shark_infor[i].second.second;

			// col == 0 �̸� ��Ƹ����ų�, ��������̹Ƿ� continue;
			if (col == 0) continue;

			shark_infor[i] = shark_moving(row, col, spd, dir, siz, dist);

			// �̵��� ��ģ ����� r,c,z ��
			row = shark_infor[i].first.first.first;
			col = shark_infor[i].first.first.second;
			siz = shark_infor[i].second.first;

			// eat vector�� ���� �̹� ��� �ִٸ�, �� ���� ��ǥ�� ��ġ�ϴ� �����
			if (eat[row][col].size() == 1) {
				// ����� �������� ũ�ٸ�
				if (eat[row][col][0].second < siz) {
					// �������� ��Ƹ�����, ����� ū ���� ��ǥ�� ����� ������Ʈ
					shark_infor[eat[row][col][0].first] = { {{0,0},{0,0}},{0, 0} };
					eat[row][col][0] = { i,siz };
				}
				// ����� �������� �۴ٸ�
				else {
					// ���ο� ���� �������� ��Ƹ���
					shark_infor[i] = { {{0,0},{0,0}},{0, 0} };
				}
			}
			// vector�� ���� ���ٸ�
			else {
				// ���ο� vector �߰�
				eat[row][col].push_back({ i,siz });
			}
		}
		// ���� �� �ʸ��� ��ġ�� �޶����Ƿ�, eat�� vector�� �ʱ�ȭ���ش�.
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				eat[i][j].clear();
			}
		}
	}
	cout << cnt << '\n';
}
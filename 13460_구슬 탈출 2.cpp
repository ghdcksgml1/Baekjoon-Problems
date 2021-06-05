#include <iostream>
#include <queue>
using namespace std;
int N, M;
char graph[11][11];
bool visited[11][11][11][11];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int red_x, red_y, blue_x, blue_y;
int BFS() {
	queue<pair<pair<int, int>, pair<int, int>>> q; // red�� blue�� ��ǥ�� ����
	q.push({ {red_x,red_y},{blue_x,blue_y} });
	visited[red_x][red_y][blue_x][blue_y] = true;
	int result = 0;

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int redball_x = q.front().first.first;
			int redball_y = q.front().first.second;
			int blueball_x = q.front().second.first;
			int blueball_y = q.front().second.second;
			q.pop();

			if (graph[redball_x][redball_y] == 'O' && graph[redball_x][redball_y] != graph[blueball_x][blueball_y]) {
				// �������� O�� ����������, �Ķ����� ���� O�� �������� ���Ѱ�� Ż�⼺��!
				return result;
			}
			for (int i = 0; i < 4; i++) {
				int red_nx = redball_x;
				int red_ny = redball_y;
				int blue_nx = blueball_x;
				int blue_ny = blueball_y;

				// R�� �������� �б�
				while (graph[red_nx + dx[i]][red_ny + dy[i]] != '#' && graph[red_nx][red_ny] != 'O') {
					red_nx += dx[i];
					red_ny += dy[i];
				}
				// B�� �������� �б�
				while (graph[blue_nx + dx[i]][blue_ny + dy[i]] != '#' && graph[blue_nx][blue_ny] != 'O') {
					blue_nx += dx[i];
					blue_ny += dy[i];
				}
				// �������� ���Ҵµ� R�� B�� ��ġ�� ���
				if (red_nx == blue_nx && red_ny == blue_ny) {
					if (graph[red_nx][blue_ny] == 'O')continue; // �Ѵ� �����Ѱ��
					// R�� B �� �̵� �� ����� ���ʿ� �־�����
					// ###### �̷������� RB�� �پ��ִ°��
					// #O.RB#
					// ######
					if (abs(red_nx - redball_x) + abs(red_ny - redball_y) < abs(blue_nx - blueball_x) + abs(blue_ny - blueball_y)) {
						// R�� B���� ���ʿ� �ִ����
						blue_nx -= dx[i];
						blue_ny -= dy[i];
					}
					else {
						// B�� R ���ʿ� �ִ����
						red_nx -= dx[i];
						red_ny -= dy[i];
					}
				}
				// ���� �Դ� ���̿��ٸ� continue
				// �Դ������� �ٽõ��ư��� ���� ������ �ƹ��� ������ ����.
				if (visited[red_nx][red_ny][blue_nx][blue_ny]) continue;
				q.push({ {red_nx,red_ny},{blue_nx,blue_ny} });
				visited[red_nx][red_ny][blue_nx][blue_ny] = true;
			}
		}
		if (result == 10) return -1;
		result++;
	}
	return -1;
}
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> graph[i];
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 'R') {
				red_x = i; red_y = j;
			}
			else if (graph[i][j] == 'B') {
				blue_x = i; blue_y = j;
			}
		}
	}

	cout << BFS() << '\n';
}
/*
4 6
######
###.##
#O.BR#
######
���� : 2

4 6
######
####.#
#O.RB#
######
���� : 2

5 8
########
#R#....#
#B..#.##
#####O##
########
���� : 8
*/

// R�� ����δ�, B�� ����δ�, R�� �ѹ� �� ��￩�ش�.
// 
#include <iostream>
#include <queue>
using namespace std;
int N, M, cnt, cnt_1, cnt_day , all_0;
int graph[101][101];
int v_sign[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0) {
				all_0++;
			}
		}
	}
	if (all_0 == N * M) {
		cout << "0" << '\n' << "0" << '\n';
		return 0;
	}
	// BFS
	while(1) {
		cnt_day++; // ��¥���� ����
		cnt = 0;  // ������������ Ȯ���ϴ� ����
		cnt_1 = 0; // ������ ������ ġ����� ���� ����
		q.push({ 0,0 });
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (v_sign[nx][ny] == 1) continue; // �湮�Ѱ��̸� continue
				// ġ� �ִ� ĭ������, �湮���� �ʾ�����
				if (graph[nx][ny] == 1 && v_sign[nx][ny] == 0) {
					graph[nx][ny] = 0; // ���������� ġ� ������Ƿ� ġ� ����ĭ ó��
					v_sign[nx][ny] = 1; // �湮ǥ��
					cnt_1++; // �� ���� ġ� � ��������� ����
				}
				else {
					// ġ� ���� ĭ�̰�, �湮���� ���� ĭ�̸�
					if (graph[nx][ny] == 0 && v_sign[nx][ny] == 0) {
						v_sign[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				// �ѷ� �׿��־� 0������ �湮���� ��������� �湮ó������
				if (graph[i][j] == 0 && v_sign[i][j] == 0) v_sign[i][j] = 1;
				// �湮 ���Ѱ� ����
				if (v_sign[i][j] == 0) {
					cnt++;
				}
				// �湮 �ʱ�ȭ
				v_sign[i][j] = 0;
			}
		}
		if (cnt == 0) {
			cout << cnt_day << '\n'<< cnt_1 << '\n';
			return 0;
		}
	}
}
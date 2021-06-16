#include <iostream>
#define MAX 101
using namespace std;
int N, L;
int graph[MAX][MAX];
bool visit[MAX][MAX];

void init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	int cnt = 0; // ��ü ����� ���� count
	/********************************/
	// ����
	for (int i = 0; i < N; i++) {
		int trigger = 0; // 0�̸� ����, 1�̸� ������
		int prev = graph[i][0]; // ���� ���� �����ϴ� ����
		for (int j = 1; j < N; j++) {
			// ���� ���̰� 2�ΰ��� ������
			if (abs(graph[i][j] - prev) >= 2) {
				trigger = 1;
				break;
			}
			// ���� ������ ���� ���� ū ���
			if (graph[i][j] > prev) {
				// L��ŭ �ڷΰ��鼭 ���� ������ Ȯ��
				for (int k = j - 1; k >= j - L; k--) {
					if (k < 0) {
						trigger = 1;
						break;
					}
					else if (visit[i][k]) trigger = 1;
					else if (prev != graph[i][k]) trigger = 1;
				}
				// ������ ��� �湮ǥ��!
				if (!trigger) {
					for (int k = j - 1; k >= j - L; k--) {
						visit[i][k] = true;
					}
				}
			}
			// ���� ������ ���� ���� ���� ���
			if (graph[i][j] < prev) {
				// L-1��ŭ ������ ���鼭 ���� ������ Ȯ��
				for (int k = j ; k <= j + L-1; k++) {
					if (k >= N) {
						trigger = 1;
						break;
					}
					else if (visit[i][k]) trigger = 1;
					else if (graph[i][j] != graph[i][k]) trigger = 1;
				}
				// ������ ��� �湮ǥ��!
				if (!trigger) {
					for (int k = j; k <= j + L - 1; k++) {
						visit[i][k] = true;
					}
				}
			}
			// �������̸� ����
			if (trigger) break;
			// �����̸� prev�� ���簪�� ����
			prev = graph[i][j];
		}
		// �����̸� ���� 1 ����
		if (!trigger) cnt++;
	}
	/********************************/
	// visit �� �ʱ�ȭ
	for (int i=0; i < N; i++) {
		for (int j=0; j < N; j++) {
			visit[i][j] = false;
		}
	}
	/********************************/
	// ����
	for (int i = 0; i < N; i++) {
		int trigger = 0; // 0�̸� ����, 1�̸� ������
		int prev = graph[0][i]; // ���� ���� �����ϴ� ����
		for (int j = 1; j < N; j++) {
			// ���� ���̰� 2�ΰ��� ������
			if (abs(graph[j][i] - prev) >= 2) {
				trigger = 1;
				break;
			}
			// ���� ������ ���� ���� ū ���
			if (graph[j][i] > prev) {
				// L��ŭ �ڷΰ��鼭 ���� ������ Ȯ��
				for (int k = j - 1; k >= j - L; k--) {
					if (k < 0) {
						trigger = 1;
						break;
					}
					else if (visit[k][i]) trigger = 1;
					else if (prev != graph[k][i]) trigger = 1;
				}
				// ������ ��� �湮ǥ��!
				if (!trigger) {
					for (int k = j - 1; k >= j - L; k--) {
						visit[k][i] = true;
					}
				}
			}
			// ���� ������ ���� ���� ���� ���
			if (graph[j][i] < prev) {
				// L-1��ŭ ������ ���鼭 ���� ������ Ȯ��
				for (int k = j; k <= j + L - 1; k++) {
					if (k >= N) {
						trigger = 1;
						break;
					}
					else if (visit[k][i]) trigger = 1;
					else if (graph[j][i] != graph[k][i]) trigger = 1;
				}
				// ������ ��� �湮ǥ��!
				if (!trigger) {
					for (int k = j; k <= j + L - 1; k++) {
						visit[k][i] = true;
					}
				}
			}
			// �������̸� ����
			if (trigger) break;
			// �����̸� prev�� ���簪�� ����
			prev = graph[j][i];
		}
		// �����̸� ���� 1 ����
		if (!trigger) cnt++;
	}
	/********************************/
	cout << cnt << '\n';
}
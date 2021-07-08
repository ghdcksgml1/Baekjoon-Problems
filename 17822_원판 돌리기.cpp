#include <iostream>
#include <deque>
#define MAX 51

using namespace std;

int N, M, T;
int graph[MAX][MAX];
int sum = 0;
bool graph_overlap[MAX][MAX];
deque<int> dq[MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// �ߺ��� ã���ִ� �Լ�
bool checkCircle() {
	bool trigger = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) continue;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				// ��,�Ʒ��� �����
				if (nx < 0 || nx >= N) continue;
				// �������� �����
				else if (ny < 0) {
					if (graph[i][M-1] == graph[i][j]) {
						graph_overlap[i][M-1] = true;
						graph_overlap[i][j] = true;
						trigger = true;
					}
				}
				// ���������� �����
				else if (ny >= M) {
					if (graph[i][0] == graph[i][j]) {
						graph_overlap[i][0] = true;
						graph_overlap[i][j] = true;
						trigger = true;
					}
				}
				// ������ ����� �κ��� �ƴϸ�
				else {
					if (graph[nx][ny] == graph[i][j]) {
						graph_overlap[nx][ny] = true;
						graph_overlap[i][j] = true;
						trigger = true;
					}
				}
			}
		}
	}
	return trigger;
}
// �ð�������� ������ ȸ��
void clockWise(int num,int k) {
	// 1 1 2 3
	// 3 1 1 2
	for (int i = 0; i < k; i++) {
		dq[num].push_front(dq[num].back());
		dq[num].pop_back();
	}
}
// �ݽð�������� ������ ȸ��
void counterClockWise(int num,int k) {
	// 1 1 2 3
	// 1 2 3 1
	for (int i = 0; i < k; i++) {
		dq[num].push_back(dq[num].front());
		dq[num].pop_front();
	}
}
// �ʱ⼳��
void init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main(void) {
	init();
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int n;
			cin >> n;
			dq[i].push_back(n);
		}
	}
	
	while (T--) {
		int x, d, k;
		cin >> x >> d >> k;
		
		// x�� ������� ȸ����Ŵ
		for (int i = 1; i <= N; i++) {
			if (i % x == 0) {
				if (d == 0) clockWise(i, k);
				if (d == 1) counterClockWise(i, k);
			}
		}

		// ���� �ִ� ������ graph�迭�� ����
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < dq[i].size(); j++) {
				graph[i - 1][j] = dq[i][j];
				// graph�� ���� 0�̸� �ߺ��ؼ� ���������Ƿ� graph_overlap�� true�� �ٲ���
				if (graph[i - 1][j] == 0) graph_overlap[i-1][j] = true;
			}
		}

		// �ߺ��� ã�� �Լ��� ������� �ߺ��� ������������
		if (!checkCircle()) {
			int avg_sum = 0, cnt = 0;
			// �迭�� ���� �ߺ��� �ƴ� ���� ���Ѵ�.
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (!graph_overlap[i][j]) {
						avg_sum += graph[i][j];
						cnt++;
					}
				}
			}
			
			// ��� �ߺ����� ���� �����
			if (cnt != 0) {
				int avg = avg_sum / cnt;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						// �ߺ����� ���� �� �߿� 
						if (!graph_overlap[i][j]) {
							// ��պ��� ������ +1
							if (graph[i][j] < avg) graph[i][j] += 1;
							// ��պ��� ������ -1
							else if (graph[i][j] > avg) graph[i][j] -= 1;
							// ��պ��� ������ +1
							else if (graph[i][j] == avg && (avg_sum % cnt != 0)) graph[i][j] += 1;
						}
						// ���⼭ double�� �Ⱦ��� int�� ���������� �̿��� ����
						// double�� int�� ���ϰԵǸ� double�� ���� ���� �ֱ� ����
						// ex.) a = 1.0 , b = 1; if(a==b) false�� ���� �� �ִ�.
						// double�� ���� ���� ������ �����ϱ� ������
					}
				}
			}
		}

		sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!graph_overlap[i][j])
					sum += graph[i][j];
			}
		}

		// deque�� �ֽ�ȭ�ϰ�, graph_overlap�迭�� �ʱ�ȭ
		for (int i = 0; i < N; i++) {
			dq[i + 1].clear(); // deque �����
			for (int j = 0; j < M; j++) {
				// �ߺ��Ǿ��� �κ��� 0���� ���� ���� ����ְ�
				if (graph_overlap[i][j])
					dq[i + 1].push_back(0);
				// �ߺ������ʾҴ� �κ��� graph�迭�� �� �״�� �־��ش�.
				else
					dq[i + 1].push_back(graph[i][j]);
				// graph_overlap�迭 �ʱ�ȭ
				graph_overlap[i][j] = false;
			}
		}
	}

	cout << sum << '\n';

	return 0;
}
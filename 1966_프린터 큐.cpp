#include <iostream>
#include <queue>

using namespace std;

int T, N, M;
int num;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		cin >> N >> M;
		for (int j = 0; j < N; j++) {
			cin >> num;
			q.push({ num,j }); // �� ��ġ�� key������ ����.
			pq.push(num);
		}
		int index = 0; // ���°�� �������������� �������ִ� ����
		while(!q.empty()) {
			// �켱���� ť�� top�� ť�� front ���� ���������� �ݺ�
			while (q.front().first != pq.top()) {
				q.push(q.front());
				q.pop();
			}
			// q�� key�κ��� ã�����ϴ� M�϶�
			if (q.front().second == M) {
				index++;
				cout << index << '\n';
				break; // ������ص� Ż��
			}
			// q�� key�κ��� ã���ϴ� �κ��� �ƴϸ�
			else {
				index++;
				q.pop(); pq.pop();
				// ť�� �켱���� ť�� ����
				// �������� ��µǴ� ū���� ã������
			}
		}
	}
}
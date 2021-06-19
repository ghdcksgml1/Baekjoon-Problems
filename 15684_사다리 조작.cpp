#include <iostream>
#include <vector>
using namespace std;
int N, M, H;
int Min = 4;
int graph[32][11] = { 0, };
bool visit[32][11];
// i�� ���μ��� ����� i���� �������� üũ�ϴ� �Լ�
bool check_ladder() {
	for (int i = 1; i <= N; i++) {
		int cpy_i = i;
		for (int j = 1; j <= H + 1; j++) {
			cpy_i = cpy_i + graph[j][cpy_i];
		}
		if (i != cpy_i) return false;
	}
	return true;
}
// ��Ʈ��ŷ
void backtracking(int x,int prev) {
	// i���� ���μ��� i�� ����
	if (check_ladder()) {
		// ������ Min���� ������ �ֽ�ȭ
		Min = min(x, Min);
		return;
	}
	// x�� 3�̸� �Լ� ����
	// x>3 �� �ƴ� ������ x>3���� �����ص� ���������� �۵�������,
	// �ð����⵵�� �ξ� ���� �þ�� ������ x==3���� �߰�,
	// x==3�̴��� ������ Min���� �ֽ�ȭ�߱� ������ Min���� ���������� �ֽ�ȭ �ȴ�.
	if (x == 3) {
		return;
	}
	// �����̶� �ð����⵵�� �ٿ����� ���� i,j �Ѵ� �������� �־������, ����
	// ������, i���� �������� ���� �ߺ��� �ٿ�������, 2���� �迭�̱� ������
	// j�� �������� ���� �ȴٸ�, ���� �������� 3�̶�� j=3;j<=N-1�� �Ǳ� ������
	// j=1, j=2 ���� Ž���� ���ϰ� �ȴ�. ���� i���� �������� �־��ִ� ���� �ð����⵵��
	// ���̴� ����̴�.

	// ������ ���� i=1,j=1�� �������ѵ� ���������� ���� ������ ������, nCr�̾ƴ� nPr �� ����
	// �ϱ� ������ �����ߴ� ����� ���� ����� �� �����ϰ� �ǹǷ�, �ð����⵵�� �ξ� �����Ͽ�
	// �ð��ʰ��� �߰� �ȴ�.
	for (int i = prev; i <= H; i++) {
		for (int j = 1; j <= N - 1; j++) {
			if (visit[i][j]) continue;
			if (graph[i][j] == 0 && graph[i][j + 1] == 0) {
				if (x == 0) visit[i][j] = true;
				graph[i][j] = 1;
				graph[i][j + 1] = -1;
				backtracking(x + 1, i);
				graph[i][j] = 0;
				graph[i][j + 1] = 0;
			}
		}
	}
}

void init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main(void) {
	init();
	cin >> N >> M >> H;
	while (M--) {
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1][n2] = 1;
		graph[n1][n2 + 1] = -1;
	}
	backtracking(0,1);
	// Min�� 4��� ���� �ֽ�ȭ�� �ȵȰ��̹Ƿ�, "-1" ���
	if (Min == 4) {
		cout << "-1" << '\n';
	}
	else {
		cout << Min << '\n';
	}
}
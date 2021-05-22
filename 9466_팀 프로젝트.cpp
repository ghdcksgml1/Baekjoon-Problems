#include <iostream>
#include <cstring>
using namespace std;
int T, n,cnt;
int n_select[100001];
bool n_visited[100001];
bool check[100001];
void dfs(int x) {
	int next = n_select[x];// ���� ��
	n_visited[x] = true; // �湮ǥ��
	if (!n_visited[next]) 
		dfs(next);// �湮���� ���� �ε����� dfs
	else { // �׷��� ������
		if (!check[next]) { // ��湮 ���� ���� ���
			for (int i = next; i != x; i = n_select[i]) {
				cnt++;
			}
			cnt++;
		}
	}
	check[x] = true;
}
int main(void) {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(n_select, 0, sizeof(n_select));
		memset(n_visited, false, sizeof(n_visited));
		memset(check, false, sizeof(check));
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> n_select[j];
		}
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (!n_visited[j])
				dfs(j);
		}
		cout << n-cnt << '\n';
	}
}
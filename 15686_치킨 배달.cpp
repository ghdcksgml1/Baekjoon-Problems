#include <iostream>
#include <vector>
using namespace std;
int N, M;
int n_arr[51][51];
vector<pair<int, int>> v1; // 1�� ��ǥ�� �����ϴ� ����
vector<pair<int, int>> v2; // 2�� ��ǥ�� �����ϴ� ����
bool visited[2500];
int minn = 1000000000;

void backTracking(int x, int ind) {
	if(x==M) {
		vector<pair<int, int>> picked; // M����ŭ ���� 2�� ��ǥ
		vector<int> chicken_distance(v1.size(),100000);
		for (int i = 0; i < v2.size(); i++) {
			if (visited[i]) {
				picked.push_back(v2[i]);
			}
		}
		// 2���� 1������ �Ÿ��� ���ϴ� ����
		for (int i = 0; i < picked.size(); i++) {
			for (int j = 0; j < v1.size(); j++) {
				int dist = abs(picked[i].first - v1[j].first) + abs(picked[i].second - v1[j].second);
				if (chicken_distance[j] > dist) {
					chicken_distance[j] = dist;
				}
			}
		}
		int chicken_dist = 0;
		for (int i = 0; i < chicken_distance.size(); i++) {
			chicken_dist += chicken_distance[i];
		}
		if (chicken_dist < minn) {
			minn = chicken_dist;
		}
		return;
	}
	for (int i = ind; i < v2.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			backTracking(x + 1, i);
			visited[i] = false;
		}
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n_arr[i][j];
			if (n_arr[i][j] == 1) {
				v1.push_back({ i,j });
			}
			if (n_arr[i][j] == 2) {
				v2.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i].first <<v2[i].second<< '\n';
	}
	backTracking(0, 0);
	cout << minn << '\n';
}
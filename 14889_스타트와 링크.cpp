#include <iostream>
#include <vector>

using namespace std;
int N;
int n_arr[21][21];
bool visited[21];
int minn = 1000000;
void backTracking(int x,int ind) {
	if (x==N/2) {
		vector<int> start;
		vector<int> link;
		int start_score = 0;
		int link_score = 0;
		for (int i = 0; i < N; i++) {
			if (visited[i]) {
				start.push_back(i);
			}
			else {
				link.push_back(i);
			}
		}
		for (int i = 0; i < (N / 2); i++) {
			for (int j = 0; j < (N / 2); j++) {
				start_score += n_arr[start[i]][start[j]];
				link_score += n_arr[link[i]][link[j]];
			}
		}
		if (abs(start_score - link_score) < minn)
			minn = abs(start_score - link_score);
		return;
	}
	for (int i = ind; i < N; i++) {
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
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n_arr[i][j];
		}
	}
	backTracking(0, 0);
	cout << minn << '\n';
}
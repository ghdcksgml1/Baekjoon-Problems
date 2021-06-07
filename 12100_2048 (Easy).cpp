#include <iostream>
using namespace std;
int N;
int graph[20][20];
int dx[4] = { 1,-1,0,0 }; // ╩С ,го , ©Л , аб
int dy[4] = { 0,0,1,-1 };
int Max = 0;
void backtracking(int x) {
	if (x == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Max < graph[i][j])
					Max = graph[i][j];
			}
		}
		return;
	}
	int new_graph[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			new_graph[i][j] = graph[i][j];
		}
	}
	/********ю╖*******/
	for (int i = 0; i < N; i++) {
		int idx = 0;
		for (int j = 1; j < N; j++) {
			if (graph[idx][i] == 0) {
				idx++;
				continue;
			}
			if (graph[j][i] == 0) continue;
			if (graph[j][i] == graph[idx][i]) {
				graph[idx][i] = graph[idx][i] * 2;
				graph[j][i] = 0;
				idx = j + 1;
				j++;
			}
			else {
				idx = j;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int idx = 0;
		for (int j = 1; j < N; j++) {
			if (graph[idx][i] != 0) {
				idx++;
				continue;
			}
			if (graph[j][i] != 0) {
				graph[idx][i] = graph[j][i];
				graph[j][i] = 0;
				idx++;
			}
		}
	}
	backtracking(x + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			graph[i][j] = new_graph[i][j];
		}
	}
	/********╬ф╥║*******/
	for (int i = 0; i < N; i++) {
		int idx = N - 1;
		for (int j = N - 2; j >= 0; j--) {
			if (graph[idx][i] == 0) {
				idx--;
				continue;
			}
			if (graph[j][i] == 0) continue;
			if (graph[j][i] == graph[idx][i]) {
				graph[idx][i] = graph[idx][i] * 2;
				graph[j][i] = 0;
				idx = j - 1;
				j--;
			}
			else {
				idx = j;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int idx = N - 1;
		for (int j = N - 2; j >= 0; j--) {
			if (graph[idx][i] != 0) {
				idx--;
				continue;
			}
			if (graph[j][i] != 0) {
				graph[idx][i] = graph[j][i];
				graph[j][i] = 0;
				idx--;
			}
		}
	}
	backtracking(x + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			graph[i][j] = new_graph[i][j];
		}
	}
	/*********аб********/
	for (int i = 0; i < N; i++) {
		int idx = 0;
		for (int j = 1; j < N; j++) {
			if (graph[i][idx] == 0) {
				idx++;
				continue;
			}
			if (graph[i][j] == 0) continue;
			if (graph[i][j] == graph[i][idx]) {
				graph[i][idx] = graph[i][idx] * 2;
				graph[i][j] = 0;
				idx = j + 1;
				j++;
			}
			else {
				idx = j;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int idx = 0;
		for (int j = 1; j < N; j++) {
			if (graph[i][idx] != 0) {
				idx++;
				continue;
			}
			if (graph[i][j] != 0) {
				graph[i][idx] = graph[i][j];
				graph[i][j] = 0;
				idx++;
			}
		}
	}
	backtracking(x + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			graph[i][j] = new_graph[i][j];
		}
	}
	/********©Л********/
	for (int i = 0; i < N; i++) {
		int idx = N - 1;
		for (int j = N - 2; j >= 0; j--) {
			if (graph[i][idx] == 0) {
				idx--;
				continue;
			}
			if (graph[i][j] == 0) continue;
			if (graph[i][j] == graph[i][idx]) {
				graph[i][idx] = graph[i][idx] * 2;
				graph[i][j] = 0;
				idx = j - 1;
				j--;
			}
			else {
				idx = j;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int idx = N - 1;
		for (int j = N - 2; j >= 0; j--) {
			if (graph[i][idx] != 0) {
				idx--;
				continue;
			}
			if (graph[i][j] != 0) {
				graph[i][idx] = graph[i][j];
				graph[i][j] = 0;
				idx--;
			}
		}
	}
	backtracking(x + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			graph[i][j] = new_graph[i][j];
		}
	}
	/*************/
}
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	backtracking(0);
	cout << Max << '\n';
}
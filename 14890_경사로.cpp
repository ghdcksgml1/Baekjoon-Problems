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

	int cnt = 0; // 전체 경우의 수를 count
	/********************************/
	// 가로
	for (int i = 0; i < N; i++) {
		int trigger = 0; // 0이면 정상, 1이면 비정상
		int prev = graph[i][0]; // 이전 값을 저장하는 변수
		for (int j = 1; j < N; j++) {
			// 높이 차이가 2인경우는 비정상
			if (abs(graph[i][j] - prev) >= 2) {
				trigger = 1;
				break;
			}
			// 이전 값보다 현재 값이 큰 경우
			if (graph[i][j] > prev) {
				// L만큼 뒤로가면서 값이 같은지 확인
				for (int k = j - 1; k >= j - L; k--) {
					if (k < 0) {
						trigger = 1;
						break;
					}
					else if (visit[i][k]) trigger = 1;
					else if (prev != graph[i][k]) trigger = 1;
				}
				// 정상인 경우 방문표시!
				if (!trigger) {
					for (int k = j - 1; k >= j - L; k--) {
						visit[i][k] = true;
					}
				}
			}
			// 이전 값보다 현재 값이 작은 경우
			if (graph[i][j] < prev) {
				// L-1만큼 앞으로 가면서 값이 같은지 확인
				for (int k = j ; k <= j + L-1; k++) {
					if (k >= N) {
						trigger = 1;
						break;
					}
					else if (visit[i][k]) trigger = 1;
					else if (graph[i][j] != graph[i][k]) trigger = 1;
				}
				// 정상인 경우 방문표시!
				if (!trigger) {
					for (int k = j; k <= j + L - 1; k++) {
						visit[i][k] = true;
					}
				}
			}
			// 비정상이면 종료
			if (trigger) break;
			// 정상이면 prev에 현재값을 저장
			prev = graph[i][j];
		}
		// 정상이면 개수 1 증가
		if (!trigger) cnt++;
	}
	/********************************/
	// visit 값 초기화
	for (int i=0; i < N; i++) {
		for (int j=0; j < N; j++) {
			visit[i][j] = false;
		}
	}
	/********************************/
	// 세로
	for (int i = 0; i < N; i++) {
		int trigger = 0; // 0이면 정상, 1이면 비정상
		int prev = graph[0][i]; // 이전 값을 저장하는 변수
		for (int j = 1; j < N; j++) {
			// 높이 차이가 2인경우는 비정상
			if (abs(graph[j][i] - prev) >= 2) {
				trigger = 1;
				break;
			}
			// 이전 값보다 현재 값이 큰 경우
			if (graph[j][i] > prev) {
				// L만큼 뒤로가면서 값이 같은지 확인
				for (int k = j - 1; k >= j - L; k--) {
					if (k < 0) {
						trigger = 1;
						break;
					}
					else if (visit[k][i]) trigger = 1;
					else if (prev != graph[k][i]) trigger = 1;
				}
				// 정상인 경우 방문표시!
				if (!trigger) {
					for (int k = j - 1; k >= j - L; k--) {
						visit[k][i] = true;
					}
				}
			}
			// 이전 값보다 현재 값이 작은 경우
			if (graph[j][i] < prev) {
				// L-1만큼 앞으로 가면서 값이 같은지 확인
				for (int k = j; k <= j + L - 1; k++) {
					if (k >= N) {
						trigger = 1;
						break;
					}
					else if (visit[k][i]) trigger = 1;
					else if (graph[j][i] != graph[k][i]) trigger = 1;
				}
				// 정상인 경우 방문표시!
				if (!trigger) {
					for (int k = j; k <= j + L - 1; k++) {
						visit[k][i] = true;
					}
				}
			}
			// 비정상이면 종료
			if (trigger) break;
			// 정상이면 prev에 현재값을 저장
			prev = graph[j][i];
		}
		// 정상이면 개수 1 증가
		if (!trigger) cnt++;
	}
	/********************************/
	cout << cnt << '\n';
}
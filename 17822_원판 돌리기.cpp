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
// 중복을 찾아주는 함수
bool checkCircle() {
	bool trigger = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) continue;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				// 위,아래로 벗어나면
				if (nx < 0 || nx >= N) continue;
				// 왼쪽으로 벗어나면
				else if (ny < 0) {
					if (graph[i][M-1] == graph[i][j]) {
						graph_overlap[i][M-1] = true;
						graph_overlap[i][j] = true;
						trigger = true;
					}
				}
				// 오른쪽으로 벗어나면
				else if (ny >= M) {
					if (graph[i][0] == graph[i][j]) {
						graph_overlap[i][0] = true;
						graph_overlap[i][j] = true;
						trigger = true;
					}
				}
				// 범위를 벗어나는 부분이 아니면
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
// 시계방향으로 원판을 회전
void clockWise(int num,int k) {
	// 1 1 2 3
	// 3 1 1 2
	for (int i = 0; i < k; i++) {
		dq[num].push_front(dq[num].back());
		dq[num].pop_back();
	}
}
// 반시계방향으로 원판을 회전
void counterClockWise(int num,int k) {
	// 1 1 2 3
	// 1 2 3 1
	for (int i = 0; i < k; i++) {
		dq[num].push_back(dq[num].front());
		dq[num].pop_front();
	}
}
// 초기설정
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
		
		// x의 배수들을 회전시킴
		for (int i = 1; i <= N; i++) {
			if (i % x == 0) {
				if (d == 0) clockWise(i, k);
				if (d == 1) counterClockWise(i, k);
			}
		}

		// 덱에 있는 값들을 graph배열에 복사
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < dq[i].size(); j++) {
				graph[i - 1][j] = dq[i][j];
				// graph의 값이 0이면 중복해서 지워졌으므로 graph_overlap을 true로 바꿔줌
				if (graph[i - 1][j] == 0) graph_overlap[i-1][j] = true;
			}
		}

		// 중복을 찾는 함수를 실행시켜 중복이 나오지않으면
		if (!checkCircle()) {
			int avg_sum = 0, cnt = 0;
			// 배열의 값중 중복이 아닌 값만 더한다.
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (!graph_overlap[i][j]) {
						avg_sum += graph[i][j];
						cnt++;
					}
				}
			}
			
			// 모두 중복되지 않은 경우라면
			if (cnt != 0) {
				int avg = avg_sum / cnt;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						// 중복되지 않은 수 중에 
						if (!graph_overlap[i][j]) {
							// 평균보다 낮으면 +1
							if (graph[i][j] < avg) graph[i][j] += 1;
							// 평균보다 높으면 -1
							else if (graph[i][j] > avg) graph[i][j] -= 1;
							// 평균보다 낮으면 +1
							else if (graph[i][j] == avg && (avg_sum % cnt != 0)) graph[i][j] += 1;
						}
						// 여기서 double을 안쓰고 int의 나머지값을 이용한 이유
						// double을 int와 비교하게되면 double에 오차 값이 있기 때문
						// ex.) a = 1.0 , b = 1; if(a==b) false가 나올 수 있다.
						// double은 일정 오차 범위를 인정하기 때문에
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

		// deque을 최신화하고, graph_overlap배열을 초기화
		for (int i = 0; i < N; i++) {
			dq[i + 1].clear(); // deque 지우기
			for (int j = 0; j < M; j++) {
				// 중복되었던 부분은 0으로 덱에 새로 집어넣고
				if (graph_overlap[i][j])
					dq[i + 1].push_back(0);
				// 중복되지않았던 부분은 graph배열의 값 그대로 넣어준다.
				else
					dq[i + 1].push_back(graph[i][j]);
				// graph_overlap배열 초기화
				graph_overlap[i][j] = false;
			}
		}
	}

	cout << sum << '\n';

	return 0;
}
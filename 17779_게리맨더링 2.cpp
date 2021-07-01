#include <iostream>
#include <cstring>
#define MAX 21
using namespace std;
int N;
int x, y, d1, d2;
int Max, Min;
int election_Min = 1000000000;
int arr[MAX][MAX];
int graph[MAX][MAX];
// 1번 선거구 : 1 <= r < x+d1 , 1 <= c <=y
// 2번 선거구 : 1 <= r <= x+d2 , y < c <=N
// 3번 선거구 : x+d1 <= r <= N , 1 <= c < y-d1+d2
// 4번 선거구 : x+d2 < r <= N , y-d1+d2 <= c <= N
void election_num(int x, int y, int d1, int d2) {
	Max = 0, Min = 1000000000;
	int Num[5] = { 0, };
	// 5
	for (int i = 0; i <= d1; i++) {
		graph[x + i][y - i] = 5;
		graph[x + d2 + i][y + d2 - i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		graph[x + i][y + i] = 5;
		graph[x + d1 + i][y - d1 + i] = 5;
	}
	int cnt_5;
	for (int i = x+1; i <= x+d1+d2-1; i++) {
		cnt_5 = 0;
		for (int j = 1; j <= N; j++) {
			if (cnt_5 == 2) break;
			if (graph[i][j] == 5) cnt_5++;
			if (cnt_5 == 1) graph[i][j] = 5;
		}
	}
	/***************/
	// 1
	for (int i = 1; i < x + d1; i++) {
		for (int j = 1; j <= y; j++) {
			if (graph[i][j] == 5) break;
			graph[i][j] = 1;
			Num[0] += arr[i][j];
		}
	}
	Max = max(Max, Num[0]);
	Min = min(Min, Num[0]);
	/*****************/
	// 2
	for (int i = 1; i <= x + d2; i++) {
		for (int j = y + 1; j <= N; j++) {
			if (graph[i][j] == 5) continue;
			graph[i][j] = 2;
			Num[1] += arr[i][j];
		}
	}
	Max = max(Max, Num[1]);
	Min = min(Min, Num[1]);
	/*****************/
	// 3
	for (int i = x + d1; i <= N; i++) {
		for (int j = 1; j < y - d1 + d2; j++) {
			if (graph[i][j] == 5) break;
			graph[i][j] = 3;
			Num[2] += arr[i][j];
		}
	}
	Max = max(Max, Num[2]);
	Min = min(Min, Num[2]);
	/*****************/
	// 4
	for (int i = x + d2 + 1; i <= N; i++) {
		for (int j = y - d1 + d2; j <= N; j++) {
			if (graph[i][j] == 5) continue;
			graph[i][j] = 4;
			Num[3] += arr[i][j];
		}
	}
	Max = max(Max, Num[3]);
	Min = min(Min, Num[3]);
	/*****************/
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] == 5) Num[4] += arr[i][j];
		}
	}
	Max = max(Max, Num[4]);
	Min = min(Min, Num[4]);

	election_Min = min(election_Min, Max - Min);
}
void init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main(void) {
	init();
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	
	
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if (x + d1 + d2 > N) break;
					if (y - d1 >= y && y - d1 < 1 && y + d2 > N) break;
					election_num(x, y, d1, d2);
					memset(graph, 0, sizeof(graph));
				}
			}
		}
	}
	
	cout << election_Min << '\n';
	return 0;
}
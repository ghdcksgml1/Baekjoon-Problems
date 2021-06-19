#include <iostream>
#include <vector>
using namespace std;
int N, M, H;
int Min = 4;
int graph[32][11] = { 0, };
bool visit[32][11];
// i번 세로선의 결과가 i번이 나오는지 체크하는 함수
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
// 백트래킹
void backtracking(int x,int prev) {
	// i번의 세로선이 i로 가면
	if (check_ladder()) {
		// 현재의 Min보다 작으면 최신화
		Min = min(x, Min);
		return;
	}
	// x가 3이면 함수 종료
	// x>3 이 아닌 이유는 x>3으로 설정해도 정상적으로 작동하지만,
	// 시간복잡도가 훨씬 많이 늘어나기 때문에 x==3으로 했고,
	// x==3이더라도 위에서 Min값을 최신화했기 때문에 Min값은 정상적으로 최신화 된다.
	if (x == 3) {
		return;
	}
	// 조금이라도 시간복잡도를 줄여보기 위해 i,j 둘다 이전값을 넣어봤지만, 실패
	// 이유는, i에는 이전값이 들어가면 중복을 줄여주지만, 2차원 배열이기 때문에
	// j에 이전값이 들어가게 된다면, 만약 이전값이 3이라면 j=3;j<=N-1이 되기 때문에
	// j=1, j=2 값을 탐색을 못하게 된다. 따라서 i에만 이전값을 넣어주는 것이 시간복잡도를
	// 줄이는 방법이다.

	// 이전값 없이 i=1,j=1로 고정시켜도 정상적으로 답이 나오긴 하지만, nCr이아닌 nPr 로 동작
	// 하기 때문에 선택했던 경우의 수를 몇번씩 더 선택하게 되므로, 시간복잡도가 훨씬 증가하여
	// 시간초과가 뜨게 된다.
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
	// Min이 4라면 값이 최신화가 안된것이므로, "-1" 출력
	if (Min == 4) {
		cout << "-1" << '\n';
	}
	else {
		cout << Min << '\n';
	}
}
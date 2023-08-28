// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

int dist[1000002];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    queue<int> Q;
    Q.push(S);
    dist[S] = 1;

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();

        if (cur == G) {
            cout << dist[cur] -1 << '\n';
            return 0;
        }

        for (int i=0; i<2; i++) {
            int nx;
            if (i==0) nx = cur + U;
            if (i==1) nx = cur - D;

            if (nx < 1 || nx > F) continue; // 건물의 범위를 넘어가는 것을 막기
            if (dist[nx]) continue; // 방문한 곳 가지 말기

            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }
    cout << "use the stairs" << '\n';

    return 0;
}
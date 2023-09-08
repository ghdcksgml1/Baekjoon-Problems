// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

int dist[101][101];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i=0; i<101; i++) {
        for (int j=0; j<101; j++) {
            if (i != j) {
                dist[i][j] = 987654321;
            }
        }
    }

    int N,M;
    cin >> N >> M;

    for (int i=0; i<M; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        dist[tmp1-1][tmp2-1] = 1;
        dist[tmp2-1][tmp1-1] = 1;
    }

    for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                int tmp = dist[i][k] + dist[k][j];
                if (dist[i][j] > tmp) {
                    dist[i][j] = tmp;
                }
            }
        }
    }

    int ans = 987654321;
    for (int i=0; i<N; i++) {
        int tmp = 0;
        for (int j=0; j<N; j++) {
            tmp += dist[i][j];
        }
        ans = min(ans, tmp);
    }

    for (int i=0; i<N; i++) {
        int tmp = 0;
        for (int j=0; j<N; j++) {
            tmp += dist[i][j];
        }
        if (tmp == ans) {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    return 0;
}
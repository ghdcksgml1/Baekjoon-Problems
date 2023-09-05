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

    int N,M;
    cin >> N >> M;

    for (int i=0; i<M; i++) {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        tmp1--; tmp2--;
        if (dist[tmp1][tmp2] !=0 && dist[tmp1][tmp2] < tmp3) {

        } else {
            dist[tmp1][tmp2] = tmp3;
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i == j) continue;
            if (dist[i][j] == 0) dist[i][j] = 987654321;
        }
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

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (dist[i][j] == 987654321) cout << "0 ";
            else cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
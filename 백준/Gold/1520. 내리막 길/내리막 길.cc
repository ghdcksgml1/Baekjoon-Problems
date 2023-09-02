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

// 4 5
// 50 45 37 32 30
// 35 50 40 20 25
// 30 30 25 17 28
// 27 24 22 15 10

// 2 1 1 2 1
// 1 4 3 1 1
// 1 2 2 1 3
// 1 1 1 1 0

using namespace std;
typedef long long ll;

struct NN {
    int g_x; // 발생 x
    int g_y; // 발생 y
    int t_x; // 타겟 x
    int t_y; // 타겟 y
};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int graph[502][502];
int dp[502][502];

vector<NN> v;

bool cmp(NN v1, NN v2) {
    return graph[v1.g_x][v1.g_y] > graph[v2.g_x][v2.g_y];
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            for (int k=0; k<4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
                if (graph[i][j] > graph[nx][ny]) {
                    v.push_back({i,j,nx,ny});
                }
            }
        }
    }

    sort(v.begin(), v.end(), cmp);

    dp[1][1] = 1;
    for (NN tmp : v) {
        dp[tmp.t_x][tmp.t_y] += dp[tmp.g_x][tmp.g_y];
    }

    cout << dp[n][m] << '\n';

    return 0;
}
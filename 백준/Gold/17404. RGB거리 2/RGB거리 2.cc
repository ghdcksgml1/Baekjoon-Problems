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

struct Node {
    int r;
    int g;
    int b;
};

vector<Node> v;

int N;
int dp[1002][3];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i=0; i<N; i++) {
        int r,g,b;
        cin >> r >> g >> b;
        v.push_back({r,g,b});
    }

    memset(dp, 1000000, sizeof(dp));
    int answer = 1000000;

    dp[0][0] = v[0].r;
    dp[0][1] = 1000000;
    dp[0][2] = 1000000;

    for (int i=1; i<N; i++) {
        for (int j=0; j<3; j++) {
            if (j == 0 && !(i==N-1)) { // 빨간집을 골랐을때
                dp[i][j] = min(dp[i-1][1], dp[i-1][2]) + v[i].r;
            } else if (j == 1) { // 초록집을 골랐을때
                dp[i][j] = min(dp[i-1][0], dp[i-1][2]) + v[i].g;
            } else if (j == 2) { // 파란집을 골랐을때
                dp[i][j] = min(dp[i-1][0], dp[i-1][1]) + v[i].b;
            }
        }
    }
    answer = min(answer, dp[N-1][0]);
    answer = min(answer, dp[N-1][1]);
    answer = min(answer, dp[N-1][2]);

    memset(dp, 1000000, sizeof(dp));

    dp[0][0] = 1000000;
    dp[0][1] = v[0].g;
    dp[0][2] = 1000000;

    for (int i=1; i<N; i++) {
        for (int j=0; j<3; j++) {
            if (j == 0) { // 빨간집을 골랐을때
                dp[i][j] = min(dp[i-1][1], dp[i-1][2]) + v[i].r;
            } else if (j == 1 && !(i==N-1)) { // 초록집을 골랐을때
                dp[i][j] = min(dp[i-1][0], dp[i-1][2]) + v[i].g;
            } else if (j == 2) { // 파란집을 골랐을때
                dp[i][j] = min(dp[i-1][0], dp[i-1][1]) + v[i].b;
            }
        }
    }
    answer = min(answer, dp[N-1][0]);
    answer = min(answer, dp[N-1][1]);
    answer = min(answer, dp[N-1][2]);

    memset(dp, 1000000, sizeof(dp));

    dp[0][0] = 1000000;
    dp[0][1] = 1000000;
    dp[0][2] = v[0].b;

    for (int i=1; i<N; i++) {
        for (int j=0; j<3; j++) {
            if (j == 0) { // 빨간집을 골랐을때
                dp[i][j] = min(dp[i-1][1], dp[i-1][2]) + v[i].r;
            } else if (j == 1) { // 초록집을 골랐을때
                dp[i][j] = min(dp[i-1][0], dp[i-1][2]) + v[i].g;
            } else if (j == 2 && !(i==N-1)) { // 파란집을 골랐을때
                dp[i][j] = min(dp[i-1][0], dp[i-1][1]) + v[i].b;
            }
        }
    }
    answer = min(answer, dp[N-1][0]);
    answer = min(answer, dp[N-1][1]);
    answer = min(answer, dp[N-1][2]);

    cout << answer << '\n';

    return 0;
}
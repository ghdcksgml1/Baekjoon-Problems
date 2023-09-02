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

// 5 4
// 0 101 0 0 100
// 201

using namespace std;
typedef long long ll;

int n, b, num[3005];
int dp[3005][3005][2];

// B는 잠을 잘수 있는 횟수
// B만큼의 기회를 써서 자고 안자고를 탑다운 방식으로 내려감

int topdown(int x, int y, int z) {
    if (y < 0) return -10;
    if (y == 0 || x > n) return 0;
    if (~dp[x][y][z]) return dp[x][y][z];
    if (z) { // 자는중
        return dp[x][y][z] = max(
                topdown(x+1, y-1, 1), // 자다가 또자면, 기회는 1번 차감됨
                topdown(x+1, y, 0)) // 자다가 안자면, 기회는 그대로
                        + num[x]; // 피로가 회복되었기 때문에 회복량을 더해줌
    } else { // 안자는 중
        return dp[x][y][z] = max(
                topdown(x + 2, y - 2, 1), // 안자다 자면, 첫번째 잠에서는 피로를 회복하지 못하므로 건너뛰기
                topdown(x + 1, y , 0)); // 안자고있었는데 또 안자면, 잘 기회는 그대로
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> n >> b;
    for (int i=1; i<=n; i++) {
        cin >> num[i];
    }

    cout << topdown(0, b+1, 0) << '\n';
}
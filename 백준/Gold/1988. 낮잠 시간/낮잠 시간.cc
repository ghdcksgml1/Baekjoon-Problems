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

int topdown(int x, int y, int z) {
    if (y < 0) return -10;
    if (y == 0 || x > n) return 0;
    if (~dp[x][y][z]) return dp[x][y][z];
    if (z) {
        return dp[x][y][z] = max(topdown(x+1, y-1, 1), topdown(x+1, y, 0)) + num[x];
    } else {
        return dp[x][y][z] = max(topdown(x + 2, y - 2, 1), topdown(x + 1, y , 0));
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
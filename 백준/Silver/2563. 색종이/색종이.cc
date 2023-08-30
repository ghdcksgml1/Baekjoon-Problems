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

int p[101][101];

vector<pii > v;

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v.push_back({tmp1, tmp2});
    }

    int cnt = 0;
    for (pii tmp: v) {
        int x = tmp.xx;
        int y = tmp.yy;
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                if (p[i][j] > 0) continue;
                cnt++;
                p[i][j] = 1;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}
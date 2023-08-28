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

bool visited[300001];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(visited, 0, 100001);

    int n,k;
    cin>>n>>k;

    if (n == k) {
        cout << 0 << '\n';
        return 0;
    }

    queue<pii> Q;
    Q.push({n, 0});

    while (!Q.empty()) {
        pii cur = Q.front(); Q.pop();

        for (int i=0; i<3; i++) {
            int nx;
            if (i==0) nx = cur.xx - 1;
            if (i==1) nx = cur.xx + 1;
            if (i==2) nx = cur.xx * 2;


            if (nx < 0 || nx > 300000 || visited[nx]) continue;
            if (nx == k) {
                cout << cur.yy + 1 << '\n';
                return 0;
            }

            visited[nx] = true;
            Q.push({nx, cur.yy + 1});
        }
    }

    return 0;
}
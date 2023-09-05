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

int parent[500001];

int f_p(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = f_p(parent[a]);
}

void connect(int a, int b) {
    int tmp1 = f_p(a);
    int tmp2 = f_p(b);

    if (tmp1 < tmp2) parent[tmp2] = tmp1;
    else parent[tmp1] = tmp2;
}

bool tf(int a, int b) {
    int tmp1 = f_p(a);
    int tmp2 = f_p(b);

    return (tmp1 == tmp2);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i=0; i<500001; i++) {
        parent[i] = i;
    }

    int n,m;
    cin >> n >> m;

    int ans = 0;
    for (int i=0; i<m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        if (ans != 0) continue;

        if (!tf(tmp1, tmp2)) {
            connect(tmp1, tmp2);
        } else {
            ans = i+1;
        }
    }

    cout << ans << '\n';

    return 0;
}
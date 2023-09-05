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
    int a;
    int b;
    int c; // 거리
};

int parent[200002];
vector<Node> v;

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

// true면 사이클 발생
bool tf(int a, int b) {
    int tmp1 = f_p(a);
    int tmp2 = f_p(b);

    return (tmp1 == tmp2);
}

bool cmp(Node n1, Node n2) {
    if (n1.c == n2.c) {
        return n1.a < n2.a;
    }

    return n1.c < n2.c;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (true) {
        int m, n;
        cin >> m >> n;
        if (m==0 && n==0) break;

        for (int i=0; i<=m; i++) {
            parent[i] = i;
        }
        v.clear();

        int ans = 0;
        for (int i=0; i<n; i++) {
            int tmp1, tmp2, tmp3;
            cin >> tmp1 >> tmp2 >> tmp3;
            v.push_back({tmp1, tmp2, tmp3});

            ans += tmp3;
        }

        sort(v.begin(), v.end(), cmp);

        int sum = 0;
        for (Node t : v) {
            if (!tf(t.a, t.b)) {
                connect(t.a, t.b);
                sum += t.c;
            }
        }

        cout << ans - sum << '\n';
    }

    return 0;
}
// 03 24 35 01 14
// 5 + 5 + 6 + 7 + 7 + 9
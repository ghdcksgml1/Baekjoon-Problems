// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

/**

8 4
1 1
3 1 2 3
3 4 5 6
3 6 7 8
2 3 8
output: 0

 */

vector<int> t; // 진실을 아는 사람
vector<vector<int>> p; // 파티 참석 인원 정보

int parent[52];

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

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 52; i++) {
        parent[i] = i;
    }

    // 0 < N,M <= 50
    int N, M;
    cin >> N >> M;

    // 진실을 아는 사람들
    // 0 <= T <= 50
    int T;
    cin >> T;
    while (T--) {
        int tmp;
        cin >> tmp;
        t.push_back(tmp);
    }

    // 진실을 이어주기
    for (int i=1; i<t.size(); i++) {
        connect(t[i-1], t[i]);
    }
    for (int tmp : t) {
        f_p(tmp);
    }

    // 파티 참석 인원
    for (int i = 0; i < M; i++) {
        vector<int> v;
        int tmp;
        cin >> tmp;
        while (tmp--) { // 1 <= tmp <= 50
            int tmp2;
            cin >> tmp2;
            v.push_back(tmp2);
        }
        p.push_back(v);
    }

    if (t.size() == 0) {
        cout << p.size() << '\n';
        return 0;
    }

    int r = parent[t[0]];

    for (int i=0; i<N; i++) {
        for (vector<int> v: p) {
            bool trigger = false;
            for (int tmp : v) {
                if (tf(r, tmp)) {
                    trigger = true;
                    break;
                }
            }

            if (trigger) {
                for (int tmp : v) {
                    connect(r, tmp);
                }
            }
        }
    }

    int ans = 0;
    for (vector<int> v : p) {
        if (!tf(r, v[0])) ans++;
    }

    cout << ans << '\n';

    return 0;
}
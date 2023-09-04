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
    int x;
    int y;
    int z;
};

int num[1000005];
vector<Node> v;

int nn(int a) {
    if (num[a] != a) {
        return num[a] = nn(num[a]);
    } else{
        return a;
    }
}

bool s(int a, int b) {
    int tmp1 = nn(a);
    int tmp2 = nn(b);

    return (tmp1 == tmp2);
}

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i=0; i<1000001; i++) {
        num[i] = i;
    }

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
//        if (tmp3 < tmp2) {
//            int tmp = tmp3;
//            tmp3 = tmp2;
//            tmp2 = tmp;
//        }
        v.push_back({tmp1, tmp2, tmp3});
    }

    for (Node t : v) {
        if (t.x == 0) {
            int tmp1 = nn(t.y);
            int tmp2 = nn(t.z);
            if (tmp1 < tmp2) num[tmp2] = tmp1;
            else num[tmp1] = tmp2;
        } else {
            if (s(t.y, t.z)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

//    for (int i=1; i<=n; i++) {
//        cout << num[i] << " ";
//    }

    return 0;
}
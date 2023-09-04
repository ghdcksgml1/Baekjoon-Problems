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

int parent[202];

// 부모 찾기
int f_p(int num) {
    if (parent[num] == num) return num;
    else return parent[num] = f_p(parent[num]);
}

void union_join(int num1, int num2) {
    int tmp1 = f_p(num1);
    int tmp2 = f_p(num2);

    if (tmp1 < tmp2) parent[tmp2] = tmp1;
    else parent[tmp1] = tmp2;
}

bool check(int num1, int num2) {
    int tmp1 = f_p(num1);
    int tmp2 = f_p(num2);

    return (tmp1 == tmp2);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i=0; i<202; i++) {
        parent[i] = i;
    }

    int N,M;

    cin >> N >> M;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1) {
                union_join(i, j);
            }
        }
    }

    vector<int> v;
    for (int i=0; i<M; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i=1; i<v.size(); i++) {
        if (!check(v[i], v[i-1])) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}
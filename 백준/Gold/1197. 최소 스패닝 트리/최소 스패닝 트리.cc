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

// 둘의 부모가 같을때 이으면 사이클이 발생한다.

using namespace std;
typedef long long ll;

struct Node {
    int a;
    int b;
    int c;
};


int parent[10001];
vector<Node> v;

int f_p(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = f_p(parent[a]);
}
// 잇기
void connect(int a, int b) {
    int tmp1 = f_p(a);
    int tmp2 = f_p(b);

    if (tmp1 < tmp2) parent[tmp2] = tmp1;
    else parent[tmp1] = tmp2;
}

// 사이클이 발생하는지 안하는지
bool cycle(int a, int b) {
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

    for (int i=0; i<10001; i++) {
        parent[i] = i;
    }

    int V,E;
    cin >> V >> E;

    for (int i=0; i<E; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back({a,b,c});
    }

    sort(v.begin(), v.end(), cmp);

    int sum = 0;
    for (Node t : v) {
        if (!cycle(t.a, t.b)) {
            connect(t.a, t.b);
            sum += t.c;
        }
    }

    cout << sum << '\n';

    return 0;
}
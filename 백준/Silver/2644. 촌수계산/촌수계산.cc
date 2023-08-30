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

// 두사람 중 한사람의 번호를 쭉 타고 들어갔을때, 다른 한사람의 번호가 나와야한다.
// 사람의 수가 100 이하이므로, 101개 정도 배열을 잡아놓고,
// 그래프는 vector<vector<int>>로 만들고, vector< >도 101개 정도 만든다.
// 사람들의 관계를 양방향 그래프로 만들어준다.

// (메소드) 그다음 한 사람으로 부터 DFS를 통해 다른 한사람의 번호가 나올때까지 해주는데
// return 값이 0이라면 -1을 출력하고, 0을 초과한다면 해당 값을 출력한다.

using namespace std;
typedef long long ll;

int people[101];
vector<vector<int>> graph(101);

int s,e; // 시작, 끝

bool dfs(int x) {
    if (x == e) return true; // 타겟 값이면 true 리턴

    // 연관 되어 있는 요소들 하나씩 들어가보기
    for (int tmp : graph[x]) {
        if (!people[tmp]) {
            people[tmp] = people[x] + 1;
            if (!dfs(tmp)) {
                people[tmp] = 0;
            } else {
                return true;
            }
        }
    }

    return false;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    cin >> s >> e;

    int m;
    cin >> m;

    for (int i=0; i<m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }
    ////// 입출력  //////

    people[s] = 1;
    if (dfs(s)) {
        cout << people[e] - 1 << '\n';
    } else {
        cout << "-1" << '\n';
    }

    return 0;
}
// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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

pii home;
pii festival;
vector<pii> v;
map<int, vector<int>> graph;
bool visited[102];

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        v.clear();
        graph.clear();
        memset(visited, false, 102);

        int n;
        cin >> n;

        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        home = {tmp1, tmp2};
        v.push_back(home);

        for (int i = 0; i < n; i++) {
            cin >> tmp1 >> tmp2;
            v.push_back({tmp1, tmp2});
        }

        cin >> tmp1 >> tmp2;
        festival = {tmp1, tmp2};
        v.push_back(festival);

        //////

        for (int i=0; i<n+2; i++) {
            for (int j=i+1; j<n+2; j++) {
                pii one = v[i]; // 대상 좌표
                pii two = v[j]; // 비교 좌표
                // 도달할 수 있는 거리라면, 그래프에 넣어주기
                if ((abs(one.xx - two.xx) + abs(one.yy - two.yy)) <= 1000) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        queue<int> Q;
        Q.push(0);
        visited[0] = true;
        bool trigger = false;

        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            if (cur == n+1) {
                trigger = true;
                break;
            }


            for (int nx : graph[cur]) {
                if (visited[nx]) continue;
                visited[nx] = true;
                Q.push(nx);
            }
        }

        if (trigger) {
            cout << "happy" << '\n';
        } else {
            cout << "sad" << '\n';
        }
    }

    return 0;
}
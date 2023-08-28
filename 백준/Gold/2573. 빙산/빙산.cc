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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int graph[303][303];
int visited[303][303];
int batch[303][303];
vector<pii> st;

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] > 0) {
                st.push_back({i, j});
            }
        }
    }
    // 빙하 녹이는거 정산하면서, 두개로 분리되었는지 체크
    // 녹인 빙하가 하나도 없다면 0 출력
    // 녹일 빙하의 수 저장해놓고


    int t_cnt = 0;
    while (true) {

        int v_cnt = 0;
        for (pii v : st) {

            if (!visited[v.xx][v.yy]) {
                v_cnt++;
                queue<pii> Q;
                Q.push(v);
                visited[v.xx][v.yy] = true;

                while (!Q.empty()) {
                    pii cur = Q.front();
                    Q.pop();
                    int cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        int kx = cur.xx + dx[k];
                        int ky = cur.yy + dy[k];

                        if (kx < 0 || ky < 0 || kx >= n || ky >= m) continue;
                        if (graph[kx][ky] > 0) continue;
                        cnt++;
                    }
                    batch[cur.xx][cur.yy] = cnt;

                    for (int i = 0; i < 4; i++) {
                        int nx = cur.xx + dx[i];
                        int ny = cur.yy + dy[i];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (visited[nx][ny] || graph[nx][ny] <= 0) continue;

                        visited[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        if (v_cnt >= 2) break;
        st.clear();
        int batch_cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                batch_cnt += batch[i][j];
                graph[i][j] -= batch[i][j];
                batch[i][j] = 0;
                visited[i][j] = false;

                if (graph[i][j] > 0) {
                    st.push_back({i,j});
                }
            }
        }
        t_cnt++;

        if (batch_cnt == 0) {
            t_cnt = 0;
            break;
        }
    }

    cout << t_cnt << '\n';

    return 0;
}
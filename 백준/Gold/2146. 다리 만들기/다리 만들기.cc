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

// 먼저, 섬의 개수를 알아내야함. (2개 이상의 섬만 준다.) BFS로
// 개수(i_cnt)를 알아낼때, 벡터에 좌표값 추가 (각각의 섬의 아무 좌표나 한 개씩 알게됨.)
// BFS로 탐색할땐, 개수(i_cnt)를 graph에 저장 (몇번째 섬인지 표시하기 위해서)
// 흰색 부분인지 확인하는 if문에 걸릴때 바로 continue하지말고 vector에 좌표 담아놓고,
// 개수 다 세면, vector<queue<pii>>에 추가해준다.



using namespace std;
typedef long long ll;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int graph[102][102];
bool visited[102][102];
int sea[102][102];

vector<pii > i_graph;
vector<vector<pii>> b_sea;

void visited_setting() {
    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 102; j++) {
            visited[i][j] = false;
        }
    }
}

void sea_setting() {
    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 102; j++) {
            sea[i][j] = 0;
        }
    }
}

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    visited_setting();
    ////// 입출력 //////

    int i_cnt = 0; // 섬 개수
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] > 0 && !visited[i][j]) {
                i_cnt++;
                i_graph.push_back({i, j});

                vector<pii > tmp_sea;

                queue<pii > Q;
                Q.push({i, j});
                graph[i][j] = i_cnt;
                visited[i][j] = true;

                while (!Q.empty()) {
                    pii cur = Q.front();
                    Q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = cur.xx + dx[k];
                        int ny = cur.yy + dy[k];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if (visited[nx][ny]) continue; // 방문한 곳은 거르기
                        if (graph[nx][ny] <= 0) { // 바다면 tmp_sea에 넣어줌.
                            if (graph[nx][ny] == 0) {
                                tmp_sea.push_back({nx, ny});
                                graph[nx][ny] = -1; // 해당 바다 넣었음을 표시
                            }
                            continue;
                        }

                        graph[nx][ny] = i_cnt; // 몇번째 섬인지 표시
                        visited[nx][ny] = true; // 방문 표시
                        Q.push({nx, ny});
                    }
                }
                b_sea.push_back(tmp_sea);
            }
        }
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << graph[i][j] << " ";
//        }
//        cout << '\n';
//    }

    int length = 100000000;
    int idx = 0;
    for (vector<pii > v : b_sea) {
        // sea 초기화, sea는 얼마나 움직였는지를 확인하려구.
        sea_setting();
        idx++; // 몇번째 섬인지.

        queue<pii> Q;

        // v는 경계선 바다 모음집
        for (pii tmp : v) {
            Q.push(tmp);
            sea[tmp.xx][tmp.yy] = 1; // 방문 표시
        }

        while (!Q.empty()) {
            pii cur = Q.front(); Q.pop();

            // 다른 섬을 찾은경우
            if (graph[cur.xx][cur.yy] >= 1 && graph[cur.xx][cur.yy] != idx) {
                length = min(length, sea[cur.xx][cur.yy]);
                break;
            }

            for (int i=0; i<4; i++) {
                int nx = cur.xx + dx[i];
                int ny = cur.yy + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (graph[nx][ny] == idx) continue; // 원래 자기섬이면, 넘기기
                if (sea[nx][ny] > 0) continue;

                sea[nx][ny] = sea[cur.xx][cur.yy] + 1;
                Q.push({nx, ny});
            }
        }
    }

    cout << length - 1 << '\n';

    return 0;
}
// 이제 흰색테두리 부분인 queue<pii>를 하나씩 꺼내서 graph의 숫자가 달라지면 바로 종료시키고 다리길이를 min()을 통해 업데이트한다.
// (-1, 0은 건너뛰지 말고 들어가야함.)
// 다리길이 +1을 해준다.
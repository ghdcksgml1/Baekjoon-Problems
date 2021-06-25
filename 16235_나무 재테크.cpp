#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 11
using namespace std;
int N, M, K;
int x, y, tree_old;
int cur_graph[MAX][MAX]; // 현재 양분
int add_graph[MAX][MAX]; // 겨울에 추가할 양분 
int death_tree[MAX][MAX]; // 죽은 나무의 양분

// 나무를 추가할때 쓰이는 기준좌표
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

vector<int> infor[MAX][MAX]; // 좌표별 나무들의 나이가 저장된 vector
queue<pair<int, int>> tree_coordinates; // 나무가 있는 좌표를 담고있는 queue

void add_tree(int x, int y) {
    for (int dir = 0; dir < 8; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
        // infor[nx][ny]가 비어있을 때에만 queue 에 push해준다.
        if (infor[nx][ny].empty()) tree_coordinates.push({ nx,ny });
        infor[nx][ny].push_back(1);
    }
}

void init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

int main(void) {
    init();
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cur_graph[i][j] = 5;
            cin >> add_graph[i][j];
        }
    }

    while (M--) {
        cin >> x >> y >> tree_old;
        tree_coordinates.push({ x,y });
        infor[x][y].push_back(tree_old);
    }

    // 봄 : 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가
    // 여름 : 봄에 죽은 나무가 양분으로 변함 나이/2 만큼
    // 가을 : 나무가 번식 나이가 5의 배수일때 인접한 8개의 칸
    // 겨울 : 양분 추가 add_graph[r][c]만큼

    vector<pair<int, int>> tree; // 번식하는 나무의 좌표
    vector<int> temp;
    while (K--) { // K년 동안 반복
        int size = tree_coordinates.size();
        while (size--) {
            temp.clear(); // temp 초기화
            auto cur = tree_coordinates.front(); tree_coordinates.pop();
            int curX = cur.first; int curY = cur.second;

            // 나무를 나이 순으로 오름차순 정렬
            sort(infor[curX][curY].begin(), infor[curX][curY].end());

            for (int i = 0; i < infor[curX][curY].size(); i++) {
                // 양분을 먹을 수 있으면 true 아니면 false
                if (cur_graph[curX][curY] - infor[curX][curY][i] >= 0) {
                    // 양분을 먹은 나무의 나이가 5의 배수일때
                    if ((infor[curX][curY][i] + 1) % 5 == 0) {
                        tree.push_back({ curX,curY });
                    }
                    // 현재의 양분을 먹은 양분만큼 빼준다.
                    cur_graph[curX][curY] -= infor[curX][curY][i];
                    temp.push_back(infor[curX][curY][i] + 1);
                }
                else {
                    // 죽은 나무는 (죽은 나무의 나이 / 2) 만큼 양분이 된다.
                    death_tree[curX][curY] += (infor[curX][curY][i] / 2);
                }
            }

            infor[curX][curY].clear(); // 현재 나무들의 나이를 초기화해주고
            infor[curX][curY] = temp; // 살아남은 나무들의 나이를 넣어준다.

            // 중요 !! 살아남은 나무가 없다면 continue 해줘야한다.
            // 위에서 add_tree 함수가 infor가 비어있을 때에만 tree_coordinates queue에
            // 좌표를 넣어주기 때문이다. continue를 하지 않게 되면, queue에
            // 다시 좌표가 들어가기 때문에 동일한 좌표가 들어가게 된다.
            if (infor[curX][curY].empty())
                continue; // push하기 전에 continue해주므로, pop인상태 유지

            // pop 했던 좌표를 다시 push 해준다.
            tree_coordinates.push({ curX,curY });
        }

        // 나무의 나이가 5의 배수인 나무가 있었다면, add_tree함수를 실행해준다.
        for (int i = 0; i < tree.size(); i++) {
            auto cur = tree[i];
            add_tree(cur.first, cur.second);
        }
        tree.clear(); // tree vector를 초기화

        // 현재 양분에 죽은 나무들의 양분과 1년마다 추가되는 양분을 더해준다.
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cur_graph[i][j] += (add_graph[i][j] + death_tree[i][j]);
                death_tree[i][j] = 0;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sum += infor[i][j].size();
        }
    }
    cout << sum << '\n';
}
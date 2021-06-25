#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 11
using namespace std;
int N, M, K;
int x, y, tree_old;
int cur_graph[MAX][MAX]; // ���� ���
int add_graph[MAX][MAX]; // �ܿ￡ �߰��� ��� 
int death_tree[MAX][MAX]; // ���� ������ ���

// ������ �߰��Ҷ� ���̴� ������ǥ
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

vector<int> infor[MAX][MAX]; // ��ǥ�� �������� ���̰� ����� vector
queue<pair<int, int>> tree_coordinates; // ������ �ִ� ��ǥ�� ����ִ� queue

void add_tree(int x, int y) {
    for (int dir = 0; dir < 8; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
        // infor[nx][ny]�� ������� ������ queue �� push���ش�.
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

    // �� : ������ �ڽ��� ���̸�ŭ ����� �԰�, ���̰� 1 ����
    // ���� : ���� ���� ������ ������� ���� ����/2 ��ŭ
    // ���� : ������ ���� ���̰� 5�� ����϶� ������ 8���� ĭ
    // �ܿ� : ��� �߰� add_graph[r][c]��ŭ

    vector<pair<int, int>> tree; // �����ϴ� ������ ��ǥ
    vector<int> temp;
    while (K--) { // K�� ���� �ݺ�
        int size = tree_coordinates.size();
        while (size--) {
            temp.clear(); // temp �ʱ�ȭ
            auto cur = tree_coordinates.front(); tree_coordinates.pop();
            int curX = cur.first; int curY = cur.second;

            // ������ ���� ������ �������� ����
            sort(infor[curX][curY].begin(), infor[curX][curY].end());

            for (int i = 0; i < infor[curX][curY].size(); i++) {
                // ����� ���� �� ������ true �ƴϸ� false
                if (cur_graph[curX][curY] - infor[curX][curY][i] >= 0) {
                    // ����� ���� ������ ���̰� 5�� ����϶�
                    if ((infor[curX][curY][i] + 1) % 5 == 0) {
                        tree.push_back({ curX,curY });
                    }
                    // ������ ����� ���� ��и�ŭ ���ش�.
                    cur_graph[curX][curY] -= infor[curX][curY][i];
                    temp.push_back(infor[curX][curY][i] + 1);
                }
                else {
                    // ���� ������ (���� ������ ���� / 2) ��ŭ ����� �ȴ�.
                    death_tree[curX][curY] += (infor[curX][curY][i] / 2);
                }
            }

            infor[curX][curY].clear(); // ���� �������� ���̸� �ʱ�ȭ���ְ�
            infor[curX][curY] = temp; // ��Ƴ��� �������� ���̸� �־��ش�.

            // �߿� !! ��Ƴ��� ������ ���ٸ� continue ������Ѵ�.
            // ������ add_tree �Լ��� infor�� ������� ������ tree_coordinates queue��
            // ��ǥ�� �־��ֱ� �����̴�. continue�� ���� �ʰ� �Ǹ�, queue��
            // �ٽ� ��ǥ�� ���� ������ ������ ��ǥ�� ���� �ȴ�.
            if (infor[curX][curY].empty())
                continue; // push�ϱ� ���� continue���ֹǷ�, pop�λ��� ����

            // pop �ߴ� ��ǥ�� �ٽ� push ���ش�.
            tree_coordinates.push({ curX,curY });
        }

        // ������ ���̰� 5�� ����� ������ �־��ٸ�, add_tree�Լ��� �������ش�.
        for (int i = 0; i < tree.size(); i++) {
            auto cur = tree[i];
            add_tree(cur.first, cur.second);
        }
        tree.clear(); // tree vector�� �ʱ�ȭ

        // ���� ��п� ���� �������� ��а� 1�⸶�� �߰��Ǵ� ����� �����ش�.
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
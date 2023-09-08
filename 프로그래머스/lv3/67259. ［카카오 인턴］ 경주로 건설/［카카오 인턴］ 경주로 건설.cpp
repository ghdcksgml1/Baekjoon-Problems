#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct Node {
    int x;
    int y;
    int p_d; // 이전 방향
    int val; // 요금
};

// 하, 우, 좌, 상
int dx[4] = {1,0,0,-1}; 
int dy[4] = {0,1,-1,0};
// 전 방향이 {하, 상}이면, {우, 좌}일때 코너가 되고,
// 전 방향이 {우, 좌}이면, {하, 상}일때 코너가 된다.
// 직선 도로 100원
// 코너 500원
// 벽은 그래프에 1로 표시

int n,m;
int visited[30][30];
int dp[30][30];
int ans = 987654321;
int cnt = 0;
vector<vector<int>> table;

void dfs(int xx, int yy, int prev_dir, int payment) {
    if (dp[xx][yy] + 500 < payment) {
        return ;
    } else {
        dp[xx][yy] = payment;
    }
    if (ans < payment) return;
    if (xx == n-1 && yy == m-1) {
        ans = min(ans, payment);
        return ;
    }

    for (int i=0; i<4; i++) {
        int nx = xx + dx[i];
        int ny = yy + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (visited[nx][ny]) continue;


        // 요금 계산
        int pay;
        if (prev_dir == 0 || prev_dir == 3) { // 0, 1
            if (i == 1 || i == 2) { // 코너 추가
                pay = 600;
            } else {
                pay = 100;
            }
        } else { // 2, 3
            if (i == 0 || i == 3) { // 코너 추가
                pay = 600;
            } else {
                pay = 100;
            }
        }

        visited[nx][ny] = true;
        dfs(nx, ny, i, payment + pay);
        visited[nx][ny] = false;
    }
}

int solution(vector<vector<int>> board) {
    n = board.size();
    m = board[0].size();

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            dp[i][j] = 987654321;
            if (board[i][j] == 1 || i==n || j==m) {
                visited[i][j] = true;
            }
        }
    }

    visited[0][0] = true;
    dfs(0,0,0,0);
    dfs(0,0,1,0);
    
    return ans;
}
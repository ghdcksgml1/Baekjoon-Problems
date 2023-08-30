#include <string>
#include <vector>

#define MM 1000000007

using namespace std;

int dp[102][102];

// puddles가 경계선에 있으면, 그 오른쪽이나 아래쪽으로는 이동을 아예못함!


int solution(int m, int n, vector<vector<int>> puddles) {
    // 웅덩이 표시
    for (vector<int> tmp : puddles) {
        dp[tmp[0]][tmp[1]] = -1;
    }
    
    // 경계선 1로 초기화
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if ((dp[i][j] != -1) && (i==1 || j==1)) {
                dp[i][j] = 1;
            }
            if ((dp[i][j] == -1)) dp[i][j] = -1; // 웅덩이 표시
        }
    }
    
    // 경계선에 물 웅덩이가 있는경우 그 뒤는 다 도달할 수 없음.
    bool trigger = false;
    for (int i=1; i<=m; i++) {
        if (trigger) dp[i][1] = 0;
        if (dp[i][1] == -1) trigger = true;
    }
    
    trigger = false;
    for (int i=1; i<=n; i++) {
        if (trigger) dp[1][i] = 0;
        if (dp[1][i] == -1) trigger = true;
    }
    
    for (int i=2; i<=m; i++) {
        for (int j=2; j<=n; j++) {
            if (dp[i][j] != -1) {
                int u = dp[i][j-1]; // 위쪽
                int l = dp[i-1][j]; // 왼쪽
                
                u = (u == -1) ? 0 : u;
                l = (l == -1) ? 0 : l;
                
                dp[i][j] = (u+l) % MM;
            }
        }
    }
    
    int answer = dp[m][n] % MM;
    return answer;
}
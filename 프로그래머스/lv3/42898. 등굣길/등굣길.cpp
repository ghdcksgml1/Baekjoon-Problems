#include <string>
#include <vector>
#include <iostream>

#define MOD 1000000007

using namespace std;

int dp[102][102];

int solution(int m, int n, vector<vector<int>> puddles) {
    
    for (vector<int> tmp : puddles) {
        dp[tmp[0]][tmp[1]] = -1;
    }
    
    dp[1][1] = 1;
    
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (dp[i][j] == -1) dp[i][j] = 0;
            else if (!(i == 1 && j == 1)) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    
    int answer = dp[m][n];
    return answer;
}
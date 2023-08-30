#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 뭔가, 상태값이 필요해보임. (턴다, 안턴다)

//       1, 2, 3, 1
// 턴다   1  2 (1,3) (2,1)
// 안턴다    1  2  (1,3)

//       100, 1, 2, 200
// 턴다   100  1  102   
// 안턴    0  100 100  102

//       100, 1, 2, 200
// 턴다    0   1  2  201
// 안턴    0  0   1   2

int dp[1000001][2];

int solution(vector<int> money) {
    int answer = 0;
    int size = money.size();
    
    dp[0][0] = money[0];
    for (int i=1; i<size-1; i++) {
        dp[i][0] = dp[i-1][1] + money[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
    }
    
    for (int i=0; i<2; i++) {
        for (int j=0; j<size; j++) {
            answer = max(answer, dp[j][i]);
            dp[j][i] = 0;
        }
    }
    
    dp[1][0] = money[1];
    for (int i=2; i<size; i++){ 
        dp[i][0] = dp[i-1][1] + money[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
    }
    
    for (int i=0; i<2; i++) {
        for (int j=0; j<size; j++) {
            answer = max(answer, dp[j][i]);
        }
    }
    
    return answer;
}
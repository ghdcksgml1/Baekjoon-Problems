#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> v;

int solution(vector<vector<int>> triangle) {
    for (vector<int> tmp : triangle) {
        vector<int> tmp_v(tmp.size(), 0);
        v.push_back(tmp_v);
    }
    
    v[0][0] = triangle[0][0];
    
    // 마지막은 계산 필요없음.
    for (int i=0; i<v.size() - 1; i++) {
        for (int j=0; j<v[i].size(); j++) {
            int l = triangle[i+1][j]; // 왼쪽 값
            int r = triangle[i+1][j+1]; // 오른쪽 값
            
            // 현재값에서 더한 값과 원래 있던 값중 큰 값을 넣어줌.
            v[i+1][j] = max(v[i+1][j], v[i][j] + l); // 왼쪽
            v[i+1][j+1] = max(v[i+1][j+1], v[i][j] + r); // 오른쪽
        }
    }
    
    int size = v.size();
    int answer = 0;
    for (int tmp : v[size-1]) {
        answer = max(answer, tmp);
    }
    return answer;
}
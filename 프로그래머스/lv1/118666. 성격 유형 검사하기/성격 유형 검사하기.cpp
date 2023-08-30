#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 더 높은 점수를 받은 성격 유형
// 성격 유형 점수가 같으면, 사전순으로 빠른거

map<char, int> m;

string solution(vector<string> survey, vector<int> choices) {
    m['R'] = 0; m['T'] = 0;
    m['C'] = 0; m['F'] = 0;
    m['J'] = 0; m['M'] = 0;
    m['A'] = 0; m['N'] = 0;
    
    int size = survey.size();
    
    for (int i=0; i<size; i++) {
        int tmp = choices[i] - 4;
        if (tmp < 0) m[survey[i][0]] += abs(tmp);
        if (tmp > 0) m[survey[i][1]] += tmp;
    }
    
    string answer = "";
    
    answer += (m['R'] < m['T']) ? "T" : "R";
    answer += (m['C'] < m['F']) ? "F" : "C";
    answer += (m['J'] < m['M']) ? "M" : "J";
    answer += (m['A'] < m['N']) ? "N" : "A";
    
    return answer;
}
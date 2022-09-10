#include <vector>
#include <string>
#include <iostream>

using namespace std;

int minCuts(string str) {
    if (str.empty())
        return 0;

    // str에 있는 모든 가능한 palindrome 검사 후
    // left, right 범위의 하위 문자열이 palindrome인지 여부 저장
    vector<vector<bool>> isPalindrome(str.length() + 1, vector<bool>(str.length() + 1));

    for (int right = str.length() - 1; right >= 0; right--) {
        for (int left = right; left < str.length(); left++) {
            if (left == right) {
                // 단일 문자는 무조건 palindrome
                isPalindrome[right][left] = true;
            }
            else if (str[left] == str[right] && left == right + 1) {
                // 두 문자가 같은 경우 palindrome
                isPalindrome[right][left] = true;
            }
            else if (str[left] == str[right]) {
                // 이전에 저장된 palindrome 여부 이용
                isPalindrome[right][left] = isPalindrome[right + 1][left - 1];
            }
        }
    }

    // 문자열 인덱스 i부터 끝까지 palindrome을 만들기 위한 최소 컷수 저장
    vector<int> min_cuts(str.length(), 1e9);

    // 문자열 끝에서 부터 거꾸로 계산
    for (int i = str.length() - 1; i >= 0; i--) {
        if (isPalindrome[i][str.length() - 1]) {
            // 문자열 인덱스 i부터 끝까지 palindrome인 경우 컷할 필요가 없음
            min_cuts[i] = 0;
        }
        else {
            // palindrome이 아닐 경우, 문자열 인덱스 i부터 끝 바로 전까지
            // palindrome을 찾아서 최소 컷의 갯수 업데이트
            for (int j = str.length() - 2; j >= i; j--) {
                if (isPalindrome[i][j] && min_cuts[i] > min_cuts[j + 1] + 1) {
                    min_cuts[i] = min_cuts[j + 1] + 1;
                }
            }
        }
    }

    return min_cuts[0];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin>>s;
    cout<< minCuts(s) + 1;
}
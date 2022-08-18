#include<iostream>
#include<string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; getline(cin, s); // 공백 포함 문자열 입력
    int cnt = 0; // 단어의 개수
    if(s.length() == 0) {
        cout<<0;
        return 0;
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') cnt++;
    }

    if (s[0] != ' ' && s[s.length() - 1] != ' ') cout << cnt + 1; // 문자열이 공백으로 시작하거나 끝나지 않는 경우
    else if (s[0] == ' ' && s[s.length() - 1] == ' ') cout << cnt - 1; // 문자열이 공백으로 시작하고 끝나는 경우
    else cout << cnt;

    return 0;
}
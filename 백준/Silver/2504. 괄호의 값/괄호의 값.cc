// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool isPossible(string s){
    stack<char> st;
    for(auto cur : s){
        if(cur == '(' || cur == '['){
            st.push(cur);
        }else{
            if(st.size() > 0){
                if(st.top() == '(' && cur == ')') st.pop();
                else if(st.top() == '[' && cur == ']') st.pop();
                else return false;
            }else return false;
        }
    }

    return st.empty();
}

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<char> st;
    vector<int> res;
    string s;
    cin >> s;

    if(!isPossible(s)) {
        cout<<0<<"\n";
        return 0;
    }

    int result = 0;
    int tmp = 1;
    char prev;
    for(auto cur : s){
        switch (cur) {
            case '(':
                tmp *= 2;
                break;
            case '[':
                tmp *= 3;
                break;
            case ')':
                if(prev == '(') result += tmp;
                tmp /= 2;
                break;
            case ']':
                if(prev == '[') result += tmp;
                tmp /= 3;
                break;
        }
        prev = cur;
    }

    cout<<result<<"\n";

    return 0;
}
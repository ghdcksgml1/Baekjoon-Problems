// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

stack<char> st;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; // string을 담을 변수 s
    string result = ""; // 결과를 담을 변수 result
    getline(cin, s); // getline을 통해 한줄 전체를 가져옴.

    /*
     * 해결 방법 : '<', '>', ' ' 가 올경우 스택에 넣는것을 멈추고 지금까지 받아온 문자를
     * result에 스택이 빌때까지 빼면서 넣어준다.
     *
     * '<' 기호가 나온경우에는 일단 기존에 스택에 있던 요소들을 전부빼서 result에 넣어주고,
     * '>'기호가 나올때까지 그대로 result에 바로 넣어준다.
     */

    bool trigger = false; // 이 트리거는 '<'기호가 나왔을때 켜지고, 켜져있으면 result에 바로들어감.
    for(int i=0; i<s.size(); i++){
        if(s[i] == '>'){
            result += s[i];
            trigger = false;
        }
        else if(trigger){
            result += s[i];
        }
        else if(s[i] == '<' || s[i] == ' '){
            if(s[i] == '<') trigger = true; // 트리거 켜주기
            while(st.size() > 0){
                result += st.top();
                st.pop();
            }
            result += s[i];
        }else{
            st.push(s[i]);
        }
    }

    // 스택에 요소가 남아있을경우 result에 전부 넣어줌.
    while(st.size() > 0){
        result += st.top();
        st.pop();
    }

    cout<<result<<"\n";


    return 0;
}
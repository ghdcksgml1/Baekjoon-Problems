// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
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

stack<double> st;

double alpha[26];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    string s; cin>>s;

    for(int i=0; i<N; i++){
        cin>>alpha[i];
    }

    for(int i=0; i<s.size(); i++){
        double num1 = 0.0;
        double num2 = 0.0;

        if(s[i] < 'A'){
            num1 = st.top(); st.pop();
            num2 = st.top(); st.pop();
            if(s[i] == '+'){
                st.push(num2 + num1);
            }else if(s[i] == '-'){
                st.push(num2 - num1);
            }else if(s[i] == '*'){
                st.push(num2 * num1);
            }else if(s[i] == '/'){
                st.push(num2 / num1);
            }

        }else{
            st.push(alpha[s[i] - 'A']);
        }
    }

    printf("%.2lf", st.top());

    return 0;
}
// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <deque>

using namespace std;

deque<char> dq;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(true){
        dq.clear();
        char a[101];
        cin.getline(a,101);
        string str = a;
        if(!str.compare(".")) break;

        bool trigger = false;
        for(int i=0;i<str.size();i++){
            if(str[i] == '('){
                dq.push_back('(');
            }else if(str[i] == ')'){
                if(dq.empty()){
                    trigger = true;
                    break;
                }
                if(dq.back() == '(') dq.pop_back();
                else{
                    trigger = true;
                    break;
                }
            }else if(str[i] == '['){
                dq.push_back('[');
            }else if(str[i] == ']'){
                if(dq.empty()){
                    trigger = true;
                    break;
                }
                if(dq.back() == '[') dq.pop_back();
                else{
                    trigger = true;
                    break;
                }
            }
        }

        if(trigger || !dq.empty()){
            cout<<"no"<<'\n';
        }else{
            cout<<"yes"<<'\n';
        }
    }

    return 0;
}
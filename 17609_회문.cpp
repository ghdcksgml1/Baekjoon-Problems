// 언어 : C++ , (성공/실패) : 1/1 , 메모리 : 2552 KB , 시간 : 20ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    while(N--){
        string str; cin>>str;

        int result = 0;
        int s_p=0, e_p=str.size()-1;
        while(s_p<=e_p){
            if(result == 2) break;
            if(str[s_p] == str[e_p]){
                s_p++; e_p--;
            }else{
                result++;
                if(str[s_p+1] == str[e_p]) s_p++;
                else if(str[s_p] == str[e_p-1]) e_p--;
            }
        }

        int result2 = 0;
        s_p=0, e_p=str.size()-1;
        while(s_p<=e_p){
            if(result2 == 2) break;
            if(str[s_p] == str[e_p]){
                s_p++; e_p--;
            }else{
                result2++;
                if(str[s_p] == str[e_p-1]) e_p--;
                else if(str[s_p+1] == str[e_p]) s_p++;
            }
        }
        cout<< min(result,result2)<<'\n';
    }
    // asjasa

    return 0;
}
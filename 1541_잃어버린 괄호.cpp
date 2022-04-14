// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2080 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <sstream>

using namespace std;

int tmp_i = 0;
vector<int> v;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str; cin>>str;

    string tmp = "";
    int result = 0;
    for(int i=0;i<str.size();i++){
        if(str[i] == '+'){
            istringstream ssInt(tmp);
            ssInt>>tmp_i;
            result += tmp_i;

            tmp = "";
        }else if(str[i] == '-'){
            istringstream ssInt(tmp);
            ssInt>>tmp_i;
            result += tmp_i;
            v.push_back(result);
            result = 0;

            tmp = "";
        }else {
            tmp += str[i];
        }
    }
    istringstream ssInt(tmp);
    ssInt >> tmp_i; result += tmp_i;
    v.push_back(result);

    int mn = v[0];
    for(int i=1;i<v.size();i++){
        mn -= v[i];
    }

    cout<<mn<<'\n';

    return 0;
}
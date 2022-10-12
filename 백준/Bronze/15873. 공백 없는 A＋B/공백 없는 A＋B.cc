// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
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

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin>>s;
    if(s[1] == '0' && s[3] == '0')
        cout<<20<<"\n";
    else if(s[1] == '0'){
        cout<<10+s[2]-'0'<<"\n";
    }else if(s[2] == '0'){
        cout<<10+s[0]-'0'<<"\n";
    }else{
        cout<<s[0]+s[1]-'0'-'0'<<"\n";
    }

    return 0;
}
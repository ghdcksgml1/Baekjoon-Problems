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

    string s;
    while(getline(cin,s)){
        // 소문자, 대문자, 숫자, 공백
        int res[4] = {0,0,0,0};
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z') res[0]++;
            else if(s[i]>='A' && s[i]<='Z') res[1]++;
            else if(s[i]>='0' && s[i]<='9') res[2]++;
            else if(s[i]==' ') res[3]++;
        }
        cout<<res[0]<<' '<<res[1]<<' '<<res[2]<<' '<<res[3]<<'\n';
    }

    return 0;
}
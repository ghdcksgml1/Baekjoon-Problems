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
    cin>>s;

    string result = "";
    for(int i=s.size()-1;i>=0;i-=3){
        int num[3] = {0,};

        num[2] = s[i] - '0';
        if(i-1 >= 0) num[1] = s[i-1] - '0';
        if(i-2 >= 0) num[0] = s[i-2] - '0';

        int res = (num[0]<<2) + (num[1]<<1) + num[2];
        result += to_string(res);
    }

    for(int i=result.size()-1;i>=0;i--){
        cout<<result[i];
    }

    return 0;
}
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

    string s="";
    string res = "";
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        int tmp;
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            if(s[i]>='a' && s[i]<='z'){
                tmp = s[i] - 'a' + 13;
                res += (tmp>=26?tmp-26+'a':tmp+'a');
            }
            else if(s[i]>='A' && s[i]<='Z'){
                tmp = s[i] - 'A' + 13;
                res += (tmp>=26?tmp-26+'A':tmp+'A');
            }
        }else{
            res += s[i];
        }
    }
    cout<<res<<'\n';


    return 0;
}
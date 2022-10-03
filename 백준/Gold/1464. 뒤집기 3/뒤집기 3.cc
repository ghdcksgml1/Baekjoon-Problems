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

int swap(string &s, int idx){
    string tmp = s.substr(0,idx);
    reverse(tmp.begin(), tmp.end());
    s = tmp + s.substr(idx);

    return s[0] - 'A';
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin>>s;
    int num = s[0]-'A';
    for(int i=1; i<s.size(); i++){
        if(s[i] < s[i-1] && num >= s[i]-'A'){
            swap(s, i);
            num = swap(s, i+1);
        }
    }

    cout<<s<<"\n";

    return 0;
}
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

int cnt[10];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '6' || s[i] == '9'){
            if(cnt[6] == cnt[9]) cnt[6]++;
            else cnt[9]++;
        }else{
            cnt[s[i] - '0']++;
        }
    }

    int mx = 0;
    for(int i=0; i<10; i++){
        mx = max(mx, cnt[i]);
    }

    cout<<mx<<"\n";

    return 0;
}
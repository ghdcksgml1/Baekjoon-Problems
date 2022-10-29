// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <math.h>

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

    ll num = stoi(s);
    ll sum = 0;
    ll i;
    for(i=0; i<s.size()-1; i++){
        sum += (pow(10, i) * 9) * (i+1);
    }
    sum += ((num - pow(10, i) + 1) * (ll)s.size());

    cout<<sum<<"\n";

    return 0;
}
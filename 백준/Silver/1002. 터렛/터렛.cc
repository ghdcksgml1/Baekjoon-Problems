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

    int T; cin>>T;
    while(T--){
        ll x1,y1,r1; cin>>x1>>y1>>r1;
        ll x2,y2,r2; cin>>x2>>y2>>r2;

        ll d = floor(pow(x2-x1, 2) + pow(y2-y1, 2));
        if(x1==x2 && y1==y2 && r1==r2) cout<<-1<<'\n';
        else if(x1==x2 && y1==y2) cout<<0<<'\n';
        else if(d < pow(r1,2) || d < pow(r2,2)){
            if(pow(r1-r2,2) == d){
                cout<<1<<'\n';
            }else if(pow(r1-r2, 2) < d){
                cout<<2<<'\n';
            }else
                cout<<0<<'\n';
        }
        else if(d == pow(r1+r2,2)) cout<<1<<'\n';
        else if(d < pow(r1+r2,2)) cout<<2<<'\n';
        else cout<<0<<'\n';
    }

    return 0;
}
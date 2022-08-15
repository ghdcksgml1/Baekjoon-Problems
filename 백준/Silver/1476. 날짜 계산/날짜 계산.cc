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

    int E,S,M; cin>>E>>S>>M;

    int a=1,b=1,c=1;
    int cnt = 1;

    while(E!=a || S!=b || M!=c){
        a++; b++; c++;
        if(a==16) a=1;
        if(b==29) b=1;
        if(c==20) c=1;
        cnt++;
    }

    cout<<cnt<<'\n';

    return 0;
}
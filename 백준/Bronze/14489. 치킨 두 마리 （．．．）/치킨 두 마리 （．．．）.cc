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
    
    int A,B,C; cin>>A>>B>>C;
    
    if(A+B < 2*C){
        cout<<A+B<<"\n";
    }else{
        cout<<(A+B)-(2*C)<<"\n";
    }
    
    return 0;
}
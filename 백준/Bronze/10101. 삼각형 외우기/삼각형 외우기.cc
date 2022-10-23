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
    
    int a,b,c; cin>>a>>b>>c;
    
    if(a==60 && b==60 && c==60) cout<<"Equilateral";
    else if(a+b+c != 180) cout<<"Error";
    else if(a!=b && b!=c && a!=c) cout<<"Scalene";
    else cout<<"Isosceles";
    
    return 0;
}

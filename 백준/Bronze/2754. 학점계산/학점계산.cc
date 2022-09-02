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

    string a; cin>>a;
    if(a == "A+") cout<<"4.3";
    else if(a == "A0") cout<<"4.0";
    else if(a == "A-") cout<<"3.7";
    else if(a == "B+") cout<<"3.3";
    else if(a == "B0") cout<<"3.0";
    else if(a == "B-") cout<<"2.7";
    else if(a == "C+") cout<<"2.3";
    else if(a == "C0") cout<<"2.0";
    else if(a == "C-") cout<<"1.7";
    else if(a == "D+") cout<<"1.3";
    else if(a == "D0") cout<<"1.0";
    else if(a == "D-") cout<<"0.7";
    else if(a == "F") cout<<"0.0";

    return 0;
}
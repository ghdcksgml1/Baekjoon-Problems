// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

map<string,double> um;

int main(void){
    // 입출력 속도 최적화
    string s;

    double cnt = 0;
    while(getline(cin,s)){
        um[s]+=1;
        cnt++;
    }

    map<string,double>::iterator iter;
    for(iter = um.begin();iter != um.end();iter++){
        cout<<iter->first;
        printf(" %.4lf\n",(double)um[iter->first]/cnt*100);
    }

    return 0;
}
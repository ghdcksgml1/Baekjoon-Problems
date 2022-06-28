// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
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

    int n = 8, cnt = 0;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        for(int j=0;j<n;j++){
            if(i&1){
                if(j%2 == 1 && s[j]=='F') cnt++;
            }else{
                if(j%2 == 0 && s[j]=='F') cnt++;
            }
        }
    }

    cout<<cnt<<'\n';

    return 0;
}
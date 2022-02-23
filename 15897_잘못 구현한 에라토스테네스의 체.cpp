// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;
typedef long long ll;
ll n;
ll ans=0;
int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    ans = n;
    n -= 1;
    for(int i=1,j;i<=n;i=j+1){
        j=n/(n/i);
        ans += n/i*(j-i+1);
    }

    cout<<ans<<'\n';

    return 0;
}
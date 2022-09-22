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

    int N; cin>>N;
    while(N--){
        int tmp; cin>>tmp;
        int a[4];
        a[0] = tmp/25; tmp %= 25;
        a[1] = tmp/10; tmp %= 10;
        a[2] = tmp/5; tmp %= 5;
        a[3] = tmp;
        for(int i=0; i<4; i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
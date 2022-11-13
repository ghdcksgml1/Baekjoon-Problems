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

    int sum;
    for(int i=1; i<=N; i++){
        int tmp = i;
        sum = tmp;
        while(tmp != 0){
            sum += (tmp % 10);
            tmp /= 10;
        }

        if(sum == N){
            cout<<i;
            return 0;
        }
    }

    cout<<0;

    return 0;
}
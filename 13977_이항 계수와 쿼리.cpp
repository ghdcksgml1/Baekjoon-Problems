// 언어 : C++ , (성공/실패) : 1/1 , 메모리 : 33272 KB , 시간 : 100 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;
typedef long long ll;

ll const PN = 1000000007;

ll N,R;

ll dp[4000001];

void factorial(){
    ll result = 1;
    dp[0] = 1;
    for(int i=1;i<=4000000;i++){
        result = (result*i) % PN;
        dp[i] = result;
    }
}


int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    factorial();

    int M;
    cin>>M;

    while(M--) {

        cin >> N >> R;

        ll A = dp[N];
        ll B = (dp[R] * dp[N - R]) % PN;

        ll pow = PN - 2;
        ll result = 1;
        while (pow > 0) {
            if (pow % 2 == 1) {
                result = (result * B) % PN;
            }
            B = (B * B) % PN;
            pow /= 2;
        }

        cout << (A * result) % PN << '\n';
    }

    return 0;
}
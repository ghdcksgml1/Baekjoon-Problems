// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2020 KB , 시간 : 8ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;
typedef long long ll;

const ll PN = 1000000007;

ll factorial(int x){
    ll result = 1;
    for(int i=1;i<=x;i++){
        result = (result*i) % PN;
    }
    return result;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll N,M;
    cin>>N>>M;

    ll A = factorial(N);
    ll B = (factorial(M) * factorial(N-M)) % PN;

    ll pow = PN - 2;
    ll result = 1;
    while(pow > 0){
        if(pow%2 == 1){
            result = (result * B) % PN;
        }
        B = (B*B) % PN;
        pow /= 2;
    }

    cout<<(A*result)%PN<<'\n';

    return 0;
}
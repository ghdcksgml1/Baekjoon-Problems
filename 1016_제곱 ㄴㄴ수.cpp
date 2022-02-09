// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 5648 KB , 시간 : 36 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <math.h>

using namespace std;

typedef long long ll;

bool prime_number[1000001];
bool check[1000001];
vector<ll> num;

int 에라토스테네스의체(ll Min,ll Max){

    // 소수를 구한다. (소수를 구하는 이유, 그냥 제곱수를 찾을 수도 있지만, 2의 제곱:4, 4의 제곱은:16
    // 처럼 겹치는 것까지 들어가게된다. 따라서 소수를 구해서 거기에 제곱을 하면
    // 배열에 4, 16과 같이 제곱 ㄴㄴ수의 중복을 줄일 수 있다.
    for(int i=2;i*i<=sqrt(Max);i++){
        for(int j=2;i*j<=sqrt(Max);j++){
            prime_number[i*j] = true;
        }
    }

    // 구한 소수를 vector에 넣어준다.
    for(int i=2;i<=sqrt(Max);i++){
        if(!prime_number[i]) {
            num.push_back(i);
        }
    }

    // 소수를 제곱한뒤 값을 구해준다.
    int cnt = 0;
    for(int i=0;i<num.size();i++){
        ll start;
        ll pow = num[i] * num[i];
        if(Min%pow == 0) start = Min/pow;
        else start = Min/pow + 1;
        for(ll j = start;pow*j<=Max;j++){
            if(check[pow*j-Min]) continue;
            cnt++;
            check[pow*j-Min] = true;
        }
    }
    return cnt;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll mn,mx;
    cin>>mn>>mx;
    cout<<(mx-mn+1-에라토스테네스의체(mn,mx));

    return 0;
}
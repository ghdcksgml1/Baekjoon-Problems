// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2020 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;
typedef long long ll;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll N,K; cin>>N>>K;

    /*
     * 수식
     * a + b = N
     * (a+1) x (b+1) = K
     *
     * 문자를 하나로 치환시켜보면,
     * (N+1-b) x (b+1) = K인데
     * N과 K는 주어지므로, b를 구하면 된다~~
     *
     * b의 범위는 0에서 N까지이므로, 0에서 N까지의 이분탐색을 통해서
     * 값이 정확하게 맞는 값을 구하면 완료!!
     * */


    string result = "NO";
    ll st = 0, en = N;
    while(st <= en){
        ll mid = (st + en) / (ll)2;
        if((N+1-mid)*(mid+1) >= K){
            if((N+1-mid)*(mid+1) == K) result = "YES";
            en = mid - 1;
        }else{
            st = mid + 1;
        }
    }

    cout<<result<<'\n';

    return 0;
}
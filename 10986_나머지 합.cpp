// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;
typedef long long ll;
ll arr[1000001];
ll cnt[1001];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M; cin>>N>>M;

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    ll sum = 0;
    ll result = 0;
    for(int i=0;i<N;i++){
        sum = (sum +arr[i]) % M;
        if(sum == 0) result++;
        cnt[sum]++;
    }

    for(int i=0;i<M;i++){
        if(cnt[i] > 0){
            result += ((cnt[i]*(cnt[i]-1))/2);
        }
    }

    cout<<result<<'\n';

    return 0;
}
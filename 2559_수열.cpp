// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2412 KB , 시간 : 8 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int arr[100001];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,K; cin>>N>>K;
    for(int i=0;i<N;i++) cin>>arr[i];

    int st=0,en=K-1,sum=0,mx=-1000000000;
    for(int i=0;i<K;i++) sum+=arr[i];
    mx = max(mx,sum);

    while(en<N-1){
        sum -= arr[st++];
        sum += arr[++en];
        mx = max(mx,sum);
    }
    cout<<mx<<'\n';
    return 0;
}
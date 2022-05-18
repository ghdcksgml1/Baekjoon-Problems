// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2412 KB , 시간 : 12ms
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

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];
    int x; cin>>x;

    sort(arr,arr+N);

    int cnt=0;
    int s_p=0, e_p=N-1, sum=arr[s_p]+arr[e_p];
    while(s_p<e_p){
        if(sum == x) cnt++;
        if(sum >= x){
            sum -= arr[e_p];
            e_p--;
            sum += arr[e_p];

        }else{
            sum -= arr[s_p];
            s_p++;
            sum += arr[s_p];
        }
    }
    cout<<cnt<<'\n';

    return 0;
}
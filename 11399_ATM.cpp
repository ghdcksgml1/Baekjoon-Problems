// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int arr[1000];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;

    for(int i=0;i<N;i++) cin>>arr[i];

    sort(arr,arr+N);

    int sum = 0;
    int result = 0;
    for(int i=0;i<N;i++){
        sum += arr[i];
        arr[i] = sum;
    }

    for(int i=0;i<N;i++){
        result += arr[i];
    }
    cout<<result<<'\n';

    return 0;
}
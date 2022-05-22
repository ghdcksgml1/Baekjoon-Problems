// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2028 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int arr[1001];
int d[1001];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];

    for(int i=0;i<N;i++){
        d[i] = arr[i]; // 일단 d[i]의 값은 arr[i]가 들어간다.
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j])
                d[i] = max(d[i], d[j]+arr[i]);
        }
    }

    int mx = 0;
    for(int i=0;i<N;i++){
        mx = max(mx, d[i]);
    }

    cout<<mx<<'\n';

    return 0;
}
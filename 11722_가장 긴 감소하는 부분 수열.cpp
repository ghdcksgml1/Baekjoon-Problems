// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2028 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int a[1001];
int d[1001];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];

    for(int i=0;i<N;i++){
        d[i] = 1;
        for(int j=0;j<i;j++){
            if(a[i]<a[j]){
                d[i] = max(d[i],d[j]+1);
            }
        }
    }

    int mx = 0;
    for(int i=0;i<N;i++){
        mx = max(d[i],mx);
    }

    cout<<mx<<'\n';

    return 0;
}
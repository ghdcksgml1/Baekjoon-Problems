// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long N; cin>>N;

    long long result = 1;
    long long cnt = 0;
    for(long long i=1;i<=N;i++){
        result *= i;
        result %= 1000000000;
        while(true){
            if(result%10 == 0){
                result /= 10;
                cnt++;
            }else{
                break;
            }
        }
    }
    cout<<cnt<<'\n';

    return 0;
}
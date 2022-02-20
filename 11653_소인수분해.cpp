// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2020 KB , 시간 : 28ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin>>N;
    while(N>1){
        for(int i=2;i<=N;i++){
            if(N%i==0) {
                N /= i;
                cout<<i<<'\n';
                break;
            }
        }
    }


    return 0;
}
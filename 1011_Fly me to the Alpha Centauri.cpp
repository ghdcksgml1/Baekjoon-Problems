// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <cmath>

using namespace std;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        long long x,y; cin>>x>>y;
        long long diff = y-x;
        long long N=0;
        while(N*N <= diff){
            N++;
        }
        N-=1;
        long long move = 2*N - 1;
        long long rem = diff - N*N;
        // 차이를 N으로 나줘서 올림 해준다.
        rem = (long long)ceil((double)rem/(double)N);
        move += rem;
        cout<<move<<'\n';
    }

    return 0;
}
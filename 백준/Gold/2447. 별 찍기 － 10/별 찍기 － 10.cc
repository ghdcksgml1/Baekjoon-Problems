// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

void recur(int i, int j,int num){
    if((i/num)%3 == 1 && (j/num)%3 == 1){
        cout<<" ";
    }else{
        if(num/3==0)
            cout<<"*";
        else
            recur(i,j,num/3);
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            recur(i,j,N);
        }
        cout<<"\n";
    }

    return 0;
}
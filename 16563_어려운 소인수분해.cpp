// 언어 : C++ , (성공/실패) : 1/4 , 메모리 : 21552 KB , 시간 : 596ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int mem[5000001];

void era(){
    for(int i=2;i*i<=5000000;i++){
        if(mem[i]) continue;
        for(int j=2;i*j<=5000000;j++){
            if(!mem[i*j])
                mem[i*j] = i;
        }
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin>>N;
    era();

    while(N--){
        int tmp; cin>>tmp;
        while(mem[tmp]){
            cout<<mem[tmp]<<' ';
            tmp /= mem[tmp];
        }
        cout<<tmp<<'\n';
    }

    return 0;
}
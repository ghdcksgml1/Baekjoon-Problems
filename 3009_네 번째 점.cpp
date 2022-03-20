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

    int a[3],b[3];
    for(int i=0;i<3;i++){
        cin>>a[i]>>b[i];
    }
    if(a[0] == a[1]) cout<<a[2]<<' ';
    if(a[1] == a[2]) cout<<a[0]<<' ';
    if(a[0] == a[2]) cout<<a[1]<<' ';
    if(b[0] == b[1]) cout<<b[2];
    if(b[1] == b[2]) cout<<b[0];
    if(b[0] == b[2]) cout<<b[1];

    return 0;
}
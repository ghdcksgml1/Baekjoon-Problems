// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2148 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int arr[30001];
int dish[3001];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,d,k,c; cin>>N>>d>>k>>c;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    int cnt=0;
    for(int i=0;i<k;i++){
        if(dish[arr[i]] == 0) cnt++;
        dish[arr[i]]++;
    }
    int mx = dish[c]==0?cnt+1:cnt;
    for(int i=0;i<N;i++){
        dish[arr[i]]--;
        if(dish[arr[i]]==0) cnt--;
        if(dish[arr[(i+k)%N]] == 0) cnt++;
        dish[arr[(i+k)%N]]++;
        mx = max(mx, dish[c]==0?cnt+1:cnt);
    }

    cout<<mx<<'\n';

    return 0;
}
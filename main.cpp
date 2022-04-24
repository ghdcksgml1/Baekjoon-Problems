// 언어 : C++ , (성공/실패) : 1/2 , 메모리 : 63120 KB , 시간 : 1396ms
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string.h> // memset
#define MAX 5000000

using namespace std;

int arr[MAX];
deque<pair<int,int>> dq;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,L;
    cin>>N>>L;

    for(int i=0;i<N;i++) cin>>arr[i];

    for(int i=0;i<N;i++){
        // 인덱스가 i-L보다 작거나 같은게 있으면 없애준다.
        while(!dq.empty() && dq.front().second <= i-L)
            dq.pop_front();

        // 현재 arr값보다 dq.back()의 값이 더 크다면 없애준다.
        while(!dq.empty() && dq.back().first > arr[i])
            dq.pop_back();

        dq.push_back({arr[i],i});
        cout<<dq.front().first<<' ';
    }

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h> // memset

using namespace std;

int N;
int arr[1000010];
int L[1000010];

int bin_search(int st,int en,int target){
    while(st < en){
        int mid = (st+en) / 2;
        if(L[mid] >= target) en = mid;
        else st = mid+1;
    }
    return st;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    L[0] = arr[0];
    int len = 1;
    int idx;
    for(int i=1;i<N;i++){
        idx = bin_search(0,len,arr[i]);
        L[idx] = arr[i];
        if(idx == len)
            len++;
    }

    cout<<len<<'\n';


    return 0;
}
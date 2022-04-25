// 언어 : C++ , (성공/실패) : 1/1 , 메모리 : 21552 KB , 시간 : 416ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 1000001

using namespace std;

struct Tree{
    int mn=0;
}tree[MAX*4];

int arr[MAX];

int buildRec(int node,int start,int end){
    if(start == end){
        return tree[node].mn = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node].mn = max(buildRec(node*2,start,mid), buildRec(node*2+1,mid+1,end));
}

int queryRec(int left,int right,int node,int start,int end){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right){
        return tree[node].mn;
    }
    int mid = (start + end) / 2;
    return max(queryRec(left,right,node*2,start,mid), queryRec(left,right,node*2+1,mid+1,end));
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M; cin>>N>>M;
    for(int i=1;i<=N;i++) cin>>arr[i];
    buildRec(1,1,N);

    for(int i=M;i<=N-M+1;i++){
        cout<<queryRec(i-(M-1),i+(M-1),1,1,N)<<' ';
    }

    return 0;
}
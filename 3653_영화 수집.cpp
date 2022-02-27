// 언어 : C++ , (성공/실패) : 1/1 , 메모리 : 5536 KB , 시간 : 252 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 100001

using namespace std;

struct Tree{
    int value;
}tree[MAX*6];

int arr[MAX];
int sum_arr[MAX*2];
int idx;
int N,M;

// 세그먼트 트리 생성
int buildRec(int node,int start,int end){
    if (start==end){
        return tree[node].value = sum_arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node].value = buildRec(node*2,start,mid) + buildRec(node*2+1,mid+1,end);
}

// 구간 합 구하기
int queryRec(int left,int right,int node,int start,int end){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right){
        return tree[node].value;
    }
    int mid = (start + end) / 2;
    return queryRec(left,right,node*2,start,mid) + queryRec(left,right,node*2+1,mid+1,end);
}

// 한 곳 업데이트
int updateRec(int target,int value,int node,int start,int end){
    if(target>end || target<start) return tree[node].value;
    if(start == end){
        return tree[node].value = value;
    }
    int mid = (start + end) / 2;
    return tree[node].value = updateRec(target,value,node*2,start,mid) + updateRec(target,value,node*2+1,mid+1,end);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;cin>>T;
    while(T--){
        // 초기화
        memset(tree,0,sizeof(tree));
        memset(arr,0,sizeof(arr));
        memset(sum_arr,0,sizeof(sum_arr));
        //
        cin>>N>>M;
        idx = M;
        for(int i=1;i<=N;i++){
            sum_arr[M+i]=1;
            arr[i] = M+i;
        }
        buildRec(1,1,N+M);

        for(int i=0;i<M;i++){
            int tmp; cin>>tmp;
            cout<<queryRec(idx,arr[tmp]-1,1,1,N+M)<<' ';
            updateRec(arr[tmp],0,1,1,N+M);
            updateRec(idx,1,1,1,N+M);
            arr[tmp] = idx;
            idx--;
        }
        cout<<'\n';
    }

    return 0;
}
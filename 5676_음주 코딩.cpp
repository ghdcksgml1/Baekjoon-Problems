// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 3972 KB , 시간 : 120 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 100001

using namespace std;

struct Tree{
    int value;
} tree[4*MAX];

int arr[MAX];

int buildRec(int node,int start,int end){
    if(start == end){
        return tree[node].value = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node].value = buildRec(node*2,start,mid) * buildRec(node*2+1,mid+1,end);
}

int queryRec(int left,int right,int node,int start,int end){
    if(left>end || right<start) return 1;
    if(left<=start && end<=right){
        return tree[node].value;
    }
    int mid = (start + end) / 2;
    return queryRec(left,right,node*2,start,mid) * queryRec(left,right,node*2+1,mid+1,end);
}

int updateRec(int target,int value,int node,int start,int end){
    if(target>end || target<start) return tree[node].value;
    if(start == end){
        return tree[node].value = value;
    }
    int mid = (start + end) / 2;
    return tree[node].value = updateRec(target,value,node*2,start,mid) * updateRec(target,value,node*2+1,mid+1,end);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,K;

    while(cin>>N>>K){
        for(int i=1;i<=N;i++){
            cin>>arr[i];
            if(arr[i] > 0) arr[i] = 1;
            else if(arr[i] < 0) arr[i] = -1;
            else arr[i] = 0;
        }
        buildRec(1,1,N);

        while(K--){
            char A;int B,C;
            cin>>A>>B>>C;
            if(A=='C'){
                if(C > 0) C = 1;
                else if(C < 0) C = -1;
                else C = 0;
                updateRec(B,C,1,1,N);
            }else{
                int tmp = queryRec(B,C,1,1,N);
                if(tmp==1) cout<<"+";
                else if(tmp==0) cout<<"0";
                else cout<<"-";
            }
        }
        cout<<'\n';
    }

    return 0;
}
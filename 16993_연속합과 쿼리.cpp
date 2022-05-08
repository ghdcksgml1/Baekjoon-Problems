// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 8660 KB , 시간 : 80ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 100001

using namespace std;
typedef long long ll;

struct Tree{
    int Lsum;
    int Rsum;
    int MaxSum;
    int TotalSum;
}tree[MAX*4];

int arr[MAX];

Tree buildRec(int node,int start,int end){
    if(start == end){
        tree[node].Lsum = arr[start];
        tree[node].Rsum = arr[start];
        tree[node].MaxSum = arr[start];
        tree[node].TotalSum = arr[start];
        return tree[node];
    }
    int mid = (start + end) / 2;
    Tree leftVal = buildRec(node*2,start,mid);
    Tree rightVal = buildRec(node*2+1,mid+1,end);
    tree[node].Lsum = max(leftVal.Lsum,leftVal.TotalSum+rightVal.Lsum);
    tree[node].Rsum = max(rightVal.Rsum,rightVal.TotalSum+leftVal.Rsum);
    tree[node].TotalSum = leftVal.TotalSum + rightVal.TotalSum;
    tree[node].MaxSum = max({leftVal.MaxSum,rightVal.MaxSum,leftVal.Rsum + rightVal.Lsum});
    return tree[node];
}

Tree queryRec(int left,int right,int node,int start,int end){
    if(left>end || right<start) {
        return {-1001,-1001,-1001,-1001};
    }
    if(left<=start && end<=right){
        return tree[node];
    }
    int mid = (start + end) / 2;
    Tree tmp;
    Tree leftVal = queryRec(left,right,node*2,start,mid);
    Tree rightVal = queryRec(left,right,node*2+1,mid+1,end);
    tmp.Lsum = max(leftVal.Lsum,leftVal.TotalSum+rightVal.Lsum);
    tmp.Rsum = max(rightVal.Rsum,rightVal.TotalSum+leftVal.Rsum);
    tmp.TotalSum = leftVal.TotalSum + rightVal.TotalSum;
    tmp.MaxSum = max({leftVal.MaxSum,rightVal.MaxSum,leftVal.Rsum + rightVal.Lsum});
    return tmp;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }

    buildRec(1,1,N);

    int M; cin>>M;
    while(M--){
        int i,j; cin>>i>>j;
        cout<<queryRec(i,j,1,1,N).MaxSum<<'\n';
    }

    return 0;
}
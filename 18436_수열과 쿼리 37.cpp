// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 5536 KB , 시간 : 76 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 100001

using namespace std;

struct Tree{
    int o = 0; // 홀수
    int e = 0; // 짝수
} tree[4*MAX];

int arr[MAX];

void buildRec(int node,int start,int end){
    if(start == end){
        if(arr[start]%2 == 1) tree[node].o = 1;
        else tree[node].e = 1;
        return ;
    }
    int mid = (start + end) / 2;
    buildRec(node*2,start,mid);
    buildRec(node*2+1,mid+1,end);
    tree[node].o = tree[node*2].o + tree[node*2+1].o;
    tree[node].e = tree[node*2].e + tree[node*2+1].e;
    return ;
}

int queryRec2(int left,int right,int node,int start,int end){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right){
        return tree[node].e;
    }
    int mid = (start + end) / 2;
    return queryRec2(left,right,node*2,start,mid) + queryRec2(left,right,node*2+1,mid+1,end);
}

int queryRec3(int left,int right,int node,int start,int end){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right){
        return tree[node].o;
    }
    int mid = (start + end) / 2;
    return queryRec3(left,right,node*2,start,mid) + queryRec3(left,right,node*2+1,mid+1,end);
}

Tree updateRec(int target,int value,int node,int start,int end){
    if(target>end || target<start) return tree[node];
    if(start == end){
        tree[node].o = 0; tree[node].e = 0;
        if(value & 1) tree[node].o = 1;
        else tree[node].e = 1;
        return tree[node];
    }
    int mid = (start + end) / 2;
    Tree leftNode = updateRec(target,value,node*2,start,mid);
    Tree rightNode = updateRec(target,value,node*2+1,mid+1,end);
    tree[node].o = leftNode.o + rightNode.o;
    tree[node].e = leftNode.e + rightNode.e;
    return tree[node];
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,K;
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>arr[i];

    buildRec(1,1,N);

    cin>>K;
    while(K--){
        int a,b,c; cin>>a>>b>>c;
        if(a==1){
            updateRec(b,c,1,1,N);
        }else if(a==2){
            cout<<queryRec2(b,c,1,1,N)<<'\n';
        }else{
            cout<<queryRec3(b,c,1,1,N)<<'\n';
        }
    }

    return 0;
}
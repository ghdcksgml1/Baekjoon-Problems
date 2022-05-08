// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 5536 KB , 시간 : 80ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 100001

using namespace std;

struct Tree{
    int first;
    int second;
}tree[MAX*4];

int arr[MAX];

Tree buildRec(int node,int start,int end){
    if(start == end){
        tree[node].first = arr[start];
        tree[node].second = 0;
        return tree[node];
    }
    int mid = (start + end) / 2;
    Tree leftVal = buildRec(node*2,start,mid);
    Tree rightVal = buildRec(node*2+1,mid+1,end);
    if(leftVal.first > rightVal.first){
        tree[node].first = leftVal.first;
        tree[node].second = max(leftVal.second,rightVal.first);
    }else{
        tree[node].first = rightVal.first;
        tree[node].second = max(rightVal.second,leftVal.first);
    }
    return tree[node];
}

Tree queryRec(int left,int right,int node,int start,int end){
    if(left>end || right<start) return {0,0};
    if(left<=start && end<=right){
        return tree[node];
    }
    int mid = (start + end) / 2;
    Tree tmp;
    Tree leftVal = queryRec(left,right,node*2,start,mid);
    Tree rightVal = queryRec(left,right,node*2+1,mid+1,end);
    if(leftVal.first > rightVal.first){
        tmp.first = leftVal.first;
        tmp.second = max(leftVal.second,rightVal.first);
    }else{
        tmp.first = rightVal.first;
        tmp.second = max(rightVal.second,leftVal.first);
    }
    return tmp;
}

Tree updateRec(int target,int value,int node,int start,int end){
    if(target>end || target<start) return tree[node];
    if(start == end){
        tree[node].first = value;
        return tree[node];
    }
    int mid = (start + end) / 2;
    Tree leftVal = updateRec(target,value,node*2,start,mid);
    Tree rightVal = updateRec(target,value,node*2+1,mid+1,end);
    if(leftVal.first > rightVal.first){
        tree[node].first = leftVal.first;
        tree[node].second = max(leftVal.second,rightVal.first);
    }else{
        tree[node].first = rightVal.first;
        tree[node].second = max(rightVal.second,leftVal.first);
    }
    return tree[node];
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=1;i<=N;i++) cin>>arr[i];

    buildRec(1,1,N);

    int M; cin>>M;
    while(M--){
        int x,y,z; cin>>x>>y>>z;
        if(x==1){
            updateRec(y,z,1,1,N);
        }else{
            Tree tmp = queryRec(y,z,1,1,N);
            cout<<tmp.first + tmp.second<<'\n';
        }
    }

    return 0;
}
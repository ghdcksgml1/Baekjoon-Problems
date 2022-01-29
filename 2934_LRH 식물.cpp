// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 4364 KB , 시간 : 120 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

struct Tree{
    int value = 0;
    int lazy = 0;
}tree[100001*3];

int N;

void propagation(int node,int start,int end){
    if(tree[node].lazy){
        tree[node].value += (end-start+1)*tree[node].lazy;
        if(start != end){
            tree[node*2].lazy += tree[node].lazy;
            tree[node*2+1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }
}

int searchRec(int idx,int node,int start,int end){
    propagation(node,start,end);
    if(idx > end || idx < start) return 0;
    if(start == end){
        int tmp = tree[node].value;
        tree[node].value = 0;
        return tmp;
    }
    int mid = (start + end) / 2;
    int leftVal = searchRec(idx,node*2,start,mid);
    int rightVal = searchRec(idx,node*2+1,mid+1,end);
    tree[node].value -= (leftVal+rightVal); // 나오면서 빼주기
    return (leftVal+rightVal);
}

void updateRec(int left,int right,int node,int start,int end){
    propagation(node,start,end);
    if(left > end || right < start) return;
    if(left<=start && end<=right){
        tree[node].value += (end-start+1);
        if(start != end){
            tree[node*2].lazy += 1;
            tree[node*2+1].lazy += 1;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRec(left,right,node*2,start,mid);
    updateRec(left,right,node*2+1,mid+1,end);
    tree[node].value = tree[node*2].value + tree[node*2+1].value;
    return;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        int L,R;
        cin>>L>>R;
        cout<<(searchRec(L,1,1,100000) + searchRec(R,1,1,100000))<<'\n';
        if(R-L != 1) updateRec(L+1,R-1,1,1,100000);
    }
    return 0;
}
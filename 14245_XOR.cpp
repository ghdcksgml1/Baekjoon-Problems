#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int N,M;
int arr[500001];
struct Node{
    int value = 0;
    int lazy = 0;
}Node[500000*4];

int buildRec(int node,int start,int end){
    if(start == end)
        return Node[node].value = arr[start];
    int mid = (start + end) / 2;
    return Node[node].value = buildRec(node*2,start,mid) ^ buildRec(node*2+1,mid+1,end);
}

void propagation(int node,int start,int end){
    int lazy = Node[node].lazy;
    if(lazy){
        Node[node].value ^= (lazy * ((end-start+1)%2));
        if(start != end){
            Node[node*2].lazy ^= lazy;
            Node[node*2+1].lazy ^= lazy;
        }
        Node[node].lazy = 0;
    }
}

void updateRec(int left,int right,int node,int start,int end,int val){
    propagation(node,start,end);
    if(left>end || right<start) return;
    if(left<=start && end<=right){
        Node[node].value ^= (val * ((end-start+1)%2));
        if (start != end) {
            Node[node * 2].lazy ^= val;
            Node[node * 2 + 1].lazy ^= val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRec(left,right,node*2,start,mid,val);
    updateRec(left,right,node*2+1,mid+1,end,val);
    Node[node].value = Node[node*2].value ^ Node[node*2+1].value;
}

int selectRec(int idx,int node,int start,int end){
    propagation(node,start,end);
    if(idx>end || idx<start) return Node[node].value; // X ^ 0 = X 여서
    if(start == end){
        return 0;
    }
    int mid = (start + end) / 2;
    return selectRec(idx,node*2,start,mid) ^ selectRec(idx,node*2+1,mid+1,end);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    buildRec(1,0,N-1);
    cin>>M;
    for(int i=0;i<M;i++){
        int t,a,b,c;
        cin>>t;
        if(t == 1){ // a,b의 원소에 c를 xor
            cin>>a>>b>>c;
            updateRec(a,b,1,0,N-1,c);
        }else{ // a 원소값 출력
            cin>>a;
            cout<<(Node[1].value ^ selectRec(a,1,0,N-1))<<'\n';
        }
    }

    return 0;
}
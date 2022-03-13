// 언어 : C++ , (성공/실패) : 1/2 , 메모리 : 5576 KB , 시간 : 500ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 101010

using namespace std;

struct Tree{
    int value;
}tree[4*MAX][2];

int T;
int N,K;
int arr[MAX];

void init(){
    for(int i=0;i<MAX;i++){
        arr[i] = i;
    }
}

int buildMaxRec(int node, int start, int end){
    if(start == end) {
        return tree[node][0].value = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node][0].value = max(buildMaxRec(node*2,start,mid), buildMaxRec(node*2+1,mid+1,end));
}

int buildMinRec(int node, int start, int end){
    if(start == end) {
        return tree[node][1].value = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node][1].value = min(buildMinRec(node*2,start,mid), buildMinRec(node*2+1,mid+1,end));
}

int queryMaxRec(int left,int right,int node,int start,int end){
    if(left > end || right < start) return -1;
    if(left<=start && end<=right){
        return tree[node][0].value;
    }
    int mid = (start + end) / 2;
    return max(queryMaxRec(left,right,node*2,start,mid),queryMaxRec(left,right,node*2+1,mid+1,end));
}

int queryMinRec(int left,int right,int node,int start,int end){
    if(left > end || right < start) return 1000000;
    if(left<=start && end<=right){
        return tree[node][1].value;
    }
    int mid = (start + end) / 2;
    return min(queryMinRec(left,right,node*2,start,mid),queryMinRec(left,right,node*2+1,mid+1,end));
}

int targetRec(int target,int num,int node,int start,int end){
    if(target > end || target < start) return 0;
    if(start == end){
        return tree[node][num].value;
    }
    int mid = (start + end) / 2;
    return targetRec(target,num,node*2,start,mid) + targetRec(target,num, node*2+1,mid+1,end);
}

int updateMaxRec(int target,int value,int node,int start,int end){
    if(target > end || target < start) return tree[node][0].value;
    if(start == end){
        return tree[node][0].value = value;
    }
    int mid = (start + end) / 2;
    return tree[node][0].value = max(updateMaxRec(target,value,node*2,start,mid),updateMaxRec(target,value, node*2+1,mid+1,end));
}

int updateMinRec(int target,int value,int node,int start,int end){
    if(target > end || target < start) return tree[node][1].value;
    if(start == end){
        return tree[node][1].value = value;
    }
    int mid = (start + end) / 2;
    return tree[node][1].value = min(updateMinRec(target,value,node*2,start,mid),updateMinRec(target,value, node*2+1,mid+1,end));
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();
    cin>>T;
    while(T--){
        cin>>N>>K;
        buildMaxRec(1,0,N-1);
        buildMinRec(1,0,N-1);
        for(int i=0;i<K;i++) {
            int A, B, C;
            cin >> A >> B >> C;
            if(B>C) {
                int tmp = B;
                B = C;
                C = tmp;
            }
            if(A == 0){
                int B_target = targetRec(B,0,1,0,N-1);
                int C_target = targetRec(C,0,1,0,N-1);
                updateMaxRec(B,C_target,1,0,N-1);
                updateMaxRec(C,B_target,1,0,N-1);
                updateMinRec(B,C_target,1,0,N-1);
                updateMinRec(C,B_target,1,0,N-1);
            }else{
                int result_max = queryMaxRec(B,C,1,0,N-1);
                int result_min = queryMinRec(B,C,1,0,N-1);

                if(result_max == C && result_min == B) cout<<"YES"<<'\n';
                else cout<<"NO"<<'\n';
            }
        }
    }

    return 0;
}
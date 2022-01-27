// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 5536 KB , 시간 : 52ms
#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int arr[100001];
struct Tree{
    int val = 0;
    int idx = 0;
}tree[400001];

Tree merge(Tree t1,Tree t2){
    Tree temp;
    if(t1.val > t2.val){
        temp.val = t2.val;
        temp.idx = t2.idx;
    }else{
        temp.val = t1.val;
        temp.idx = t1.idx;
    }
    return temp;
}

Tree buildRec(int node,int start,int end){
    if(start == end){
        tree[node].idx = start;
        tree[node].val = arr[start];
        return tree[node];
    }
    int mid = (start + end) / 2;
    Tree leftTree = buildRec(node*2,start,mid);
    Tree rightTree = buildRec(node*2+1,mid+1,end);
    return tree[node] = merge(leftTree,rightTree);
}

void query(int index,int value,int node,int start,int end){
    if(index > end || index < start) {
        return;
    }
    if(start == end){
        tree[node].val = value;
        tree[node].idx = index;
        return ;
    }
    int mid = (start + end) / 2;
    query(index,value,node*2,start,mid);
    query(index,value,node*2+1,mid+1,end);
    tree[node] = merge(tree[node*2],tree[node*2+1]);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i=1;i<=N;i++) cin>>arr[i];

    buildRec(1,1,N);

    cin>>M;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a;
        if(a == 1){
            cin>>b>>c;
            query(b,c,1,1,N);
        }else{
            cout<<tree[1].idx<<'\n';
        }
    }

    return 0;
}
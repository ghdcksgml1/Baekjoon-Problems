// 언어 : C++ , (성공/실패) : 1/3 , 메모리 : 17644 KB , 시간 : 60ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 1000001

using namespace std;

struct Tree{
    int value = 0;
}tree[MAX*4];

int buildRec(int node,int start,int end){
    if(start == end){
        return tree[node].value = 0;
    }
    int mid = (start + end) / 2;
    return tree[node].value = buildRec(node*2,start,mid) + buildRec(node*2+1,mid+1,end);
}

int addQuery(int target,int value,int node,int start,int end){
    if(target>end || target<start) return tree[node].value;
    if(start == end){
        tree[node].value += value;
        return tree[node].value;
    }
    int mid = (start + end) / 2;
    return tree[node].value = addQuery(target,value,node*2,start,mid) + addQuery(target,value,node*2+1,mid+1,end);
}

void searchQuery(int target,int node,int start,int end){
    int mid = (start + end) / 2;
    if(start != end){
        if(target <= tree[node*2].value){
            searchQuery(target,node*2,start,mid);
        }else{
            searchQuery(target-tree[node*2].value,node*2+1,mid+1,end);
        }
    }else{
        cout<<start<<'\n';
    }
    tree[node].value -= 1;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    buildRec(1,1,1000000);

    int N; cin>>N;
    for(int i=0;i<N;i++){
        int a,b,c;
        cin>>a;
        if(a==1){
            cin>>b;
            searchQuery(b,1,1,1000000);
        }else{
            cin>>b>>c;
            addQuery(b,c,1,1,1000000);
        }
    }

    return 0;
}
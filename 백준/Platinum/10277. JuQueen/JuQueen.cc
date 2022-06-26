// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 4587530

using namespace std;

struct Tree{
    int value = 0;
    int mn = 0;
    int lazy = 0;
}tree[MAX*4];

void propagation(int node,int start,int end){
    if(tree[node].lazy){
        tree[node].value += tree[node].lazy;
        tree[node].mn += tree[node].lazy;
        if(start != end){
            tree[node*2].lazy += tree[node].lazy;
            tree[node*2+1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }
}

void update(int left,int right,int node,int start,int end,int value){
    propagation(node,start,end);
    if(left>end || right<start) return;
    if(left<=start && end<=right){
        tree[node].value += value;
        tree[node].mn += value;
        if(start != end){
            tree[node*2].lazy += value;
            tree[node*2+1].lazy += value;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(left,right,node*2,start,mid,value);
    update(left,right,node*2+1,mid+1,end,value);
    tree[node].value = max(tree[node*2].value, tree[node*2+1].value);
    tree[node].mn = min(tree[node*2].mn, tree[node*2+1].mn);
}

int queryX(int left,int right,int node,int start,int end){
    propagation(node,start,end);
    if(left>end || right<start) return 0;
    if(left<=start && end<=right){
        return tree[node].value;
    }
    int mid = (start + end) / 2;
    return max(queryX(left,right,node*2,start,mid),
               queryX(left,right,node*2+1,mid+1,end));
}

int queryN(int left,int right,int node,int start,int end){
    propagation(node,start,end);
    if(left>end || right<start) return 1e9;
    if(left<=start && end<=right){
        return tree[node].mn;
    }
    int mid = (start + end) / 2;
    return min(queryN(left,right,node*2,start,mid),
               queryN(left,right,node*2+1,mid+1,end));
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int C,N,O; cin>>C>>N>>O;
    while(O--){
        string s; cin>>s;
        int x,y,z;
        if(!s.compare("change")){
            cin>>x>>y;
            x++;
            if(y>0){
                int tmp = queryX(x,x,1,1,C);
                y = (tmp+y)>N ? N-tmp : y;
                update(x,x,1,1,C,y);
                cout<<y<<'\n';
            }else{
                int tmp = queryN(x,x,1,1,C);
                y = (tmp+y)<0? -tmp : y;
                update(x,x,1,1,C,y);
                cout<<y<<'\n';
            }
        }else if(!s.compare("groupchange")){
            cin>>x>>y>>z;
            x++;y++;
            if(z>0){
                int tmp = queryX(x,y,1,1,C);
                z = (tmp+z)>N ? N-tmp : z;
                update(x,y,1,1,C,z);
                cout<<z<<'\n';
            }else{
                int tmp = queryN(x,y,1,1,C);
                z = (tmp+z)<0? -tmp : z;
                update(x,y,1,1,C,z);
                cout<<z<<'\n';
            }
        }else{
            cin>>x;
            x++;
            cout<<queryX(x,x,1,1,C)<<'\n';
        }
    }

    return 0;
}
// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2020 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

struct Node{
    char parent;
    char child[2];
}node[27];

int N;

void prefix(int x){
    cout<<node[x].parent;
    int a=-1,b=-1;
    for(int i=0;i<N;i++){
        if(node[i].parent == node[x].child[0]) a = i;
        if(node[i].parent == node[x].child[1]) b = i;
    }
    if(a != -1) prefix(a);
    if(b != -1) prefix(b);
}

void infix(int x){
    int a=-1,b=-1;
    for(int i=0;i<N;i++){
        if(node[i].parent == node[x].child[0]) a = i;
        if(node[i].parent == node[x].child[1]) b = i;
    }
    if(a != -1) infix(a);
    cout<<node[x].parent;
    if(b != -1) infix(b);
}

void postfix(int x){
    int a=-1,b=-1;
    for(int i=0;i<N;i++){
        if(node[i].parent == node[x].child[0]) a = i;
        if(node[i].parent == node[x].child[1]) b = i;
    }
    if(a != -1) postfix(a);
    if(b != -1) postfix(b);
    cout<<node[x].parent;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        char c[3]; cin>>c[0]>>c[1]>>c[2];
        node[i].parent = c[0];
        node[i].child[0] = c[1];
        node[i].child[1] = c[2];
    }

    prefix(0); cout<<'\n';
    infix(0); cout<<'\n';
    postfix(0); cout<<'\n';

    return 0;
}
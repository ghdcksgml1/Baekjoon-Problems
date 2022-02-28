// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 6032 KB , 시간 : 240 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <math.h>
#define SIZE 100001

using namespace std;

struct Query{
    int idx,start,end;
    Query(int idx,int start,int end){
        this->idx = idx;
        this->start = start;
        this->end = end;
    }
};

vector<Query> q;
int sqrt_N;
int arr[SIZE];
int mo_res[SIZE];
int cnt_num[SIZE];
int table[SIZE];
int result;
// mo's 알고리즘
bool compare(Query a, Query b){
    int x = a.start / sqrt_N;
    int y = b.start / sqrt_N;
    if(x==y) return a.end < b.end;
    return x < y;
}

void Plus(int x){
    if(table[cnt_num[arr[x]]]!=0) table[cnt_num[arr[x]]]--;
    cnt_num[arr[x]]++;
    table[cnt_num[arr[x]]]++;
    result = max(result, cnt_num[arr[x]]);
}

void Minus(int x){
    if(table[cnt_num[arr[x]]]!=0) table[cnt_num[arr[x]]]--;
    if(result==cnt_num[arr[x]] && table[cnt_num[arr[x]]] == 0) result--;
    cnt_num[arr[x]]--;
    table[cnt_num[arr[x]]]++;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N; sqrt_N = sqrt(N);
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }

    int M; cin>>M;
    for(int i=0;i<M;i++){
        int a,b; cin>>a>>b;
        q.push_back({i,a,b});
    }

    sort(q.begin(),q.end(),compare);

    result=0;
    int st=q[0].start, en=q[0].end;
    for(int i=st;i<=en;i++){
        if(table[cnt_num[arr[i]]] != 0) table[cnt_num[arr[i]]]--;
        cnt_num[arr[i]]++;
        table[cnt_num[arr[i]]]++;
        result = max(result,cnt_num[arr[i]]);
    }
    mo_res[q[0].idx] = result;

    for(int i=1;i<M;i++){
        while (st > q[i].start){ // |q[i].start|--|--|--|st|
            // plus
            st--;
            Plus(st);
        }
        while (st < q[i].start){ // |st|--|--|--|q[i].start|
            // minus
            Minus(st);
            st++;
        }
        while (en > q[i].end){ // |q[i].end|--|--|--|en|
            // minus
            Minus(en);
            en--;
        }
        while (en < q[i].end){ // |en|--|--|--|q[i].end|
            // plus
            en++;
            Plus(en);
        }
        mo_res[q[i].idx] = result;
    }

    for(int i=0;i<M;i++){
        cout<<mo_res[i]<<'\n';
    }

    return 0;
}
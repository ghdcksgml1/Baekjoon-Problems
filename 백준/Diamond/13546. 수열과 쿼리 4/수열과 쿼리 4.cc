#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string.h> // memset
#include <math.h>
#define SIZE 101010

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

deque<int> mo_idx[SIZE];

// mo's 알고리즘
bool compare(Query a, Query b){
    int x = a.start / sqrt_N;
    int y = b.start / sqrt_N;
    if(x==y) return a.end < b.end;
    return x < y;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(cnt_num,0,sizeof(cnt_num));

    int N; cin>>N; sqrt_N = (int) sqrt(N);
    int K; cin>>K;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }

    int M; cin>>M;
    for(int i=0;i<M;i++){
        int a,b; cin>>a>>b;
        if(a>b) swap(a,b);
        q.push_back({i,a,b});
    }

    sort(q.begin(),q.end(),compare);

    int cnt=0;
    int st=q[0].start, en=q[0].end;
    for(int i=st;i<=en;i++){
        if(!mo_idx[arr[i]].empty()) {
            int tmp = mo_idx[arr[i]].back() - mo_idx[arr[i]].front();
            cnt_num[tmp]--;
            mo_idx[arr[i]].push_back(i);
            tmp = mo_idx[arr[i]].back() - mo_idx[arr[i]].front();
            cnt_num[tmp]++;
            cnt = max(cnt, tmp);
        }else{
            mo_idx[arr[i]].push_back(i);
            cnt_num[0]++;
        }
    }

    mo_res[q[0].idx] = cnt;

    for(int i=1;i<M;i++){
        int tmp;
        while (st > q[i].start){ // |q[i].start|--|--|--|st|
            // Plus
            st--;
            if(!mo_idx[arr[st]].empty()) {
                tmp = mo_idx[arr[st]].back() - mo_idx[arr[st]].front();
                cnt_num[tmp]--;
                mo_idx[arr[st]].push_front(st);
                tmp = mo_idx[arr[st]].back() - mo_idx[arr[st]].front();
                cnt_num[tmp]++;
                cnt = max(cnt, tmp);
            }else{
                mo_idx[arr[st]].push_back(st);
                cnt_num[0]++;
            }
        }

        while (en < q[i].end){ // |en|--|--|--|q[i].end|
            // Plus
            en++;
            if(!mo_idx[arr[en]].empty()) {
                tmp = mo_idx[arr[en]].back() - mo_idx[arr[en]].front();
                cnt_num[tmp]--;
                mo_idx[arr[en]].push_back(en);
                tmp = mo_idx[arr[en]].back() - mo_idx[arr[en]].front();
                cnt_num[tmp]++;
                cnt = max(cnt, tmp);
            }else{
                mo_idx[arr[en]].push_back(en);
                cnt_num[0]++;
            }
        }

        while (st < q[i].start){ // |st|--|--|--|q[i].start|
            // Minus
            tmp = abs(mo_idx[arr[st]].back() - mo_idx[arr[st]].front());
            mo_idx[arr[st]].pop_front();
            cnt_num[tmp]--;
            if(!mo_idx[arr[st]].empty()) {
                tmp = abs(mo_idx[arr[st]].back() - mo_idx[arr[st]].front());
                cnt_num[tmp]++;
            }

            st++;
        }
        while (en > q[i].end){ // |q[i].end|--|--|--|en|
            // Minus
            tmp = abs(mo_idx[arr[en]].back() - mo_idx[arr[en]].front());
            mo_idx[arr[en]].pop_back();
            cnt_num[tmp]--;
            if(!mo_idx[arr[en]].empty()) {
                tmp = abs(mo_idx[arr[en]].back() - mo_idx[arr[en]].front());
                cnt_num[tmp]++;
            }

            en--;
        }

        for(int i=cnt;i>=0;i--){
            if(cnt_num[i] > 0) {
                cnt = i;
                break;
            }
        }

        mo_res[q[i].idx] = cnt;
    }

    for(int i=0;i<M;i++){
        cout<<mo_res[i]<<'\n';
    }

    return 0;
}
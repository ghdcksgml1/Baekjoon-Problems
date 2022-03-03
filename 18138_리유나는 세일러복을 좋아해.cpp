// 언어 : C++ , (성공/실패) : 1/19 , 메모리 : 2188 KB , 시간 : 0 ms
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int N,M;

int shirt[MAX];
int kara[MAX];

// 매칭에 성공한 경우 True, 실패한 경우 False
bool dfs(int x) {
    // 연결된 모든 노드에 대해서 들어갈 수 있는 시도
    for (auto t: a[x]) {
        // 이미 처리한 노드는 더 이상 볼 필요가 없음
        if (c[t]) continue;
        c[t] = true;
        // 비어있거나 점유 노드에 더 들어갈 공간이 있는 경우
        if (d[t] == -1 || dfs(d[t])) {
            d[t] = x;
            return true;
        }
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>shirt[i];
    }

    for(int i=0;i<M;i++){
        cin>>kara[i];
    }


    for(int i=0;i<N;i++){ // 3/2 = 1
        for(int j=0;j<M;j++){
            if(((double)shirt[i]*(0.5)<=(double)kara[j] && (double)kara[j]<=(double)shirt[i]*(0.75))||(shirt[i]<=kara[j] && (double)kara[j]<=(double)shirt[i]*(1.25))){
                a[i].push_back(j);
            }
        }
    }

    fill(d,d+MAX,-1);

    int count = 0;
    for (int i = 0; i < N; i++) {
        fill(c, c + MAX, false);
        if (dfs(i)) count++;
    }
    cout<<count<<'\n';
    return 0;
}
// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2164 KB , 시간 : 0 ms
#include <iostream>
#include <vector>
#define MAX 201

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int N,M;

// 매칭에 성공한 경우 True, 실패한 경우 False
bool dfs(int x) {
    // 연결된 모든 노드에 대해서 들어갈 수 있는 시도
    for (int i = 0; i < a[x].size(); i++) {
        int t = a[x][i];
        // 이미 처리한 노드는 더 이상 볼 필요가 없음
        if (c[t]) continue;
        c[t] = true;
        // 비어있거나 점유 노드에 더 들어갈 공간이 있는 경우
        if (d[t] == 0 || dfs(d[t])) {
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
    for(int i=1;i<=N;i++){
        int tmp; cin>>tmp;
        while(tmp--){
            int tmp2; cin>>tmp2;
            a[i].push_back(tmp2);
        }
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        fill(c, c + MAX, false);
        if (dfs(i)) count++;
    }
    printf("%d\n", count);
    return 0;
}
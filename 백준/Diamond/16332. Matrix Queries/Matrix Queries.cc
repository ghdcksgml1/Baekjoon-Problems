// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;
typedef long long ll;

int tree_row[(1<<21) + 50], tree_col[(1<<21) + 50]; // seg array 생성
int rowall[21], colall[21];

void query(int *seg, int *all, int depth, int x){
    int p = (1<<depth) + x, sz = 1;
    seg[p] ^= 1; p >>= 1; sz <<= 1; depth--;

    while(p > 0){
        if(seg[p] % sz == 0){
            --all[depth];
        }
        seg[p] = seg[p*2] + seg[p*2+1];
        if(seg[p] % sz == 0){
            ++all[depth];
        }
        p >>= 1; sz <<= 1; depth--;
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, Q; cin>>N>>Q;
    for(int i=0;i<=N;i++){
        rowall[i] = 1 << i;
        colall[i] = 1 << i;

    }

    for(int i=0;i<Q;i++){
        int T, X;
        cin>>T>>X;

        X--;

        if(T == 0){
            query(tree_row,rowall,N,X);
        }else{
            query(tree_col,colall,N,X);
        }

        ll leaves = (1LL << N) * (1LL << N);

        for(int j=0;j<N;j++){
            leaves -= (ll)rowall[j] * colall[j] * 3;
        }

        cout<<4 * (leaves - 1) / 3 + 1<<"\n";
    }

    return 0;
}
// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 17644 KB , 시간 : 100 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 1000000

using namespace std;
typedef long long ll;

ll sum[MAX+1];
ll prefix[MAX+1];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(sum,0,sizeof(sum));
    for(int i=1;i<=MAX;i++){
        for(int j=1;i*j<=MAX;j++){
            sum[i*j] += i;
        }
    }

    ll an = 0;
    for(int i=1;i<=MAX;i++){
        an += sum[i];
        prefix[i] = an;
    }

    int N; cin>>N;
    while(N--){
        int tmp; cin>>tmp;
        cout<<prefix[tmp]<<'\n';
    }

    return 0;
}
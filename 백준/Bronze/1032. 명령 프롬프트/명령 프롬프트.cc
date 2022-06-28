// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    string res; cin>>res;
    for(int i=0;i<N-1;i++){
        string tmp; cin>>tmp;
        for(int j=0;j<res.size();j++){
            if(res[j] != tmp[j]) res[j] = '?';
        }
    }

    cout<<res<<'\n';

    return 0;
}
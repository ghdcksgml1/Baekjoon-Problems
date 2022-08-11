// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <map>

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

map<string, string> m;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    string a,b,c;
    for(int i=0;i<N;i++){
        cin>>a>>b>>c;
        m[a] = c;
    }

    int T; cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;i<N;i++){
            string tmp; cin>>tmp;
            cout<<m[tmp]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
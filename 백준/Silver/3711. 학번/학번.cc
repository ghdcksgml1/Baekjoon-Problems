// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

int dd[1000000];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin>>T;

    while(T--){
        int G; cin>>G;
        vector<int> v;
        for(int i=0; i<G;i++){
            int tmp; cin>>tmp;
            v.push_back(tmp);
        }

        bool trigger;
        for(int i=1; i<1000000; i++){
            trigger = false;
            for(int j=0; j<=i; j++){
                dd[j] = 0;
            }
            for(auto cur : v){
                dd[cur%i]++;
                if(dd[cur%i] > 1) {
                    trigger = true;
                    break;
                }
            }
            if(!trigger){
                cout<<i<<"\n";
                break;
            }
        }
    }

    return 0;
}
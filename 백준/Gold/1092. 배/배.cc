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

vector<int> v;
vector<int> boxes;

bool cmp(int a,int b){
    return a > b;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=0; i<N; i++){
        int tmp; cin>>tmp;
        v.push_back(tmp);
    }

    sort(ALL(v));

    vector<int> v_cnt(N, 0);

    int M; cin>>M;
    for(int i=0; i<M; i++){
        int tmp; cin>>tmp;
        if(tmp > v[v.size() - 1]){
            cout << -1 << "\n";
            return 0;
        }
        for(int j=0; j<v.size(); j++){
            if(v[j] >= tmp){
                v_cnt[j]++;
                break;
            }
        }
    }

    int cnt = 0;
    while(1){
        cnt++;
        int sv = 0;
        for(int i=v.size()-1; i>=0; i--){
            if(v_cnt[i] > 0){
                v_cnt[i]--;
                if(v_cnt[i] - sv < 0){
                    sv -= v_cnt[i];
                    v_cnt[i] = 0;
                }else{
                    v_cnt[i] -= sv;
                    sv = 0;
                }
            }else{
                sv++;
            }
        }

        bool tri = false;
        for(auto cur : v_cnt){
            if(cur > 0) tri = true;
        }

        if(!tri) break;
    }

    cout<<cnt<<"\n";

    return 0;
}
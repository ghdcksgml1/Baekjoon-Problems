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

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,K; cin>>N>>K;
    for(int i=0; i<N; i++){
        int tmp; cin>>tmp;
        if(tmp%2 == 0)
            v.push_back(1);
        else
            v.push_back(0);
    }

    int f_p = 0, s_p = 0; // first_point, second_point
    int mx = 0, cnt = v[0], o_cnt = v[0]?0:1; // max, count
    while(s_p < v.size()){

        if(s_p == f_p) {
            cnt += v[++s_p];
            if(v[s_p] == 0) o_cnt++;
        }
        else if(o_cnt > K) {
            if(v[f_p] == 0) o_cnt--;
            cnt -= v[f_p++];
        }
        else{
            cnt += v[++s_p];
            if(v[s_p] == 0) o_cnt++;
        }
//        cout<<f_p<<" "<<s_p<<"\n";
//        cout<<o_cnt<<"\n\n";
        mx = max(mx, cnt);
    }

    cout<<mx<<"\n";

    return 0;
}
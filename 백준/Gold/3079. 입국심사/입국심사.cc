// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;
typedef long long ll;

vector<ll> v;
ll N,M;
ll result;

bool fun(ll x){
    ll cnt = 0;
    for(ll cur : v){
        cnt += (x/cur);
        if(cnt >= M) {
            result = min(result, x);
            return true;
        }
    }

    return false;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    for(ll i=0;i<N;i++) {
        ll tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    ll mid; result = M*v[v.size()-1];
    ll st=0 , en=M*v[v.size()-1];
    while(st <= en){
        mid = (st + en) / 2;
        if(fun(mid)){
            en = mid-1;
        }else{
            st = mid+1;
        }
    }

    cout<<result<<'\n';

    return 0;
}
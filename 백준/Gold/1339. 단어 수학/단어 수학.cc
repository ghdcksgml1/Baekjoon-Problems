// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <math.h>

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

vector<pll> cnt(26,{0,0});
int num[26];

bool compare(pll a,pll b){
    if(a.yy == b.yy) return a.xx<b.yy;
    return a.yy>b.yy;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    vector<string> v;

    for(int i=0;i<26;i++){
        cnt[i].xx = i;
    }
    for(int i=0;i<N;i++){
        string s; cin>>s;
        v.push_back(s);
        int idx = 0;
        for(int j=s.size()-1;j>=0;j--){
            cnt[s[j]-'A'].yy += pow(10,idx++);
        }
    }

    sort(ALL(cnt), compare);

    int n = 9;
    for(auto cur : cnt){
        if(cur.yy == 0) break;
        num[cur.xx] = n--;
    }

    ll sum = 0;
    for(auto s : v){
        int idx = 0;
        for(int i = s.size()-1;i>=0;i--){
            sum += num[s[i]-'A'] * pow(10,idx++);
        }
    }

    cout<<sum<<'\n';


    return 0;
}
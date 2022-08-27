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

vector<int> v[4];
vector<pii> res;
bool check[6];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;

    for(int i=0; i<6; i++){
        int a,b; cin>>a>>b;
        v[a-1].push_back(b);
        res.push_back({a-1,b});
    }

    int sum = 1;

    vector<int> chk;
    for(int i=0;i<4;i++){
        if(v[i].size() == 1) chk.push_back(i);
    }

    for(int i : chk){
        sum *= v[i][0];
    }

    vector<int> result;
    for(int i=0; i<res.size(); i++){
        for(int c : chk){
            if(c == res[i].first){
                check[i] = true;
                if(i+1>res.size() - 1)
                    check[0] =true;
                else
                    check[i+1] = true;
                if(i-1<0)
                    check[res.size() - 1] = true;
                else
                    check[i-1] = true;
                break;
            }
        }
    }

    int mul = 1;
    for(int i=0;i<res.size(); i++){
        if(!check[i])
            mul *= res[i].second;
    }

    cout<<(sum-mul)*N<<"\n";

    return 0;
}
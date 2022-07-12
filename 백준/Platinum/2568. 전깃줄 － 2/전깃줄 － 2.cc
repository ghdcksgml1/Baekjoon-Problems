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

pii arr[100010];
pii L[100010];
int P[100010];

vector<int> result;
vector<int> lt;

bool compare(pii a,pii b){
    if(a.yy == b.yy) return a.xx < b.xx;
    return a.yy < b.yy;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;

    int len = 0;
    int idx;
    for(int i=0;i<N;i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }

    sort(arr,arr+N,compare);

    for(int i=0;i<N;i++){
        idx = lower_bound(L,L+len,arr[i]) - L;
        L[idx] = arr[i];
        P[i] = idx;
        if(idx == len) len++;
    }

    cout<<N-len<<'\n';


    len--;
    for(int i=N-1;i>=0;i--){
        if(len < 0) break;
        if(P[i] == len){
            result.push_back(arr[i].xx);
            len--;
        }
    }

    idx = 0;
    for(int i=N-1;i>=0;i--){
        if(idx < result.size() && result[idx] == arr[i].xx) idx++;
        else lt.push_back(arr[i].xx);
    }

    sort(ALL(lt));

    for(int cur: lt){
        cout<<cur<<'\n';
    }

    return 0;
}
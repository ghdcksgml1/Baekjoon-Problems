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

vector<string> v;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin>>N>>M;
    for(int i=0; i<N; i++){
        string tmp; cin>>tmp;
        v.push_back(tmp);
    }

    string a[8]={
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB"
    };
    string b[8]={
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW"
    };;

    int result = 1e9;

    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){
            int mn[2] = {0,0};
            for(int x=0; x<8; x++){
                for(int y=0; y<8; y++){
                    int cur_x = i+x;
                    int cur_y = j+y;
                    if(a[x][y] != v[cur_x][cur_y]) mn[0]++;
                    if(b[x][y] != v[cur_x][cur_y]) mn[1]++;
                }
            }
            mn[0] = min(mn[0], mn[1]);
            result = min(result, mn[0]);
        }
    }

    cout<<result<<"\n";

    return 0;
}
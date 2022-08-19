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

int arr[100001][3];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=0;i<N;i++){
        int a,b,c; cin>>a>>b>>c;
        arr[i][0] = a;
        arr[i][1] = b;
        arr[i][2] = c;
    }
    int prev[3];
    int cur[3];

    prev[0] = arr[0][0];
    prev[1] = arr[0][1];
    prev[2] = arr[0][2];

    cur[0] = -1;
    cur[1] = -1;
    cur[2] = -1;

    for(int i=1;i<N;i++){
        for(int j=0; j<3; j++){
            if(j-1 >= 0){
                cur[j-1] = max(cur[j-1], prev[j] + arr[i][j-1]);
            }
            cur[j] = max(cur[j], prev[j] + arr[i][j]);
            if(j+1 <= 2){
                cur[j+1] = max(cur[j+1], prev[j] + arr[i][j+1]);
            }
        }
        prev[0] = cur[0];
        prev[1] = cur[1];
        prev[2] = cur[2];
        cur[0] = -1;
        cur[1] = -1;
        cur[2] = -1;
    }

    cout<<max(prev[0], max(prev[1], prev[2]))<<' ';

    prev[0] = arr[0][0];
    prev[1] = arr[0][1];
    prev[2] = arr[0][2];

    cur[0] = 10000000;
    cur[1] = 10000000;
    cur[2] = 10000000;

    for(int i=1;i<N;i++){
        for(int j=0; j<3; j++){
            if(j-1 >= 0){
                cur[j-1] = min(cur[j-1], prev[j] + arr[i][j-1]);
            }
            cur[j] = min(cur[j], prev[j] + arr[i][j]);
            if(j+1 <= 2){
                cur[j+1] = min(cur[j+1], prev[j] + arr[i][j+1]);
            }
        }
        prev[0] = cur[0];
        prev[1] = cur[1];
        prev[2] = cur[2];
        cur[0] = 10000000;
        cur[1] = 10000000;
        cur[2] = 10000000;
    }

    cout<<min(prev[0], min(prev[1], prev[2]))<<' ';

    return 0;
}
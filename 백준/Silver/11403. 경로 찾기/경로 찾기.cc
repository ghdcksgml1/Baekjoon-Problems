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

int graph[101][101];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0) graph[i][j] = 10000;
        }
    }

    for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                int tmp = graph[i][k] + graph[k][j];
                if (graph[i][j] > tmp) {
                    graph[i][j] = 1;
                }
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (graph[i][j] == 10000) {
                cout << 0 << " ";
            } else {
                cout << graph[i][j] << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}
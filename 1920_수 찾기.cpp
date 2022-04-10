// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2916 KB , 시간 : 52ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

vector<int> v;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=0;i<N;i++){
        int tmp;cin>>tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int M; cin>>M;
    while(M--){
        int tmp; cin>>tmp;
        cout<<binary_search(v.begin(), v.end(),tmp)<<'\n';
    }

    return 0;
}
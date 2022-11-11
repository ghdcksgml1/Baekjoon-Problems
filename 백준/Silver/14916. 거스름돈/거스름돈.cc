#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

int main(void) {
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;cin>>n;
    int cnt_2=0;
    while(1) {
        if(n%5==0) {
            cout<<n/5+cnt_2;
            break;
        }
        else if(n>0){
            n = n - 2;
            cnt_2++;
        }
        else {
            cout<<-1;
            break;
        }
    }
    return 0;
}
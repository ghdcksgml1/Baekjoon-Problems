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

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll X,Y; cin>>X>>Y;



    ll Z = ll((Y) * 100 / (X));

    ll left = 0;
    ll right = 1000000001;

    while(left < right){
        ll mid = (left + right) / 2;
        ll result = (Y + mid) * 100 / (X + mid);
        if(result >= Z+1){
            right = mid;
        }else
            left = mid+1;
    }

    if(left == 1000000001) {
        cout<<-1<<'\n';
    }else
        cout<<left<<'\n';


    return 0;
}
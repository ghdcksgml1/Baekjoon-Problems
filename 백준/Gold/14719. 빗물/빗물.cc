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

vector<int> v;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int H,W; cin>>H>>W;
    int output = 0;

    for(int i=0;i<W;i++){
        int tmp; cin>>tmp;
        v.push_back(tmp);
    }

    int left = 0, right = v.size() - 1;
    int left_max_height = v[left];
    int right_max_height = v[right];

    while(left<right){
        if(v[left] < v[right]){
            left++;
            left_max_height = max(left_max_height, v[left]);
            output += left_max_height - v[left];
        }else{
            right--;
            right_max_height = max(right_max_height, v[right]);
            output += right_max_height - v[right];
        }
    }

    cout<<output<<'\n';

    return 0;
}
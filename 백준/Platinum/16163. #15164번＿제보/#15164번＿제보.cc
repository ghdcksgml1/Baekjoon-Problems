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

char* modifiedChars;
vector<int> palindromicRadii;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string inputString; cin>>inputString;

    for(int i=0; i<2 * inputString.length() + 3 ; i++)
        palindromicRadii.push_back(0);

    modifiedChars = new char[palindromicRadii.size()];
    modifiedChars[0] = '@';
    modifiedChars[palindromicRadii.size() - 1] = '$';

    int t = 1;

    for(char c : inputString){
        modifiedChars[t++] = '#';
        modifiedChars[t++] = c;
    }
    modifiedChars[t] = '#';

    int lp = 0;
    int start = 0;
    int rightmost = 0;
    int center = 0;
    ll cnt = 0;

    for(int i=1; i<palindromicRadii.size()-1; i++){
        if (i < rightmost) {
            palindromicRadii[i] = min(rightmost - i, palindromicRadii[2 * center - i]);
        }

        while(modifiedChars[i + palindromicRadii[i] + 1] == modifiedChars[i - palindromicRadii[i] - 1]) {
            palindromicRadii[i]++;
        }

        if(i+palindromicRadii[i] > rightmost){
            center = i;
            rightmost = i + palindromicRadii[i];
        }

        if(palindromicRadii[i] > lp){
            start = (i - palindromicRadii[i] - 1) / 2;
            lp = palindromicRadii[i];
        }
    }

    for(int cur : palindromicRadii){
        cnt += cur/2;
    }

    cout<<cnt+inputString.size()<<"\n";

    return 0;
}
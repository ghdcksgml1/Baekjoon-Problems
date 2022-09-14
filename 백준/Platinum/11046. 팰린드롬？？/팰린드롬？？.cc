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

vector<int> inputString;
int* modifiedChars;
int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    while(N--){
        int c; cin>>c;
        inputString.push_back(c);
    }

    vector<int> palindromicRadii(2 * inputString.size() + 3, 0);

    modifiedChars = new int[palindromicRadii.size()];
//    modifiedChars[0] = '@';
//    modifiedChars[palindromicRadii.size() - 1] = '$';

    int t = 1;

    for(int c : inputString){
        modifiedChars[t++] = 0;
        modifiedChars[t++] = c;
    }
    modifiedChars[t] = 0;

    int lp = 0;
    int rightmost = 0;
    int center = 0;

    for(int i=1; i<palindromicRadii.size()-1; i++){
        if (i < rightmost) {
            palindromicRadii[i] = min(rightmost - i, palindromicRadii[2 * center - i]);
        }

        while(modifiedChars[i + palindromicRadii[i] + 1] == modifiedChars[i - palindromicRadii[i] - 1])
            palindromicRadii[i]++;

        if(i+palindromicRadii[i] > rightmost){
            center = i;
            rightmost = i + palindromicRadii[i];
        }

        if(palindromicRadii[i] > lp){
            lp = palindromicRadii[i];
        }
    }

//    for(auto cur : palindromicRadii){
//        cout<<cur<<" ";
//    }
//    cout<<"\n";

    int M; cin>>M;
    while(M--){
        int a,b; cin>>a>>b;
        if(a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        int tmp = a + b;
//        cout<<"tmp: "<<palindromicRadii[tmp]<<"\n";
        if(palindromicRadii[tmp] >= b-a)
            cout<<1<<"\n";
        else
            cout<<0<<"\n";
    }

    return 0;
}
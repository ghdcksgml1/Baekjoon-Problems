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


    int T; cin>>T;
    cin.ignore();
    while(T--){
        vector<string> v;
        string s; string tmp="";
        getline(cin,s);
        for(int i=0;i<s.size();i++){
            if(s[i] != ' '){
                tmp += s[i];
            }else{
                v.push_back(tmp);
                tmp="";
            }
        }
        v.push_back(tmp);

        for(string cur : v){
            for(int i=cur.size()-1;i>=0;i--){
                cout<<cur[i];
            }
            cout<<' ';
        }
        cout<<'\n';
    }


    return 0;
}
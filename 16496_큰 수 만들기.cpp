// 언어 : C++ , (성공/실패) : 1/3 , 메모리 : 2168 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

vector<string> v;

bool cmp(string a,string b){
    int a_s = a.size(), b_s = b.size();
    if(a_s == b_s) return a<b;
    else{
        string tmp1 = a+b;
        string tmp2 = b+a;
        for(int i=0;i<tmp1.size();i++){
            if(tmp1[i] == tmp2[i]) continue;
            if(tmp1[i] > tmp2[i]) return 0;
            else return 1;
        }
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin>>N;
    int cnt_0 = 0;
    for(int i=0;i<N;i++) {
        string tmp;
        cin>>tmp;
        if(tmp=="0") cnt_0++;
        v.push_back(tmp);
    }
    if(cnt_0==N) {
        cout<<"0"<<'\n';
        return 0;
    }

    sort(v.begin(),v.end(),cmp);
    for(int i=N-1;i>=0;i--){
        cout<<v[i];
    }
    return 0;
}
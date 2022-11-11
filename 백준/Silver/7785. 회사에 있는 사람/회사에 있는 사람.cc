// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <map>

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

map<string,string> m; // <이름, 출퇴근 기록>
map<string,string>::iterator iter;
vector<string> v; // 회사에 남아있는 사람

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;cin>>n;
    for (int i = 0; i < n; ++i) {
        string name,log;cin>>name>>log;
        m[name]=log;
    }
    for(iter = m.begin(); iter != m.end(); iter++){
        if(iter->second!="leave") v.push_back(iter->first);
    }
    sort(v.rbegin(),v.rend()); // 내림차순 정렬
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<'\n';
    }

    return 0;
}
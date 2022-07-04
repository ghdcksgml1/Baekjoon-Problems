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

struct Student{
    string name;
    int a;
    int b;
    int c;
};

vector<Student> v;

bool cmp(Student a,Student b){
    if(a.a == b.a){
        if(a.b == b.b) {
            if(a.c == b.c){
                return a.name < b.name;
            }
            return a.c > b.c;
        }
        return a.b < b.b;
    }
    return a.a > b.a;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    while(N--){
        string s; int x,y,z; cin>>s>>x>>y>>z;
        v.push_back({s,x,y,z});
    }

    sort(ALL(v),cmp);

    for(Student s : v){
        cout<<s.name<<'\n';
    }

    return 0;
}
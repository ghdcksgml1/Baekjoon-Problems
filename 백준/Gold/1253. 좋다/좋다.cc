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

vector<int> v;
map<int, int> m;
map<int, int> mark;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;

    for(int i=0;i<N;i++){
        int tmp; cin>>tmp;
        v.push_back(tmp);
        m[tmp] += 1;
    }

    sort(ALL(v));


    int cnt = 0;
    for(int t=0; t<v.size(); t++){
        int i=0, j=v.size() - 1;
        while(i < j){
            if(i == t){
                i++;
                continue;
            }
            if(j == t){
                j--;
                continue;
            }
            
            if(v[i]+v[j] > v[t]){
                j--;
                continue;
            }else if(v[i]+v[j] == v[t]){
                cnt++;
                break;
            }else if(v[i]+v[j] < v[t]){
                i++;
                continue;
            }
        }
    }

    cout<<cnt<<'\n';

    return 0;
}
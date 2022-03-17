// 언어 : C++ , (성공/실패) : 1/2 , 메모리 : 2056 KB , 시간 : 12 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];

vector<int> tmp;

bool pn[3001];
int isDone_1 = 0, isDone_2 = 0;
vector<int> result;

void era(){
    for(int i=2;i*i<=3000;i++){
        if(pn[i]) continue;
        for(int j=2;i*j<=3000;j++){
            pn[i*j] = true;
        }
    }
}

bool dfs(int x){
    if(x == isDone_1 || x == isDone_2) return false;
    for(auto t : a[x]){
        if(c[t]) continue;
        if(pn[x+t]) continue;
        c[t] = true;
        if(d[t]==-1 || dfs(d[t])){
            d[t] = x;
            return true;
        }
    }
    return false;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    era();
    int N; cin>>N;
    for(int i=0;i<N;i++) {
        int t;cin>>t;
        tmp.push_back(t);
    }

    int size = tmp.size();
    vector<pair<int,int>> v;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(tmp[i]+tmp[j] & 1){
                if(i==0) {
                    v.push_back({tmp[j],j});
                }
                else{
                    a[tmp[i]].push_back(tmp[j]);
                }
            }
        }
    }

    isDone_1 = tmp[0];
    for(int i=0;i<v.size();i++){
        fill(d,d+MAX,-1);
        isDone_2 = v[i].first;
        if(pn[isDone_1+isDone_2]) continue;

        int count = 0;
        d[isDone_1] = isDone_2;
        d[isDone_2] = isDone_1;
        for(int i=1;i<MAX;i++){
            fill(c,c+MAX,false);
            if(dfs(i)) {
                count++;
            }
        }

        if(N-2 == count) result.push_back(isDone_2);

    }
    sort(result.begin(), result.end());
    if(result.size()) {
        for (auto x: result) cout << x << ' ';
    }else{
        cout<<-1<<'\n';
    }

    return 0;
}
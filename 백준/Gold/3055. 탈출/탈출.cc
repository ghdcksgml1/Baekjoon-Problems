// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <queue>
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

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

vector<string> v;
vector<vector<int>> visited;
queue<pair<int,int>> q;
queue<pair<int,int>> qq;

queue<pair<int,int>> cpy_q;
queue<pair<int,int>> cpy_qq;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int R,C; cin>>R>>C;



    for(int i=0; i<R; i++){
        string s; cin>>s;
        vector<int> vv(C, 0);
        visited.push_back(vv);
        v.push_back(s);
        for(int j=0; j<s.size(); j++){
            if(s[j] == '*') {
                qq.push({i,j});
                visited[i][j] = 1;
            }
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(v[i][j] == 'S'){
                q.push({i,j});
                visited[i][j] = 1;
            }
        }
    }

    int cnt = 0;
    while(!q.empty()){
        cpy_q = q;
        cpy_qq = qq;

        while(q.size() > 0) q.pop();
        while(qq.size() > 0) qq.pop();
        while(cpy_qq.size() > 0){
            auto cur = cpy_qq.front(); cpy_qq.pop();
//            cout<<cur.xx<<" "<<cur.yy<<"\n";
            for(int i=0; i<4; i++){
                int curX = cur.xx + dx[i];
                int curY = cur.yy + dy[i];

                if(curX < 0 || curX >= R || curY < 0 || curY >= C) continue;
                if(v[curX][curY] == 'X') continue;
                if(v[curX][curY] == 'D') continue;
                if(visited[curX][curY] == -1) continue;

                visited[curX][curY] = -1;
                qq.push({curX, curY});
            }
        }

        while(cpy_q.size() > 0) {
            auto cur = cpy_q.front();
            cpy_q.pop();
            if (v[cur.xx][cur.yy] == 'D') {
                cout << cnt << "\n";
                return 0;
            }

            for (int i = 0; i < 4; i++) {
                int curX = cur.xx + dx[i];
                int curY = cur.yy + dy[i];

                if (curX < 0 || curX >= R || curY < 0 || curY >= C) continue;
                if (v[curX][curY] == 'X') continue;
                if (visited[curX][curY] != 0) continue;

                visited[curX][curY] = visited[cur.xx][cur.yy] + 1;
                q.push({curX, curY});
            }
        }


        cnt++;
    }
    cout<<"KAKTUS";

    return 0;
}
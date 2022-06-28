// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string.h> // memset

using namespace std;

struct Node{
    int x;
    int y;
    int f;
};

int w,h;
int graph[1001][1001];
int visit[1001][1001];
deque<Node> q;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin>>T;
    while(T--){
        memset(graph,0,sizeof(graph));
        memset(visit,0,sizeof(visit));

        q.clear();

        cin>>w>>h;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                char c; cin>>c;
                if(c == '.'){
                    graph[i][j] = 1;
                    visit[i][j] = 0;
                }else if(c == '#'){
                    graph[i][j] = 2;
                    visit[i][j] = -1;
                }else if(c == '@'){
                    q.push_front({i,j,3});
                    graph[i][j] = 3;
                    visit[i][j] = 0;
                }else if(c == '*'){
                    graph[i][j] = 4;
                    visit[i][j] = -1;
                    q.push_back({i,j,4});
                }
            }
        }

        bool trigger = false;
        while(!q.empty()){
            auto cur = q.front(); q.pop_front();
            if(cur.f == 3){ // 상근이의 위치일 경우
                for(int i=0;i<4;i++){
                    int nx = cur.x + dx[i];
                    int ny = cur.y + dy[i];
                    if(nx<0 || nx>=h || ny<0 || ny>=w){
                        if(visit[cur.x][cur.y] == -1) break;
                        cout<<visit[cur.x][cur.y] + 1<<'\n';
                        trigger = true;
                        break;
                    }
                    if(visit[nx][ny] != 0) continue;
                    q.push_back({nx,ny,cur.f});
                    visit[nx][ny] = visit[cur.x][cur.y] + 1;
                }
            }else if(cur.f == 4){ // 불의 이동경로
                for(int i=0;i<4;i++){
                    int nx = cur.x + dx[i];
                    int ny = cur.y + dy[i];
                    if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
                    if(visit[nx][ny] == -1) continue;
                    q.push_back({nx,ny,cur.f});
                    visit[nx][ny] = -1;
                }
            }

            if(trigger) break;
        }
        if(!trigger) cout<<"IMPOSSIBLE"<<'\n';
    }

    return 0;
}
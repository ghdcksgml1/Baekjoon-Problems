// 언어 : C++ , (성공/실패) : 1/8 , 메모리 : 23484 KB , 시간 : 484ms
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int N,M,K;

int graph[1002][1002]; // 그래프
bool visit[1002][1002][12]; // 방문한곳 체크
int dist[1002][1002]; // 이동거리

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M>>K;
    for(int i=1;i<=N;i++){
        string tmp;
        cin>>tmp;
        for(int j=0;j<M;j++){
            graph[i][j+1] = tmp[j]-'0';
        }
    }

    queue<pair<int,pair<int,int>>> q; // {벽 부순 수,{x좌표, y좌표}}
    q.push({0,{1,1}});
    dist[1][1] = 1;
    visit[1][1][0] = true;

    while(!q.empty()){
        int curr_w = q.front().first; // 벽 사용 개수
        int curr_x = q.front().second.first; // x좌표
        int curr_y = q.front().second.second; // y 좌표
        q.pop();
        if(curr_x==N && curr_y==M){ // (N,M)에 도착하면 출력
            cout<<dist[N][M]<<'\n';
            return 0;
        }

        for(int cur=0;cur<4;cur++){
            int nx = curr_x + dx[cur];
            int ny = curr_y + dy[cur];
            if(nx<=0 || ny<=0 || nx>N || ny>M) continue;
            if(graph[nx][ny]==1){ // 벽일때
                // 벽을 다 쓰거나, 방문한 곳일때
                if(visit[nx][ny][curr_w+1] || curr_w == K) continue; //방문한 곳이 아니거나, 벽을 다 썼으면 continue
                visit[nx][ny][curr_w+1] = true; // 방문 표시
                q.push({curr_w+1,{nx,ny}});
            }else{ // 벽이 아닐때
                if(visit[nx][ny][curr_w]) continue; // 방문한 곳이면
                visit[nx][ny][curr_w] = true; // 방문 표시
                q.push({curr_w,{nx,ny}});
            }
            dist[nx][ny] = dist[curr_x][curr_y] + 1; // 거리 1 증가
        }
    }
    cout<<"-1"<<'\n';

    return 0;
}
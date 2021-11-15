#include <iostream>
#include <deque>

using namespace std;

int N,M,K;
int arr[21][21]; // 점수판
int visit[21][21]; // DFS 방문체크
deque<int> up_down = {2,1,5,6};
deque<int> right_left = {4,1,3,6};
int dx[4] = {0,1,0,-1}; // 동 남 서 북
int dy[4] = {1,0,-1,0};
int direct = 0; // 동쪽
int x=1; // x 좌표
int y=1; // y 좌표
int score = 0; // 총 점수
int dfs_length = 0; // dfs의 깊이 측정

// DFS
void dfs(int x,int y,int num){
  if(x>N || y>M || x<1 || y<1) return;
  if(arr[x][y] == num && !visit[x][y]){
    visit[x][y] = true;
    dfs_length += 1;
    dfs(x+1,y,num);
    dfs(x-1,y,num);
    dfs(x,y+1,num);
    dfs(x,y-1,num);
  }
}

// 주사위 굴리기
void rotate(int direction){
  // 동쪽
  if(direction == 0){
    right_left.push_front(right_left.back());
    right_left.pop_back();
    up_down[1] = right_left[1];
    up_down[3] = right_left[3];
  }// 남쪽
  else if(direction == 1){
    up_down.push_front(up_down.back());
    up_down.pop_back();
    right_left[1] = up_down[1];
    right_left[3] = up_down[3];
  }// 서쪽
  else if(direction == 2){
    right_left.push_back(right_left.front());
    right_left.pop_front();
    up_down[1] = right_left[1];
    up_down[3] = right_left[3];
  }// 북쪽
  else if(direction == 3){
    up_down.push_back(up_down.front());
    up_down.pop_front();
    right_left[1] = up_down[1];
    right_left[3] = up_down[3];
  }
}

void init(){
  cin.tie(0);
  cout.tie(0);
}
int main(void){
  init();

  cin>>N>>M>>K;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      cin>>arr[i][j];
    }
  }

  while(K--){
    // 이동
    if((x+dx[direct])>N || (y+dy[direct]>M) || (x+dx[direct])<1 || (y+dy[direct]<1)){
      direct = (direct+2)%4; // 범위를 벗어나면 반대방향으로 방향을 바꿔줌
    }
    x += dx[direct];
    y += dy[direct];
    rotate(direct);

    // 점수 계산
    dfs(x,y,arr[x][y]); // 연속해서 이동할 수 있는 칸의 수를 구함.
    score = score+(dfs_length*arr[x][y]); // 점수 합산
    dfs_length=0; // dfs깊이 0으로 초기화
    // 방문기록 해제
    for(int i=1;i<=N;i++){
      for(int j=1;j<=M;j++){
        visit[i][j] = 0;
      }
    }

    // 주사위 방향돌리기
    if(up_down[3] > arr[x][y]){ // A > B
      direct = (direct+1) %4;
    }else if(up_down[3] < arr[x][y]){ // A < B
      direct -= 1;
      if(direct == -1){
        direct = 3;
      }
    }
    // A = B 일 경우는 방향이 그대로이므로 그냥 넘기기
    // 주사위의 밑바닥은 up_down[3], right_left[3] 둘다 사용가능
  }
  cout<<score<<'\n';

  return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001

using namespace std;

int N,M;
int arr[MAX];
int result[MAX];
vector<int> v[MAX];

void topologySort(){
  queue<int> que;
  for(int i=1;i<=N;i++){
    if(arr[i] == 0) que.push(i);
  }
  for(int i=1;i<=N;i++){
    int x = que.front();
    que.pop();
    result[i] = x;
    for(int j=0;j<v[x].size();j++){
      int y = v[x][j];
      if(--arr[y] == 0){
        que.push(y);
      }
    }
  }
  for(int i=1;i<=N;i++){
    cout<<result[i]<<' ';
  }
}

void init(){
  cin.tie(0);
  cout.tie(0);
}

int main(void){
  init();
  cin>>N>>M;
  for(int i=0;i<M;i++){
    int n1,n2;
    cin>>n1>>n2;
    v[n1].push_back(n2);
    arr[n2]++;
  }

  topologySort();
  return 0;
}
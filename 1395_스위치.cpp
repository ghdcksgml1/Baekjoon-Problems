#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> tree;
struct Node{
  int on = 0;
  int off = 0;
  int lazy = 0;
}Node[400001];

// 트리 설정
int buildRec(int node,int start,int end){
  if(start == end){
    return Node[node].off = 1;
  }
  int mid = (start + end) / 2;
  return Node[node].off = buildRec(node*2, start, mid)+buildRec(node*2+1, mid+1, end);
}

// propagation
void propagation(int node,int start,int end){
  int lazy = Node[node].lazy;
  if(lazy){
    if(lazy%2 == 1){ // 다시한번 체크
      Node[node].on ^= Node[node].off;
      Node[node].off ^= Node[node].on;
      Node[node].on ^= Node[node].off;
      if(start != end){
        Node[node*2].lazy += 1;
        Node[node*2+1].lazy += 1;
      }
    }//
    Node[node].lazy = 0;
  }
}

// 합 구하기
int queryRec(int left,int right,int node,int start,int end){
  propagation(node,start,end);
  if(left>end || right < start) return 0;
  if(left <= start && end <= right) return Node[node].on;

  int mid = (start+end) / 2;
  return queryRec(left, right, node*2, start, mid) + queryRec(left, right, node*2+1, mid+1, end);
}

// 반전 시키기
void updateRec(int left,int right,int node,int start,int end){
  propagation(node, start, end);
  if(left>end || right<start) return;
  if(left<=start && end<=right){
    Node[node].lazy += 1;
    if(Node[node].lazy%2 == 1){ // 다시한번 체크
      Node[node].on ^= Node[node].off;
      Node[node].off ^= Node[node].on;
      Node[node].on ^= Node[node].off;
      if(start != end){
        Node[node*2].lazy += 1;
        Node[node*2+1].lazy += 1;
      }
    }//
    
    Node[node].lazy = 0;
    return;
  }

  int mid = (start+end) / 2;
  updateRec(left, right, node*2, start, mid);
  updateRec(left, right, node*2+1, mid+1, end);
  Node[node].on = Node[node*2].on + Node[node*2+1].on;
  Node[node].off = Node[node*2].off + Node[node*2+1].off; 
}

void init(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

int main() {
  init();
  cin>>N>>M;
  buildRec(1,1,N);
  
  for(int i=0;i<M;i++){
    int O,S,T;
    cin>>O>>S>>T;
    if(O == 0){
      updateRec(S,T,1,1,N);
    }else{
      cout<<queryRec(S,T,1,1,N)<<'\n';
    }
    // for(int i=1;i<4*N;i++){
    //   cout<<i<<" = on: "<<Node[i].on<<", off: "<<Node[i].off<<", lazy: "<<Node[i].lazy<<'\n';
    // }
    // cout<<'\n';
  }
} 
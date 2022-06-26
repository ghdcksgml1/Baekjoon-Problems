#include <iostream>
#include <vector>

using namespace std;

int N,M;
int N_arr[100001];
vector<int> tree;

int merge(int left, int right){
  return min(left,right);
}

int buildRec(int node,int nodeLeft,int nodeRight){
  if(nodeLeft == nodeRight){
    return tree[node] = N_arr[nodeLeft];
  }
  int mid = (nodeLeft + nodeRight) / 2;
  int leftVal = buildRec(node*2, nodeLeft, mid);
  int rightVal = buildRec(node*2+1, mid+1, nodeRight);
  return tree[node] = merge(leftVal,rightVal);
}

int queryRec(int left,int right, int node, int nodeLeft,int nodeRight){
  if(left > nodeRight || right < nodeLeft){
    return 1000000000;
  }
  if(left <= nodeLeft && right >= nodeRight){
    return tree[node];
  }
  int mid = (nodeLeft + nodeRight) / 2;
  int leftVal = queryRec(left, right, node*2, nodeLeft, mid);
  int rightVal = queryRec(left, right, node*2+1, mid+1, nodeRight);
  return merge(leftVal, rightVal);
}

void init(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}
int main() {
  init();
  cin>>N>>M;
  for(int i=0;i<N;i++){
    cin>>N_arr[i];
  }

  tree.resize(N*4);
  buildRec(1,0,N-1);

  int a,b;
  for(int i=0;i<M;i++){
    cin>>a>>b;
    cout<<queryRec(a-1, b-1, 1, 0, N-1)<<'\n';

  }
} 
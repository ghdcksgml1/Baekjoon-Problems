#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll N,M;
ll N_arr[100001];
vector<ll> tree;

ll merge(ll left, ll right){
  return left+right;
}

ll buildRec(ll node,ll nodeLeft,ll nodeRight){
  if(nodeLeft == nodeRight){
    return tree[node] = N_arr[nodeLeft];
  }
  ll mid = (nodeLeft + nodeRight) / 2;
  ll leftVal = buildRec(node*2, nodeLeft, mid);
  ll rightVal = buildRec(node*2+1, mid+1, nodeRight);
  return tree[node] = merge(leftVal,rightVal);
}

ll queryRec(ll left,ll right, ll node, ll nodeLeft,ll nodeRight){
  if(left > nodeRight || right < nodeLeft){
    return 0;
  }
  if(left <= nodeLeft && right >= nodeRight){
    return tree[node];
  }
  ll mid = (nodeLeft + nodeRight) / 2;
  ll leftVal = queryRec(left, right, node*2, nodeLeft, mid);
  ll rightVal = queryRec(left, right, node*2+1, mid+1, nodeRight);
  return merge(leftVal, rightVal);
}

ll updateRec(ll newValue,ll index, ll node, ll nodeLeft,ll nodeRight){
  if(index < nodeLeft || index > nodeRight){
    return tree[node];
  }
  if(nodeLeft == nodeRight){
    return tree[node] = newValue;
  }
  ll mid = (nodeLeft + nodeRight) / 2;
  ll leftVal = updateRec(newValue, index, node*2, nodeLeft, mid);
  ll rightVal = updateRec(newValue, index, node*2+1, mid+1, nodeRight);
  return tree[node] = merge(leftVal,rightVal);
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

  int x,y,a,b;
  for(int i=0;i<M;i++){
    cin>>x>>y>>a>>b;
    if(x<=y)
      cout<<queryRec(x-1, y-1, 1, 0, N-1)<<'\n';
    else
      cout<<queryRec(y-1, x-1, 1, 0, N-1)<<'\n';
    updateRec(b, a-1, 1, 0, N-1);
  }
} 
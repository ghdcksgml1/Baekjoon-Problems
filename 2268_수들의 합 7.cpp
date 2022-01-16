#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll N,M;
ll N_arr[1000001];
vector<ll> tree;

ll merge(ll left,ll right){
  return left+right;
}

ll queryRec(ll left,ll right,ll node,ll nodeLeft,ll nodeRight){
  if(left > nodeRight || right < nodeLeft){
    return 0;
  }
  if(left<=nodeLeft && nodeRight<=right){
    return tree[node];
  }
  ll mid = (nodeLeft + nodeRight) / 2;
  ll leftVal = queryRec(left, right, node*2, nodeLeft, mid);
  ll rightVal = queryRec(left, right, node*2+1, mid+1, nodeRight);
  return merge(leftVal, rightVal);
}

void updateRec(ll index,ll diff,ll node,ll nodeLeft,ll nodeRight){
  if(!(nodeLeft<=index && index<=nodeRight))
    return;
  
  tree[node] += diff;

  if(nodeLeft != nodeRight){
    ll mid = (nodeLeft + nodeRight) / 2;
    updateRec(index,diff,node*2,nodeLeft,mid);
    updateRec(index,diff,node*2+1,mid+1,nodeRight);
  }
  
}

void init(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

int main(void){
  init();
  cin>>N>>M;
  ll n1,n2,n3;
  tree.resize(N*4);
  while(M--){
    cin>>n1>>n2>>n3;
    if(n1 == 0){
      if(n2 > n3){
        int temp = n2;
        n2 = n3;
        n3 = temp;
      }
      cout<<queryRec(n2-1, n3-1, 1, 0, N-1)<<'\n';
    }else{
      ll diff = n3 - N_arr[n2];
      N_arr[n2] = n3;
      updateRec(n2-1, diff, 1, 0, N-1);
    }
  }
}
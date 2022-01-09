#include <iostream>
#define MAXN 1000010
#define ll long long

using namespace std;

ll arr[MAXN];
typedef struct Tree{
  ll value, lazy;
}Tree;

Tree tree[3*MAXN];

ll init(int node,int start, int end){
  if(start == end)
    return tree[node].value = arr[start];
  else
    return tree[node].value = init(node*2, start, (start+end)/2)
      + init(node * 2 + 1,(start+end)/2+1, end);
}

void update_range(int node,int start,int end,int i,int j, ll diff){
  // 만약 lazy 값이 있다면, 현재 value에 값을 lazy 값을 통해 갱신시키고,
  // 자식 노드에 lazy 값을 전파하고, 현재 lazy 값은 0으로 초기화 시킨다.
  if(tree[node].lazy != 0){
    tree[node].value += (end-start+1) * tree[node].lazy;
    if(start != end){
      tree[node*2].lazy += tree[node].lazy;
      tree[node*2+1].lazy += tree[node].lazy;
    }
    tree[node].lazy = 0;
  }

  if(start > j || end < i) return;

  // 범위에 딱 맞으면, 현재 값을 더해야하는 값만큼을 더해주고,
  // 자식 노드에게 lazy를 전파
  if(i <= start && j >= end){
    tree[node].value += (end-start+1) * diff;
    if(start != end){
      tree[node*2].lazy += diff;
      tree[node*2+1].lazy += diff;
    }
    return;
  }
  update_range(node*2, start, (start+end)/2, i, j, diff);
  update_range(node*2+1, (start+end)/2+1, end, i, j, diff);

  tree[node].value = tree[node*2].value + tree[node*2+1].value;
}

ll sum(int node, int start, int end, int i, int j){
  if(tree[node].lazy != 0){
    tree[node].value += (end-start+1) * tree[node].lazy;
    if(start != end){
      tree[node*2].lazy += tree[node].lazy;
      tree[node*2+1].lazy += tree[node].lazy;
    }
    tree[node].lazy = 0;
  }

  if(i>end || j<start) return 0;
  if(i <= start && end <= j) return tree[node].value;
  return sum(node*2, start, (start+end)/2, i, j) + sum(node*2+1, (start+end)/2+1, end, i ,j);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N, M, K;
  cin>>N>>M>>K;
  for(int i=1;i<=N;i++){
    cin>>arr[i];
  }
  init(1,1,N);
  for(int i=1;i<=M+K;i++){
    int t1, a,b;
    ll diff;
    cin>>t1;
    if(t1 == 1){
      cin>>a>>b>>diff;
      update_range(1, 1, N, a, b, diff);
    }else{
      cin>>a>>b;
      cout<<sum(1,1,N,a,b)<<'\n';
    }
  }
  return 0;
}
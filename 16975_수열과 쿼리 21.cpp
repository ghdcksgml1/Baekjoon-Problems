// 16975
#include <iostream>
#include <vector>
#define MAX_SIZE 100000

using namespace std;
typedef long ll;

int N,M;
vector<int> A;
struct tree{
  ll value = 0;
  ll lazy = 0;
}tree[MAX_SIZE*4];

ll buildRec(int node,int start,int end){
  if(start == end) return tree[node].value = A[start];
  int mid = (start + end) / 2;
  return buildRec(node*2,start,mid) + buildRec(node*2+1,mid+1,end);
}

ll sumRec(int idx,int node,int start,int end,ll ans){
  if(idx < start || idx > end) return 0;
  ans += tree[node].value;
  if(start == end) return ans;
  int mid = (start+end)/2;
  return sumRec(idx, node*2, start, mid, ans)+sumRec(idx, node*2+1, mid+1, end, ans);
}

void updateRec(int left,int right,int node,int start,int end,ll sum){
  if(end < left || right < start) return;
  if(left <= start && end <= right){
    tree[node].value += sum;
    return;
  }

  int mid = (start+end) / 2;
  updateRec(left,right,node*2,start,mid,sum);
  updateRec(left,right,node*2+1,mid+1,end,sum);
}

void init(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
}
int main(void){
  init();
  cin>>N;
  A.resize(N+1);
  for(int i=1;i<=N;i++){
    cin>>A[i];
  }
  buildRec(1,1,N);
  
  cin>>M;
  for(int kk=0;kk<M;kk++){
    int t,i,j,k,x;
    cin>>t;
    if(t==1){
      cin>>i>>j>>k;
      if(i>j){
        int temp = i;
        i = j;
        j = temp;
      }
      updateRec(i,j,1,1,N,k);
    }else if(t==2){
      cin>>x;
      cout<<sumRec(x,1,1,N,0)<<'\n';
    }
  }
}
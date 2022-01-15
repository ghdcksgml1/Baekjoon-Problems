#include <iostream>

using namespace std;
typedef long long ll;

int N;
ll K;
int N_arr[500001];

ll fac(int x,int y){
  ll result = x;
  for(int i=x-1;i>=x-y+1;i--){
    result = (result * i) % 1000000007;
  }
  return result;
}

void init(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}
int main(void){
  init();
  cin>>N>>K;
  ll sum = 0;
  for(int i=0;i<N;i++){
    cin>>N_arr[i];
    sum += N_arr[i];
  }

  K = K - sum + N;

  cout<<fac(K,N)<<'\n';

}
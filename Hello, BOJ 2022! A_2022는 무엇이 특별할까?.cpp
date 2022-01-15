#include <iostream>
#include <math.h>

using namespace std;
typedef long long ll;
ll N,d;
bool trigger = false;
ll result;
ll Min = 2000000000;
bool check[10];

ll make(ll n){
  ll cpy_N = n;
  ll temp_result = 0;
  for(int i=0;i<10;i++){
    temp_result = temp_result + (cpy_N%d)*pow(10,i);
    cpy_N /= d;
    if(cpy_N == 0) break;
  }
  if(temp_result > pow(10,d)) trigger = true;
  return temp_result;
}

void backtracking(ll x,ll sum){
  if(x == d){
    if(result < sum){
      Min = min(Min, sum);
    }
    return;
  }
  for(int i=0;i<d;i++){
    if(check[i]) continue;
    if(x == d-1 && i==0) continue; 
    check[i] = true;
    backtracking(x+1,sum + i*pow(10,x));
    check[i]=false;
  }
}

ll reverse(ll n){
  ll cpy_n = n;
  ll temp_result = 0;
  for(int i=0;i<d;i++){
    temp_result = temp_result + (cpy_n%10)*pow(d,i);
    cpy_n /= 10;
  }
  return temp_result;
}

void init(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

int main() {
    init();
  cin>>N>>d;

  result = make(N);

  backtracking(0,0);

  if(Min == 2000000000){
    cout<<"-1"<<'\n';
  }else{
    cout<<reverse(Min)<<'\n';
  }
} 
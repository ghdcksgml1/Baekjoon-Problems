#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int n_arr[500000];
stack<pair<int,int>> st; // (숫자, 몇번째인지)
stack<pair<int,int>> temp; // (숫자, 몇번째인지)
vector<pair<int,int>> result; // (수신탑, 몇번째인지)

bool compare(pair<int,int> a,pair<int,int> b){
  return a.second < b.second;
}

void init(){
  cin.tie(0);
  cout.tie(0);
}

int main() {
  init(); // 초기설정

  // 입력받기
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>n_arr[i];
    st.push({n_arr[i],i+1}); // 숫자와 몇번째인지 넣어준다.
  }
  /*****************/

  // st에서 일단 한개를 빼서 그대로 temp 스택에 넣어준다.
  // temp 스택에 있는 값들을 st 스택의 최상단과 비교해준다.
  // st 스택의 최상단보다 temp 스택의 최상단이 작으면,
  // 송신탑에 걸리는 경우이므로 result로 수신탑의 정보와함께 넣어준다.
  for(int i=0;i<N-1;i++){
    temp.push({st.top().first,st.top().second});
    st.pop();
    int num = st.size(); // 송신탑 번호
    int temp_num = temp.size(); // temp 스택의 크기
    for(int j=0;j<temp_num;j++){
      if(temp.top() < st.top()){
        result.push_back({st.top().second,temp.top().second});
        temp.pop();
      }else{
        break;
      }
    }
  }

  result.push_back({0,1}); // 첫번째는 무조건 0이므로 수신탑은 0, 첫번째를 나타내는 1
  while(!temp.empty()){ // 위 for문이 다끝났는데도 남아있는건 수신탑이 없는것이므로
    result.push_back({0,temp.top().second}); // 수신탑을 0으로 다 넣어준다.
    temp.pop();
  }

  // 결과들을 정렬한다. 몇번째인지 저장되어있는 second 기준으로
  sort(result.begin(),result.end(),compare);

  for(int i=0;i<result.size();i++){
    cout<<result[i].first<<' ';
  }
} 

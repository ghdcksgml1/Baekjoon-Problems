// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

int N;

void recursion(int x,string s){
    cout<<s<<"\"재귀함수가 뭔가요?\"\n";
    if(x == N) {
        cout<<s<<"\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
        cout<<s<<"라고 답변하였지."<<"\n";
        return;
    }
    cout<<s<<"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
    cout<<s<<"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
    cout<<s<<"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""<<"\n";
    recursion(x+1,s+"____");
    cout<<s<<"라고 답변하였지."<<"\n";
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    cout<<"어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다."<<"\n";
    recursion(0,"");

    return 0;
}
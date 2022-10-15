// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

queue<string> q[101];

void split_string(queue<string> &q, string s){
    string str = "";
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            q.push(str);
            str = "";
        }else{
            str += s[i];
        }
    }
    q.push(str);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N; cin.ignore();
    for(int i=0; i<N+1; i++){
        string s; getline(cin, s);
        split_string(q[i], s);
    }

    int empty_queue_cnt = 0;
    while(empty_queue_cnt != N){
        empty_queue_cnt = 0;
        string L_front;
        if(q[N].size() > 0) L_front = q[N].front();
        else L_front = "";

        for(int i=0; i<N; i++){
            if(q[i].size() > 0 && q[i].front() == L_front){
                q[i].pop();
                q[N].pop();
                break;
            }else if(q[i].size() > 0 && q[N].empty()) {
                cout<<"Impossible"<<"\n";
                return 0;
            }else{
                empty_queue_cnt++;
            }
        }
    }

    cout<<((q[N].size() == 0) ? "Possible" : "Impossible")<<"\n";

    return 0;
}
//// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
//#include <iostream>
//#include <vector>
//#include <set>
//#include <queue>
//#include <map>
//#include <algorithm>
//#include <string.h> // memset
//
//#define ALL(x) begin(x), end(x)
//#define pll pair<ll,ll>
//#define pii pair<int,int>
//#define xx first
//#define yy second
//#define MAX 1e6
//
//using namespace std;
//typedef long long ll;
//
//
//class LinkedList{
//public:
//    string value;
//    priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> pq;
//    vector<LinkedList*> v;
//
//    LinkedList(string value){
//        this->value = value;
//    }
//};
//
//void recursion(LinkedList* node, int idx){
//    if(node->pq.empty()) return;
//    for(int i=0; i<idx; i++){
//        cout<<"--";
//    }
//    cout<<node->value<<"\n";
//    while(!node->pq.empty()){
//        auto cur = node->pq.top(); node->pq.pop();
//        recursion(node->v[cur.second], idx+1);
//    }
//}
//
//int main(void){
//    // 입출력 속도 최적화
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    int N; cin>>N;
//    LinkedList* head = new LinkedList("start");
//    LinkedList* node;
//    for(int i=0; i<N; i++){
//        node = head;
//        int tmp; cin>>tmp;
//        for(int i=0; i<tmp; i++){
//            string s; cin>>s;
//            node->pq.push({s,i});
//            node->v.push_back(new LinkedList(s));
//            node = node->v[i];
//        }
//    }
//
//    node = head;
//    while(!node->pq.empty()){
//        auto cur = node->pq.top(); node->pq.pop();
//        recursion(node->v[cur.second], 0);
//    }
//
//    return 0;
//}
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

int arr[101][101];

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M; cin>>N>>M;

    for(int i=0; i<N; i++){
        for(int j=0;j<M;j++){
            int tmp; cin>>tmp;
            arr[i][j] += tmp;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0;j<M;j++){
            int tmp; cin>>tmp;
            arr[i][j] += tmp;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0;j<M;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<"\n";
    }

    return 0;
}
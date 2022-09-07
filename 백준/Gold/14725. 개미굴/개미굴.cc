// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <map>
#include <queue>
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

// 트라이 자료구조
class Trie {
public:
    vector<string> value; // 문자열을 멤버변수 value로 가지고있고
    map<string, Trie*> children; // 맵을 통한 children을 가지고 있습니다.

    void insert(vector<string> word){
        Trie *node = this;
        for (int i = 0; i < word.size(); i++) {
            if (node->children.find(word[i]) == node->children.end()) {
                node->children.insert(pair<string, Trie *>(word[i], new Trie()));
            }
            node = node->children[word.at(i)];
        }
        node->value = word;
    }

};

void dfs(Trie *node, int n){
    map<string, Trie*>::iterator iter;
    for(iter = node->children.begin(); iter != node->children.end(); iter++){
        for(int i=0; i<n; i++){
            cout<<"--";
        }
        cout<<iter->first<<"\n";
        dfs(iter->second, n+1);
    }

}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;

    Trie *head = new Trie();
    while(N--){
        int C; cin>>C;
        vector<string> v;
        while(C--){
            string s; cin>>s;
            v.push_back(s);
        }
        head->insert(v);
    }

    dfs(head, 0);

    return 0;
}
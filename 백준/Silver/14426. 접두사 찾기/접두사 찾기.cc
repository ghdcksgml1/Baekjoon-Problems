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
class Trie{
public:
    string value;
    map<char, Trie *> children;

    void insert(string word){
        Trie* node = this;
        for(int i=0; i<word.length(); i++){
            if(node->children.find(word[i]) == node->children.end()){
                node->children[word[i]] = new Trie();
            }
            node = node->children[word[i]];
        }
        node->value = word;
    }

    bool search(string word){
        Trie* node = this;
        for(int i=0; i<word.length(); i++) {
            if (node->children.find(word[i]) == node->children.end())
                return false;
            node = node->children[word[i]];
        }
        return true;
    }
};


int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M; cin>>N>>M;
    Trie* head = new Trie();
    for(int i=0; i<N; i++){
        string s; cin>>s;
        head->insert(s);
    }

    int cnt = 0;
    while(M--){
        string s; cin>>s;
        if(head->search(s)) cnt++;
    }

    cout<<cnt<<"\n";

    return 0;
}
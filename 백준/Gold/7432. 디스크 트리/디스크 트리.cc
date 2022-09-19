// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

class Trie{
public:
    string value = "";
    map<string, Trie*> children;

    void insert(string word){
        Trie* node = this;
        string s = "";
        for(int i=0; i<=word.length(); i++){
            if(word.length()==i || word[i] == '\\'){
                if(node->children.find(s) == node->children.end()){
                    node->children.insert(pair<string, Trie*>(s, new Trie()));
                }
                node = node->children[s];
                s = "";
            }else{
                s += word[i];
            }
        }
        node->value = word;
    }
};

void dfs(Trie *t, int depth){
    map<string, Trie*>::iterator iter;
    for(iter = t->children.begin(); iter != t->children.end(); iter++){
        for(int i=0; i< depth; i++) cout<<" ";
        cout<<iter->first<<"\n";
        dfs(iter->second, depth+1);
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    Trie* trie = new Trie();
    for(int i=0; i<N; i++){
        string s; cin>>s;
        trie->insert(s);
    }

    dfs(trie, 0);

    return 0;
}
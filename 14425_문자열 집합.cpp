// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 1091020 KB , 시간 : 1304ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

const int GO_MAX = 26;

struct Trie{
    Trie* go[GO_MAX];
    bool finish;
    bool child;

    Trie(){
        fill(go,go+GO_MAX,nullptr);
        finish = child = false;
    }
    ~Trie(){
        for(int i=0;i<GO_MAX;i++)
            if(go[i]) delete go[i];
    }

    void insert(const char* key){
        if(*key == '\0'){
            finish = true;
        }else{
            int next = *key - 'a';
            if(!go[next]) go[next] = new Trie;
            child = true;
            go[next]->insert(key+1);
        }
    }

    bool check(const char* key){
        if(*key == '\0'){
            if(finish) return true;
            else return false;
        }else{
            int next = *key-'a';
            if(!go[next]) return false;
            return go[next]->check(key+1);
        }
    }
};

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M;
    int cnt = 0;
    cin>>N>>M;

    Trie* root = new Trie;
    for(int i=0;i<N;i++){
        char c[501];
        cin>>c;
        root->insert(c);
    }

    for(int i=0;i<M;i++){
        char c[501];
        cin>>c;
        if(root->check(c)) cnt += 1;
    }

    cout<<cnt<<'\n';

    return 0;
}
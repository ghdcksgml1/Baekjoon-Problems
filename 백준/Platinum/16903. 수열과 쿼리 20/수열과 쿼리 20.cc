// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h> // memset
#include <cmath>

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
    string value;
    int num = 0;
    Trie* children[2];

    void insert(string word, string original){
        Trie* node = this;
        bool trigger = true;
        for(int i=0; i<word.length(); i++){
            if(node->children[word[i]-'0'] == NULL)
                node->children[word[i]-'0'] = new Trie();
            node = node->children[word[i]-'0'];
            node->num++;
            if(word[i] == '1' && trigger) {
                node->value = original;
                trigger = false;
            }
        }
    }

    void del(string word){
        Trie* node = this;
        bool trigger = true;
        for(int i=0; i<word.length(); i++){
            node = node->children[word[i]-'0'];
            node->num--;
            if(word[i] == '1' && trigger){
                node->value = "";
                trigger = false;
            }
        }
    }

    string fmx(string word){
        Trie* node = this;
        string result = "";
        for(int i=0; i<word.length(); i++){
            int c = (word[i] == '1'?0:1);
            if(node->children[c] != NULL){
                if(node->children[c]->num > 0)
                    node = node->children[c];
                else{
                    c = (c == 1 ? 0 : 1);
                    node = node->children[c];
                }

            }
            else {
                c = (c == 1 ? 0 : 1);
                node = node->children[c];
            }
            result += to_string(c);
        }

        return result;
    }
};

string dtob(int x){
    string result = "";
    for(int i=0; i<31; i++){
        result = to_string(x%2) + result;
        x/=2;
    }
    return result;
}

int xr(string a, string b){
    int result = 0;
    for(int i=30; i>=0; i--){
        int t = a[i] == b[i] ? 0 : 1;
        result +=(t * pow(2,30-i));
    }
    return result;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    Trie* trie = new Trie();
    trie->insert(dtob(0),"0");
    while(N--){
        int a,b; cin>>a>>b;
        if(a == 1){
            string original = "";
            int cpy_b = b;
            while(cpy_b != 0){
                original = to_string(cpy_b%2) + original;
                cpy_b/=2;
            }
            trie->insert(dtob(b), original);
        }else if(a == 2){
            trie->del(dtob(b));
        }else{
            cout<<xr(trie->fmx(dtob(b)),dtob(b))<<"\n";
        }
    }

    return 0;
}
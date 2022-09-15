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
    int num = 0;
    Trie* children[2];

    void insert(string word){
        Trie* node = this;
        bool trigger = true;
        for(int i=0; i<word.length(); i++){
            if(node->children[word[i]-'0'] == NULL)
                node->children[word[i]-'0'] = new Trie();
            node = node->children[word[i]-'0'];
            node->num++;
            if(word[i] == '1' && trigger) {
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

vector<int> v;

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    Trie* trie = new Trie();
    for(int i=0; i<N; i++){
        int a; cin>>a;
        v.push_back(a);
        trie->insert(dtob(a));
    }


    int mx = 0;
    for(auto cur : v){
        mx = max(mx, xr(trie->fmx(dtob(cur)), dtob(cur)));
    }

    cout<<mx<<"\n";

    return 0;
}
// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

int cnt=0;
vector<int> result;

vector<int> makeTable(string pattern){
    int patternSize = pattern.size();
    vector<int> table(patternSize,0);
    int j = 0;
    for(int i=1;i<patternSize;i++){
        while(j>0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    return table;
}

void KMP(string parent,string pattern){
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    for(int i=0;i<parentSize;i++){
        while(j>0 && parent[i] != pattern[j]){
            j = table[j-1];
        }
        if(parent[i] == pattern[j]){
            if(j == patternSize-1){
                cnt++;
                result.push_back(i-patternSize+2);
                j = table[j];
            }else{
                j++;
            }
        }
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string parent;
    string pattern;
    getline(cin,parent);
    getline(cin,pattern);
    KMP(parent,pattern);

    cout<<cnt<<'\n';
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<' ';
    }

    return 0;
}
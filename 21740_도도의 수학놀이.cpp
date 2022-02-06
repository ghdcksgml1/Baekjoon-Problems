// 언어 : C++ , (성공/실패) : 1/12 , 메모리 : 8300 KB , 시간 : 92 ms
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> v;

bool compare(string a,string b){
    if(a.size()==b.size()) return a<b;
    else{
        string tmp1 = a+b;
        string tmp2 = b+a;
        for(int i=0;i<tmp1.size();i++){
            if(tmp1[i] == tmp2[i]) continue;
            if(tmp1[i] > tmp2[i]) return 0;
            else return 1;
        }
        return 1;
    }
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(to_string(tmp));
    }

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]=='6') v[i][j]='9';
            else if(v[i][j]=='9') v[i][j] = '6';
        }
        reverse(v[i].begin(),v[i].end());
    }

    sort(v.begin(),v.end(),compare);

    string result="";

    int idx=0;
    int size=0;

    for(int i=0;i<v.size();i++){
        reverse(v[i].begin(),v[i].end());
        if(v[i].size() >= size){
            idx = i;
            size = v[i].size();
        }
    }

    for(int i=0;i<v.size();i++){
        result+=v[i];
        if(i==idx) result+=v[i];
    }

    for(int i=0;i<result.size();i++){
        if(result[i]=='6') result[i]='9';
        else if(result[i]=='9') result[i] = '6';

    }
    cout<<result<<'\n';

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v1;
vector<int> v2;

int main(void){
    
    for(int i=0; i<4; i++){
        int tmp; cin>>tmp;
        v1.push_back(tmp);
    }
    for(int i=0; i<2; i++){
        int tmp; cin>>tmp;
        v2.push_back(tmp);
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    cout<<v1[3]+v1[2]+v1[1]+v2[1];
    
    return 0;
}
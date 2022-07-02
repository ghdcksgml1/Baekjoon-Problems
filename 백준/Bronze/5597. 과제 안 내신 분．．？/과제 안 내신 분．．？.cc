#include <iostream>

using namespace std;

int main(void){
    
    int a[31] = {0,};
    
    for(int i=0;i<28;i++){
        int tmp; cin>>tmp;
        a[tmp]++;
    }
    
    for(int i=1;i<=30;i++){
        if(a[i] != 1) cout<<i<<'\n';
    }
    
    return 0;
}
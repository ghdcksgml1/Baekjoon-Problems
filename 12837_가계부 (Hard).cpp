// 언어 : C++ , (성공/실패) : 1/1 , 메모리 : 33272 KB , 시간 : 80 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 1000001

using namespace std;
typedef long long ll;

struct Tree{
    ll value = 0;
}tree[MAX*4];

ll N,Q;

ll buildRec(ll node,ll start,ll end){
    if(start == end){
        return tree[node].value = 0;
    }
    ll mid = (start + end) / 2;
    return tree[node].value = buildRec(node*2,start,mid) + buildRec(node*2+1,mid+1,end);
}

ll queryRec(ll left,ll right,ll node,ll start,ll end){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right){
        return tree[node].value;
    }
    ll mid = (start + end) / 2;
    return queryRec(left,right,node*2,start,mid) + queryRec(left,right,node*2+1,mid+1,end);
}

ll updateRec(ll target,ll value,ll node,ll start,ll end){
    if(target>end || target<start) return tree[node].value;
    if(start == end){
        return tree[node].value += value;
    }
    ll mid = (start + end) / 2;
    return tree[node].value = updateRec(target,value,node*2,start,mid) + updateRec(target,value,node*2+1,mid+1,end);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>Q;
    buildRec(1,1,N);

    while(Q--){
        ll a,b,c;
        cin>>a>>b>>c;;
        if(a==1){
            updateRec(b,c,1,1,N);
        }else{
            cout<<queryRec(b,c,1,1,N)<<'\n';
        }
    }

    return 0;
}
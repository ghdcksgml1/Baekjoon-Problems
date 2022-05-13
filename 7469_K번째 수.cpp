// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 23380 KB , 시간 : 156ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 100001

using namespace std;

vector<int> mst[MAX*4];
int arr[MAX];

void buildRec(int node,int start,int end){
    vector<int>&cur = mst[node];
    if(start == end){
        cur.push_back(arr[start]);
        return;
    }
    int mid = (start + end) / 2;
    buildRec(node*2,start,mid);
    buildRec(node*2+1,mid+1,end);

    vector<int>&left = mst[node*2]; vector<int>&right = mst[node*2+1];
    cur.resize(left.size()+right.size());
    merge(left.begin(),left.end(),right.begin(),right.end(),cur.begin());
}

int queryRec(int left,int right,int node,int start,int end,int target){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right){
        return (lower_bound(mst[node].begin(),mst[node].end(),target) - mst[node].begin());
    }
    int mid = (start + end) / 2;
    return queryRec(left,right,node*2,start,mid,target) + queryRec(left,right,node*2+1,mid+1,end,target);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M; cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }

    buildRec(1,1,N);

    while(M--){
        int i,j,k; cin>>i>>j>>k;

        int l= -1e9, r = 1e9;
        int res;


        // 매개변수 탐색
        while(l<=r){
            int mid = (l + r) / 2;
            if(queryRec(i,j,1,1,N,mid) <= k-1){
                res = mid, l = mid + 1;
            }else{
                r = mid-1;
            }
        }
        cout<<res<<'\n';

    }

    return 0;
}
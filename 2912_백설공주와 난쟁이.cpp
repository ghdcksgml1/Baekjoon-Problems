// 언어 : C++ , (성공/실패) : 1/6 , 메모리 : 67680 KB , 시간 : 292ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#include <math.h>
#define SIZE 300010

using namespace std;


vector<int> mst[SIZE*4];
vector<int> tmp;
int N;
int arr[SIZE];


void buildRec(int node,int start,int end){
    vector<int> &cur = mst[node];
    if(start == end){
        cur.push_back(arr[start]);
        return;
    }
    int mid = (start + end) / 2;
    buildRec(node*2,start,mid);
    buildRec(node*2+1,mid+1,end);

    vector<int> &left = mst[node*2], &right = mst[node*2+1];
    cur.resize(left.size() + right.size());
    merge(left.begin(),left.end(),right.begin(),right.end(),cur.begin());
}

int queryRec(int left,int right,int node,int start,int end,int target){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right){
        int temp = upper_bound(mst[node].begin(),mst[node].end(),target)- lower_bound(mst[node].begin(),mst[node].end(),target);
        return temp;
    }
    int mid = (start + end) / 2;
    return queryRec(left,right,node*2,start,mid,target) + queryRec(left,right,node*2+1,mid+1,end,target);
}

void queryRec2(int left,int right,int node,int start,int end){
    if(left>end || right<start) return ;
    if(left<=start && end<=right){
        int size = mst[node].size();
        if(start == end){tmp.push_back(arr[start]); return;}
        if(size%2 == 1){
            tmp.push_back(mst[node][size/2]);
        }else {
            if (mst[node][size / 2] == mst[node][size / 2 - 1]) {
                tmp.push_back(mst[node][size / 2]);
            }
        }
        return ;
    }
    int mid = (start + end) / 2;
    queryRec2(left,right,node*2,start,mid);
    queryRec2(left,right,node*2+1,mid+1,end);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N;int C;cin>>C;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }

    buildRec(1,1,N);

    int M; cin>>M;
    for(int i=0;i<M;i++){
        int a,b; cin>>a>>b;
        if(a>b){
            int temp = a;
            a = b;
            b = temp;
        }
        bool trigger = false;
        tmp = {};
        queryRec2(a,b,1,1,N);
        for(int j=0;j<tmp.size();j++){
            if((b-a+1)/2 < queryRec(a,b,1,1,N,tmp[j])) {
                cout<<"yes "<<tmp[j]<<'\n';
                trigger = true;
                break;
            }
        }
        if(!trigger) cout<<"no"<<'\n';
    }

    return 0;
}
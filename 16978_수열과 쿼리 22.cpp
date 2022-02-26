// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 10936 KB , 시간 : 84 ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset
#define MAX 100001

using namespace std;
typedef long long ll;

struct Tree{
    ll value;
}tree[MAX*4];

class Query{
public:
    ll idx,k,i,j;
    Query(ll idx,ll k,ll i,ll j){
        this->idx = idx;
        this->k = k;
        this->i = i;
        this->j = j;
    }
};

ll arr[MAX];
vector<pair<int,int>> ch;
vector<Query> query;
ll query_res[MAX];

bool compare(Query a,Query b){
    return a.k < b.k;
}

ll buildRec(int node,int start,int end){
    if(start == end){
        return tree[node].value = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node].value = buildRec(node*2,start,mid) + buildRec(node*2+1,mid+1,end);
}

ll queryRec(int left,int right,int node,int start,int end){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right){
        return tree[node].value;
    }
    int mid = (start + end) / 2;
    return queryRec(left,right,node*2,start,mid) + queryRec(left,right,node*2+1,mid+1,end);
}

ll updateRec(int i,ll v,int node,int start,int end){
    if(i>end || i<start) return tree[node].value;
    if(start == end){
        return tree[node].value = v;
    }
    int mid = (start + end) / 2;
    return tree[node].value = updateRec(i,v,node*2,start,mid) + updateRec(i,v,node*2+1,mid+1,end);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin>>N;
    for(int i=1;i<=N;i++){
        ll tmp; cin>>tmp;
        arr[i] = tmp;
    }

    buildRec(1,1,N);

    int M; cin>>M;
    int q_idx = 0;
    for(int ii=0;ii<M;ii++){
        int num; cin>>num;
        if(num==1){
            int i;ll v; cin>>i>>v;
            ch.push_back({i,v});
        }else{
            int k,i,j; cin>>k>>i>>j;
            query.push_back({q_idx,k,i,j});
            q_idx++;
        }
    }

    sort(query.begin(), query.end(),compare);

    int cur_k = 0;
    for(auto q : query){
        if(cur_k != q.k){
            for(int i=cur_k;i<q.k;i++) {
                updateRec(ch[i].first,ch[i].second,1,1,N);
            }
            cur_k = q.k;
        }
        query_res[q.idx] = queryRec(q.i,q.j,1,1,N);
    }

    for(int i=0;i<query.size();i++){
        cout<<query_res[i]<<'\n';
    }

    return 0;
}
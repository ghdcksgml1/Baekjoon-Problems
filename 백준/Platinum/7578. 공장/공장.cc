// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

vector<pii> v;
vector<ll> tree(MAX*4,0);
int arr[1000001];

bool compare(pii a,pii b){
    if(a.xx == b.xx){
        return a.yy<b.yy;
    }
    return a.xx<b.xx;
}

ll query(int left,int right,int node,int start,int end){
    if(left>end || right<start) return 0;
    if(left<=start && end<=right){
        return tree[node];
    }
    int mid = start + end >> 1;
    return query(left,right,node*2,start,mid) +
        query(left,right,node*2+1,mid+1,end);
}

ll update(int target,int node,int start,int end,ll value){
    if(target>end || target<start) return tree[node];
    if(start == end){
        return tree[node] += value;
    }
    int mid = start + end >> 1;
    return tree[node] = update(target,node*2,start,mid,value) +
            update(target,node*2+1,mid+1,end,value);
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T=1;
    while(T--) {
        v.clear();
        tree.clear();
        tree.resize(MAX*4,0);
        memset(arr,0,sizeof(arr));

        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            int tmp;
            cin >> tmp;
            arr[tmp] = i;
        }
        for (int i = 1; i <= N; i++) {
            int tmp;
            cin >> tmp;
            v.push_back({arr[tmp], i});
        }

        sort(ALL(v), compare);

        ll cnt = 0;

        for (int i = N - 1; i >= 0; i--) {
            int b = v[i].yy;
            cnt += query(1, b - 1, 1, 1, N);
            update(b, 1, 1, N, 1);
        }

        cout << cnt << '\n';
    }

    return 0;
}
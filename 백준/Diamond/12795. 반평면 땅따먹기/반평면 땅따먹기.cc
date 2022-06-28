// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> // memset

using namespace std;

typedef long long ll;
const ll inf = 2e18;

// y = ax + b를 저장하는 구조체
struct Line{
    ll a,b;
    ll get(ll x){
        return a * x + b;
    }
};

// 세그먼트 트리의 노드
struct Node{
    int l, r; // left, right
    ll s, e; // start, end
    Line line;
};

// 리차오 트리
struct Li_Chao{
    vector<Node> tree;

    void init(ll s, ll e){
        tree.push_back({-1, -1, s, e, {0, -inf}});
    }

    void update(int node,Line v){
        ll start = tree[node].s, end = tree[node].e;
        ll mid = start + end >> 1;

        Line low = tree[node].line, high = v;
        if(low.get(start) > high.get(start)) // 원래 있던 직선의 start부분이 추가할 직선의 start부분보다 크다면
            swap(low,high); // high에 원래 있던 직선을 설정
        if(low.get(end) <= high.get(end)){ // 현재 낮게있는 직선의 end가 높게있는 직선의 end보다 작거나 같을 경우
            tree[node].line = high; return; // 높게 있는 직선을 현재 라인에 저장하고 나가기
        }

        // 여기까지 왔다는 것은 high가 start부분은 높지만, end부분이 low보다 낮다는 것이다.

        if(low.get(mid) < high.get(mid)){ // low의 mid부분이 high의 mid부분보다 작다면, 즉 high가 [start,mid] 모두 low보다 크다면
            tree[node].line = high;
            if(tree[node].r == -1){
                tree[node].r = tree.size();
                tree.push_back({-1,-1,mid+1,end,{0,-inf}});
            }
            update(tree[node].r, low);
        }
        else{ // 즉, low가 [mid,end] 모두 high보다 크다면
            tree[node].line = low;
            if(tree[node].l == -1){
                tree[node].l = tree.size();
                tree.push_back({-1,-1,start,mid,{0,-inf}});
            }
            update(tree[node].l,high);
        }
    }

    ll query(int node, ll x){
        if(node == -1) return -inf;
        ll start = tree[node].s, end = tree[node].e;
        ll mid = start + end >> 1;
        if(x <= mid) return max(tree[node].line.get(x), query(tree[node].l,x));
        else return max(tree[node].line.get(x), query(tree[node].r, x));
    }
}seg;


int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q; cin>>q;
    seg.init(-2e12, 2e12);
    while(q--){
        ll op, a, b; cin>>op;
        if(op==1){
            cin>>a>>b;
            seg.update(0,{a,b});
        }else{
            cin>>a;
            cout<<seg.query(0,a)<<'\n';
        }
    }

    return 0;
}
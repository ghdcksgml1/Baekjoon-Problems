#include <iostream>
using namespace std;
typedef long long ll;
ll arr[100002];
ll area;
ll n;


struct Tree{
    ll mn_idx = 0;
    ll value = 0;
}tree[400004];

void buildRec(ll node,ll start,ll end){
    if(start == end){
        tree[node].value = arr[start];
        tree[node].mn_idx = start;
        return ;
    }
    ll mid = (start + end) / 2;
    buildRec(node*2,start,mid);
    buildRec(node*2+1,mid+1,end);
    tree[node].mn_idx = (tree[node*2].value < tree[node*2+1].value)? tree[node*2].mn_idx: tree[node*2+1].mn_idx;
    tree[node].value = min(tree[node*2].value, tree[node*2+1].value);
    return ;
}

ll query(ll left,ll right,ll node,ll start,ll end){
    if(left>end || right<start){
        return 100001;
    }
    if(left<=start && end<=right){
        return tree[node].mn_idx;
    }
    ll mid = (start + end) / 2;
    ll leftVal = query(left,right,node*2,start,mid);
    ll rightVal = query(left,right,node*2+1,mid+1,end);
    return arr[leftVal] < arr[rightVal] ? leftVal : rightVal;
}

void Divide_Conquer(ll start, ll end);
int main(void) {
    scanf("%lld", &n);
    arr[100001] = 100000000000;
    area = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    buildRec(1,0,n-1);
    Divide_Conquer(0, n - 1);
    printf("%lld\n", area);
}
//분할정복
void Divide_Conquer(ll start, ll end) {
    if (start == end) {
        if (area < arr[start]) {
            area = arr[start];
        }
    }
    else {
        ll min = 123123112321323;
        ll Min_index;
        Min_index = query(start,end,1,0,n-1);
        min = arr[Min_index];

        if (area < min * (end - start + 1)) {
            area = min * (end - start + 1);
        }

        if (Min_index == start) {
            Divide_Conquer(start + 1, end);
        }
        else if (Min_index == end) {
            Divide_Conquer(start, end - 1);
        }
        else {
            Divide_Conquer(start, Min_index - 1);
            Divide_Conquer(Min_index + 1, end);
        }
    }
}

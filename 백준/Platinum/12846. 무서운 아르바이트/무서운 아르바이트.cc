//// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string.h> // memset
//#define MAX 100001
//
//using namespace std;
//
//struct Tree{
//    int value;
//}tree[MAX*4];
//
//typedef long long ll;
//ll arr[100002];
//ll area;
//ll n;
//
//int buildRec(int node,int start,int end){
//    if(start == end){
//        return tree[node].value = arr[start];
//    }
//    int mid = (start + end) / 2;
//    return tree[node].value = min(buildRec(node*2,start,mid), buildRec(node*2+1,mid+1,end));
//}
//
//int queryRec(int left,int right,int node,int start,int end){
//    if(left>end || right<start){
//        return 1000001;
//    }
//    if(left<=start && end<=right){
//        return tree[node].value;
//    }
//    int mid = (start + end) / 2;
//    return min(queryRec(left,right,node*2,start,mid), queryRec(left,right,node*2+1,mid+1,end));
//}
//
////분할정복
//void Divide_Conquer(ll start, ll end) {
//    if (start == end) {
//        if (area < arr[start]) {
//            area = arr[start];
//        }
//    }
//    else if(1<=start && end<=n){
//        ll min = queryRec(start,end,1,1,n);
//
//        if (area < min * (end - start + 1)) {
//            area = min * (end - start + 1);
//        }
//
//        Divide_Conquer(start, Min_index - 1);
//        Divide_Conquer(Min_index + 1, end);
//    }
//}
//
//int main(void){
//    // 입출력 속도 최적화
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    cin>>n;
//    for(int i=1;i<=n;i++){
//        cin>>arr[i];
//    }
//
//    buildRec(1,1,n);
//
//    Divide_Conquer(1,n);
//    cout<<area;
//
//    return 0;
//}

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

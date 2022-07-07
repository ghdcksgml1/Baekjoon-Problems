// 언어 : C++ , (성공/실패) : 1/0 , 메모리 : 2024 KB , 시간 : 0ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string.h> // memset

#define ALL(x) begin(x), end(x)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define xx first
#define yy second
#define MAX 1e6

using namespace std;
typedef long long ll;

struct Node{
    int mx = 0; // 최댓값
    vector<int> mx_idx; // 최댓값의 인덱스

    int mn = 1e5; // 최솟값
    vector<int> mn_idx; // 최솟값의 인덱스
};

int N,K;
deque<int> dq[101];
deque<int> tmp_dq[101];
int dx[4] = {1,0};
int dy[4] = {0,1};

void stage1(){
//    cout<<"STAGE 1"<<'\n';
    int height = 1; // 어항의 높이
    int width = 1; // 2층이상부터 쌓여있는 어항이 차지하는 너비

    // 어항 쌓기
    while(((int)dq[0].size() - width - height) >= 0){ // (dq[0].size() - weight - height) < 0
        for(int i=width-1;i>=0; i--){
            for(int j=height-1;j>=0; j--){
                tmp_dq[width-i].push_front(dq[j][i]);
            }
        }
        for(int i=width;i<dq[0].size();i++){
            tmp_dq[0].push_back(dq[0][i]);
        }

        for(int i=0;i<101;i++) {
            dq[i].clear();
            if(!tmp_dq[i].empty()) height = i;
            else continue;
            dq[i] = tmp_dq[i];
//            for(int cur : dq[i]) cout<<cur<<' ';
//            cout<<'\n';
            tmp_dq[i].clear();
        }

        height += 1;
        width = dq[1].size();
    }

    // 물고기 재분배
    for(int i=0;i<height;i++){
        tmp_dq[i] = dq[i];
    }

    for(int i=0;i<height;i++){
        int size = tmp_dq[i].size();
        for(int j=0;j<size;j++){
            for(int k=0;k<2;k++){
                if(j>=width && k==0) continue;
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx<0 || ny<0 || nx>=height || ny>=size) continue;
                int res = abs(tmp_dq[nx][ny] - tmp_dq[i][j])/5;
                if(res > 0){
                    if(tmp_dq[nx][ny] > tmp_dq[i][j]){
                        dq[nx][ny] -= res;
                        dq[i][j] += res;
                    }else{
                        dq[nx][ny] += res;
                        dq[i][j] -= res;
                    }
                }
            }
        }
    }

    for(int i=0;i<101;i++){
        if(!tmp_dq[i].empty()) tmp_dq[i].clear();
        else break;
    }


    // 다시 일렬로 정렬
    for(int i=0;i<width; i++){
        for(int j=0;j<height; j++){
            tmp_dq[0].push_back(dq[j][i]);
        }
    }
    for(int i=width;i<dq[0].size();i++) tmp_dq[0].push_back(dq[0][i]);
    for(int i=0;i<101;i++) {
        dq[i].clear();
        if(!tmp_dq[i].empty()) height = i;
        else continue;
        dq[i] = tmp_dq[i];
//        for(int cur : dq[i]) cout<<cur<<' ';
//        cout<<'\n';
        tmp_dq[i].clear();
    }
}

void stage2(){
    int size = dq[0].size();

    for(int i=0;i<size/2;i++){
        dq[1].push_front(dq[0].front());
        dq[0].pop_front();
    }

    for(int i=0;i<size/4;i++){
        dq[3].push_front(dq[0].front());
        dq[0].pop_front();
        dq[2].push_front(dq[1].front());
        dq[1].pop_front();
    }

    // 물고기 재분배
    for(int i=0;i<4;i++){
        tmp_dq[i] = dq[i];
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<size/4;j++){
            for(int k=0;k<2;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx<0 || ny<0 || nx>=4 || ny>=size/4) continue;
                int res = abs(tmp_dq[nx][ny] - tmp_dq[i][j])/5;
                if(res > 0){
                    if(tmp_dq[nx][ny] > tmp_dq[i][j]){
                        dq[nx][ny] -= res;
                        dq[i][j] += res;
                    }else{
                        dq[nx][ny] += res;
                        dq[i][j] -= res;
                    }
                }
            }
        }
    }

    for(int i=0;i<101;i++){
        if(!tmp_dq[i].empty()) tmp_dq[i].clear();
        else break;
    }

    // 다시 일렬로 정렬
    for(int i=0;i<size/4; i++){
        for(int j=0;j<4; j++){
            tmp_dq[0].push_back(dq[j][i]);
        }
    }
    for(int i=size/4;i<dq[0].size();i++) tmp_dq[0].push_back(dq[0][i]);
    for(int i=0;i<101;i++) {
        dq[i].clear();
        if(tmp_dq[i].empty()) continue;
        dq[i] = tmp_dq[i];
//        for(int cur : dq[i]) cout<<cur<<' ';
//        cout<<'\n';
        tmp_dq[i].clear();
    }
}

Node calMxMn(deque<int> d){
    Node node;
    for(int i=0;i<d.size();i++){
        if(node.mx <= d[i]){
            if(node.mx == d[i])
                node.mx_idx.push_back(i);
            else{
                node.mx_idx.clear();
                node.mx_idx.push_back(i);
            }
            node.mx = d[i];
        }
        if(node.mn >= d[i]) {
            if (node.mn == d[i])
                node.mn_idx.push_back(i);
            else {
                node.mn_idx.clear();
                node.mn_idx.push_back(i);
            }
            node.mn = d[i];
        }
    }

    return node;
}

int main(void){
    // 입출력 속도 최적화
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>K;
    for(int i=0;i<N;i++){
        int tmp; cin>>tmp;
        dq[0].push_back(tmp);
    }

    int cnt = 0;

    while(true){
        Node node = calMxMn(dq[0]);
        if(abs(node.mx-node.mn) <= K) break;
        for(int cur : node.mn_idx){
            dq[0][cur]++;
        }

        stage1();
        stage2();

        cnt++;
    }

    cout<<cnt<<'\n';



    return 0;
}
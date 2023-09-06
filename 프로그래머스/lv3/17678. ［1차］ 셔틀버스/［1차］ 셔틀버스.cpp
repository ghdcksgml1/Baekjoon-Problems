#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
    int h; // 시간
    int m; // 분
};

vector<Node> v;

void minuteplus(Node& a, int b) {
    if (a.m + b >= 60) {
        a.h += 1;
        a.m += (b - 60);
    } else {
        a.m += b;
    }
}

void minuteminus(Node& a, int b) {
    if (a.m - b < 0) {
        a.h -= 1;
        a.m = 60 + (a.m - b);
    } else {
        a.m -= b;
    }
}

string printTime(Node n) {
    string tmp = "";
    if (n.h < 10) {
        tmp += "0";
        tmp += to_string(n.h);
    } else {
        tmp += to_string(n.h);
    }
    tmp += ":";
    if (n.m < 10) {
        tmp += "0";
        tmp += to_string(n.m);
    } else {
        tmp += to_string(n.m);
    }
    
    return tmp;
}

bool cmp(Node n1, Node n2) {
    if (n1.h == n2.h) {
        return n1.m < n2.m;
    }
    
    return n1.h < n2.h;
}
// 원하는 시간에 탈 수 있다.
// n*m만큼 순회하면서 현재 출발시간보다 작은값을 조사함
// 버스에 인원을 가득채울 수 있으면 다음으로
// 만약 마지막 버스까지 인원이 다 채워지면 (순회가 끝나면)
// 마지막 줄선 사람기준으로 뒤로 돌아가야한다.
// 마지막 줄선 사람이랑 똑같은 사람의 cnt가 0이면 그냥 node 값 넣고
// 아니라면 마지막 사람 시간의 -1분


string solution(int n, int t, int m, vector<string> timetable) {
    int time_size = timetable.size();
    
    for (string s : timetable) {
        v.push_back({stoi(s.substr(0,2)), stoi(s.substr(3,2))});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    Node node = {9,0}; // 시작 시간
    // 다른사람들이 타고도 남을경우
//     if (time_size < n*m) {
//         for (int i=0; i<n-1; i++) {
//             minuteplus(node, t);
//         }
        
//         return printTime(node);
//     }
    Node prev = {-1, -1};
    int cnt = 0; // 같은 숫자 카운트
    int idx = 0;
    int lastCnt = 0;
    
    bool trigger = false;

    for (int i=0; i<n ;i++) {
        for (int j=0; j<m; j++) {
            if (idx == time_size) trigger = true;
            if (trigger) continue;
            if (node.h >= v[idx].h) {
                if (node.h == v[idx].h && node.m < v[idx].m) continue;
                if (i == n-1) lastCnt++;
                if (prev.h == v[idx].h && prev.m == v[idx].m) {
                    cnt++;
                } else {
                    prev = v[idx];
                    cnt = 1;
                }
                idx++;
            }
        }
        if (i != n-1) minuteplus(node, t);
    }
    cout << "node: " << node.h << ", " << node.m << '\n';
    cout << "idx: " << idx << '\n';
    cout << "cnt: " << cnt << '\n';
    cout << "trigger :  " << trigger << '\n';
    cout << "lastcnt :  " << lastCnt << '\n';

    // 쓰인적은 있으면서 다쓰진 않은 것
    if (!trigger && cnt != 0) {
        if (lastCnt < m) return printTime(node);
        minuteminus(prev, 1);
        return printTime(prev);
    } else {
        return printTime(node);
    }
}
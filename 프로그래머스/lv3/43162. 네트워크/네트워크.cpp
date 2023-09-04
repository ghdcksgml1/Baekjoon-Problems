#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

// 1 1 0
// 1 1 0
// 0 0 1

int parent[202];
map<int, int> m;

int f_p(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = f_p(parent[a]);
}

void connect(int a, int b) {
    int tmp1 = f_p(a);
    int tmp2 = f_p(b);
    
    if (tmp1 < tmp2) parent[tmp2] = tmp1;
    else parent[tmp1] = tmp2;
}

int solution(int n, vector<vector<int>> computers) {
    for (int i=0; i<202; i++) {
        parent[i] = i;
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n;j++) {
            if (computers[i][j] == 1) {
                connect(i+1, j+1);
            }
        }
    }
    
    for (int i=1; i<=n; i++) {
        f_p(i);
        m[parent[i]] = 1;
    }
    
    return m.size();
}
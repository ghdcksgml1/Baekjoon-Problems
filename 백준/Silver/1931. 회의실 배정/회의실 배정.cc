#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }

    return a.second < b.second;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 입력 값 받기
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        v.push_back({tmp1, tmp2});
    }
    //

    sort(v.begin(), v.end(), cmp);

    int mx = 0;
    int recently_add_idx = 0;

    for (pair<int,int> tmp : v) {
        if (tmp.first >= recently_add_idx) {
            mx++;
            recently_add_idx = tmp.second;
        }
    }

    cout << mx << '\n';

    return 0;
}
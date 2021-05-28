#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int K;
char bol;
bool visited[10];
string name = "";
vector<char> v;
vector<string> vs;
void dp(int x,string nm,int vis_Num) {
	if (K+1 == x) {
		vs.push_back(nm);
		return;
	}
	if (x != 0 && v[x-1] == '<') {
		for (int i = vis_Num+1; i <= 9; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			dp(x + 1, nm + to_string(i),i);
			visited[i] = false;
		}
	}
	else if (x != 0 && v[x-1] == '>') {
		for (int i = vis_Num-1; i >= 0; i--) {
			if (visited[i]) continue;
			visited[i] = true;
			dp(x + 1, nm + to_string(i),i);
			visited[i] = false;
		}
	}
	else {
		for (int i = 0; i <= 9; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			dp(x + 1, nm + to_string(i),i);
			visited[i] = false;
		}
	}
}
void init() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> bol;
		v.push_back(bol);
	}
	dp(0, "",0);
	sort(vs.begin(), vs.end());
	cout << vs[vs.size()-1] << '\n'<<vs[0]<<'\n';
}
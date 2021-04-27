#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<pair<int, pair<int, string>>, vector<pair<int, pair<int, string>>>, greater<pair<int, pair<int, string>>>> pq;


int main(void) {
	int n1;
	string n2;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> n1 >> n2;
		pq.push({ n1,{i,n2} });
	}
	while (!pq.empty()) {
		cout << pq.top().first << ' ' << pq.top().second.second << '\n';
		pq.pop();
	}
}
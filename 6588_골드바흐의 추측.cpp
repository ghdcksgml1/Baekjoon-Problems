#include <iostream>
#include <vector>
using namespace std;
int N;
bool n[1000001];
vector<int> v;
vector<int> num;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	while (1) {
		cin >> N;
		if (N != 0) {
			num.push_back(N);
		}
		else {
			break;
		}
	}
	N = 1000000;
	// 에라토스테네스의 체
	for (int i = 2; i * i <= N; i++) {
		if (n[i]) continue;
		for (int j = 2; i * j <= N; j++) {
			n[i * j] = 1;
		}
	}
	for (int i = 2; i <= N; i++) {
		if (n[i] == 0) {
			v.push_back(i);
		}
	}
	v.push_back(100000000);
	for (int i = 0; i < num.size(); i++) {
		int sum = 0; int start = 0; int end = 0;
		for (int j = 0; v[j] < num[i]; j++) {
			end++;
		}
		while (1) {
			sum = v[start] + v[end];
			if (start > end) {
				cout << "Goldbach's conjecture is wrong." << '\n';
				break;
			}
			if (sum > num[i]) {
				end--;
				start = 0;
			}
			else if (sum == num[i] && v[start]!=2) {
				cout <<num[i]<<" = "<< v[start]<<" + "<<v[end] << '\n';
				break;
			}
			else {
				start++;
			}
		}
		
		
	}
}
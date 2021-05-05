#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
string s = "";
vector<string>S;

bool compare(string i, string j) {
	if (i.size() == j.size()) {
		return i < j;
	}
	return i.size() < j.size();
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		S.push_back(s);
	}
	// unique�� ��ȯ���� �����Ⱚ�� ù��° ���� ��ġ!!
	sort(S.begin(), S.end());
	S.erase(unique(S.begin(), S.end()), S.end());
	sort(S.begin(), S.end(), compare);
	for (int i = 0; i < S.size(); i++) {
		cout << S[i] << '\n';
	}
}
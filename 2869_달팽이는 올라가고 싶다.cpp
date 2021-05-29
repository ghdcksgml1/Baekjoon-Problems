#include <iostream>
using namespace std;
int main(void) {
	int a, b, v;
	int count = 0;
	int sum = 0;
	cin >> a >> b >> v;


	//(a-b)*i>=v
	if ((v - a) % (a - b) == 0) count = (v - a) / (a - b) + 1;
	else if ((v - a) % (a - b) > 0) count = (v - a) / (a - b) + 2;


	cout << count << '\n';
}
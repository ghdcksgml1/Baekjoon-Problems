#include <iostream>
#include <deque>
using namespace std;
int K;
string name[4];
deque<int> gear_wheel[4];
// 맞닿는 부분은 인덱스 2와 6

// 톱니바퀴 자체 회전
void wheel_spin(int num, int rotation) {
	if (rotation == 1) {
		gear_wheel[num].push_front(gear_wheel[num].back());
		gear_wheel[num].pop_back();
	}
	else if (rotation == -1) {
		gear_wheel[num].push_back(gear_wheel[num].front());
		gear_wheel[num].pop_front();
	}
	return;
}

void spin(int gear_wheel_num, int rotation) {
	int r, prev;
	int gear_wheel_[4] = { 0, }; // n번째 바퀴가 어디로 돌아야하는지
	gear_wheel_[gear_wheel_num] = rotation;

	r = rotation;
	prev = gear_wheel_num;
	for (int i = gear_wheel_num-1; i >= 0; i--) {
		if (gear_wheel[prev][6] != gear_wheel[i][2]) {
			gear_wheel_[i] = r * (-1);
			r = gear_wheel_[i];
			prev = i;
		}
		else break;
	}

	r = rotation;
	prev = gear_wheel_num;
	for (int i = gear_wheel_num + 1; i < 4; i++) {
		if (gear_wheel[prev][2] != gear_wheel[i][6]) {
			gear_wheel_[i] = r * (-1);
			r = gear_wheel_[i];
			prev = i;
		}
		else break;
	}
	
	for (int i = 0; i < 4; i++) {
		if (gear_wheel_[i] == 0) continue;
		wheel_spin(i, gear_wheel_[i]);
	}
	return;
}

void init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}
int main(void) {
	init();
	for (int i = 0; i < 4; i++) {
		cin >> name[i];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			gear_wheel[i].push_back( name[i][j]-'0');
		}
	}
	cin >> K;
	while (K--) {
		int n1, n2;
		cin >> n1 >> n2;
		spin(n1-1, n2);
	}
	int sum = 0;
	if (gear_wheel[0][0] == 1) sum += 1;
	if (gear_wheel[1][0] == 1) sum += 2;
	if (gear_wheel[2][0] == 1) sum += 4;
	if (gear_wheel[3][0] == 1) sum += 8;

	cout << sum << '\n';
}
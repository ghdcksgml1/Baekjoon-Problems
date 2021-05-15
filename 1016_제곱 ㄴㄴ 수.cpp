#include <iostream>

using namespace std;

bool eratos[1000001];

int main(void) {
	long long int min, max;
	cin >> min >> max;

	for (long long int i = 2; i * i <= max; i++) {
		long long int start = min / (i * i);
		if (start * i * i != min) start++; // start<min �̹Ƿ� start�� ��������
		// min���� ũ�� max���� ���� ������ �������Ѿ��Ѵ�.
		for (long long int j = start; i * i * j <= max; j++) {
			eratos[i * i * j - min] = true;
		}
	}
	int count = 0;
	for (int i = 0; i < max - min + 1; i++) {
		if (!eratos[i]) count++;
	}
	cout << count << '\n';
}
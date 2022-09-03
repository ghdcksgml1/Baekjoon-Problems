#include <stdio.h>
#include <algorithm>
using namespace std;

const int n_ = 1e5 + 3;
int n, k, d, ans, l, r, cnt[33];

struct ABC { int alg, abt; } stu[n_];

int main() {

	scanf("%d %d %d", &n, &k, &d);

	for (int i = 0; i < n; i++) {
		int m;
		scanf("%d %d", &m, &stu[i].abt);
		while (m--) {
			int a;
			scanf("%d", &a); --a;
			stu[i].alg |= (1 << a);
		}
	}

	sort(stu, stu + n, [](const ABC &i, const ABC &j) { return i.abt < j.abt; });

	while (r < n) {
		int now = 0;
		while (stu[r].abt - stu[l].abt > d) {
			for (int i = 0; i < k; i++) if (stu[l].alg & (1 << i)) cnt[i]--;
			l++;
		}
		for (int i = 0; i < k; i++) if (stu[r].alg & (1 << i)) cnt[i]++;
		for (int i = 0; i < k; i++) if (cnt[i] > 0 && cnt[i] < r - l + 1) now++;
		ans = max(ans, now * (r - l + 1));
		r++;
	}

	printf("%d", ans);

	return 0;
}
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int a[1000010];
int tcn, n, q, min_, pos, max_res, stnd;
int cnt[30010], aex[30010];
int min(int a, int b) {
	return a < b ? a : b;
}
struct list {
	int le;
	int ri;
	int size;
	vector<pair<int, int>> range;
	bool operator<(const list &a) {
		return size == a.size ? (le == a.le ? ri < a.ri : le < a.le) : size < a.size;
	}
} re[30010];
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%d %d", &n, &q);
		for (int i = 1; i <= q; i++) {
			scanf("%d %d", &re[i].le, &re[i].ri);
			re[i].range.push_back({ re[i].le, re[i].ri });
			re[i].size = re[i].range[0].second - re[i].range[0].first;
			cnt[i] = 0;
		}
		sort(re + 1, re + q + 1);
		stnd = re[1].size;
		for (int i = 1; i <= q; i++) {
			for (int j = re[i].le; j <= re[i].ri; j++) {
				if (a[j] == 0) {
					a[j] = i;
					cnt[i]++;
				}
				else {
					aex[a[j]]++;
				}
			}
			if (cnt >= stnd) continue;
			for (int j = i - 1; j >= 1; j--) {
				if (aex[j]!=0 && cnt[j] > stnd) {
					aex[j] = min(cnt[j] - stnd, aex[j]);
					cnt[j] -= aex[j];
					cnt[i] += aex[j];
				}
			}
			for (int j = re[i].le; j <= re[i].ri; j++) {
				if (aex[a[j]] > 0) {
					aex[a[j]]--;
					a[j] = i;
				}
			}
		}
		for (int i = 1; i <= max_res; i++) {
			for (int j = 1; j <= q; j++) {

			}
		}

		for (int i = 1; i <= q; i++) {
			for (int j = re[i].le; j <= re[i].ri; j++) {
				a[j].push_back(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (a[i].size() == 1) {
				cnt[a[i][0]]++;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (a[i].size() >= 2) {
				min_ = 2100000000;
				pos = 0;
				for (int j = 0; j < a[i].size(); j++) {
					if (cnt[a[i][j]] < min_) {
						min_ = cnt[a[i][j]];
						pos = a[i][j];
					}
				}
				cnt[pos]++;
			}
		}
		min_ = 2100000000;
		for (int i = 1; i <= q; i++) {
			if (cnt[i] < min_) min_ = cnt[i];
			a[i].clear();
		}
		printf("Case #%d: %d\n", tc, min_);
	}
}
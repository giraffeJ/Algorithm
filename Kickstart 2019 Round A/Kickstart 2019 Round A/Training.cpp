#include<stdio.h>
#include<algorithm>
using namespace std;
int tcn, n, p, i, stnd, tr_hr, res, prev_stnd;
int a[100010];
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%d %d", &n, &p);
		res = 2100000000;
		for (i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + n + 1);
		stnd = a[p];
		tr_hr = 0;
		for (i = 1; i <= p; i++) {
			tr_hr += stnd - a[i];
		}
		if (tr_hr < res) res = tr_hr;
		for (i = p + 1; i <= n; i++) {
			prev_stnd = stnd;
			stnd = a[i];
			tr_hr = tr_hr + (stnd - prev_stnd)*(p-1);
			tr_hr -= (prev_stnd - a[i - p]);
			if (tr_hr < res) res = tr_hr;
		}
		printf("Case #%d: %d\n", tc, res);
	}
	return 0;
}
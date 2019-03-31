#include<stdio.h>
#include<algorithm>
using namespace std;
int a[200010], cnt[200010], inc[200010], dec[200010];
int n, res, inc_n, dec_n;
int main() {
	scanf("%d", &n);
	res = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (cnt[a[i]] == 0) inc[++inc_n] = a[i];
		cnt[a[i]]++;
		if (cnt[a[i]] == 2) dec[++dec_n] = a[i];
		if (cnt[a[i]] >= 3) res = 0;
	}
	if (res == 0) printf("NO\n");
	else {
		sort(inc + 1, inc + inc_n + 1);
		sort(dec + 1, dec + dec_n + 1);
		printf("YES\n");
		printf("%d\n", inc_n);
		for (int i = 1; i <= inc_n; i++) {
			printf("%d ", inc[i]);
		}
		printf("\n%d\n", dec_n);
		for (int i = dec_n; i >= 1; i--) {
			printf("%d ", dec[i]);
		}
		printf("\n");
	}
	return 0;
}
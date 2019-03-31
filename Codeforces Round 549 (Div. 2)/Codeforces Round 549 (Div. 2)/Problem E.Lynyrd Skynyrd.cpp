#include<stdio.h>
int n, m, q, l, r;
int a[200010], b[200010], par[200010], d[200010], clo[200010];
int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (i >= 2) par[a[i]] = a[i - 1];
	}
	par[a[1]] = a[n];
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		d[i] = d[clo[par[b[i]]]] + 1;
		clo[b[i]] = i;
	}
	for (int i = 1; i <= q; i++) {
		scanf("%d %d", &l, &r);
		if (d[r] - d[l] >= n - 1) printf("1");
		else printf("0");
	}
	printf("\n");
	return 0;
}

#include<stdio.h>
#define MOD 1000000009;
typedef long long int lli;
int n, k;
lli d[6][1000010];
int main() {
	scanf("%d %d", &n, &k);
	d[5][0] = 1;
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= 4; i++) {
			d[i][j] = d[5][j - 1];
			if (i == 4) d[i][j] *= (k - 3);
			d[i][j] %= MOD;
			if (i != 3) continue;
			if (j >= 5) d[i][j] = d[i][j] - (d[5][j - 5] * 2) + 2000000018;
			if (j >= 7) d[i][j] += d[5][j - 7];
			d[i][j] %= MOD;
		}
		d[5][j] = d[1][j] + d[2][j] + d[3][j] + d[4][j];
		d[5][j] %= MOD;
	}
	printf("%lld\n", d[5][n]);
}

/*
#include<stdio.h>
#define MOD 1000000009
typedef long long int lli;
int n, k;
lli d[4][1000010];
int main() {
	scanf("%d %d", &n, &k);
	d[3][0] = 1;
	for (int j = 1; j <= n; j++) {
		d[1][j] = d[3][j - 1];
		if (j >= 5) d[1][j] = d[1][j] - (d[3][j - 5] * 2);
		if (j >= 7) d[1][j] = d[1][j] + d[3][j - 7];
		d[1][j] = (d[1][j] + MOD) % MOD;
		d[2][j] = (d[3][j - 1] * (k - 1) + MOD) % MOD;
		d[3][j] = (d[1][j] + d[2][j] + MOD) % MOD;
		printf("%lld ", d[3][j]);
	}
	printf("\n%lld\n", d[3][n]);
}
*/
#include<stdio.h>
typedef long long int lli;
#define MOD 1000000007
lli a[1000010], mul[1000010];
lli tcn, n, k, x1, y1, c, d, e1, e2, f;
void make_array_a() {
	lli xi = x1, yi = y1, xim1, yim1;
	for (int i = 1; i <= n; i++) {
		a[i] = (xi + yi) % f;
		xim1 = xi;
		yim1 = yi;
		xi = (c*xim1 + d * yim1 + e1) % f;
		yi = (d*xim1 + c * yim1 + e2) % f;
	}
}
void init() {
	for (int i = 1; i <= n; i++) {
		mul[i] = i;
	}
}
lli calc_power() {
	lli res = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		sum = (sum + mul[i])%MOD;
		res = (res + (a[i] * ((sum*(n - i + 1)%MOD))))%MOD;
	}
	return res;
}
void increase_mul() {
	for (int i = 1; i <= n; i++) {
		mul[i] = (mul[i] * i)%MOD;
	}
}
lli power(lli a, lli b) {
	lli res = 0, k=1;
	for (int i = 1; i <= b; i++) {
		k = (k * a)%MOD;
		res = (res + k)%MOD;
	}
	return res;
}
int main() {
	scanf("%lld", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%lld %lld", &n, &k);
		scanf("%lld %lld %lld %lld %lld %lld %lld", &x1, &y1, &c, &d, &e1, &e2, &f);
		init();
		make_array_a();
		lli sumx = k;
		lli powersum = sumx * n * a[1];
		for (int i = 2; i <= n; i++) {
			lli sumi;
			sumi = power(i, k);
			sumx = (sumx + sumi)%MOD;
			powersum = (powersum + a[i]*((sumx*(n - i + 1)%MOD)))%MOD;
		}/*
		for (int i = 1; i <= k; i++) {
			lli poweri;
			poweri = calc_power();
			powersum = (powersum + poweri)%MOD;
			increase_mul();
		}*/
		printf("Case #%d: %lld\n", tc, powersum);
	}
	getchar();
	getchar();
}
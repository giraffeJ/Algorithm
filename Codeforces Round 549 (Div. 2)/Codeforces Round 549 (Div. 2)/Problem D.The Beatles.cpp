#include<stdio.h>
typedef long long int lli;
lli n, k, a, b, m, l, x, y, temp;
lli fastfood_restaurant[100010];
lli sp1, sp2;
lli after_l[200010];
lli pos(lli a) {
	while (a <= 0)
		a += m;
	while (a > m)
		a -= m;
	return a;
}
lli gcd(lli a, lli b) {
	return a % b == 0 ? b : gcd(b, a%b);
}
lli min_(lli a, lli b) {
	return a < b ? a : b;
}
lli max_(lli a, lli b) {
	return a > b ? a : b;
}
int main() {
	scanf("%lld %lld", &n, &k);
	scanf("%lld %lld", &a, &b);
	m = n * k;
	fastfood_restaurant[1] = 1;
	for (lli i = 2; i <= n; i++) {
		fastfood_restaurant[i] = fastfood_restaurant[i - 1] + k;
	}
	sp1 = pos(1 - a);
	sp2 = pos(1 + a);
	for (lli i = 1; i <= n; i++) {
		after_l[i * 2 - 1] = pos(fastfood_restaurant[i] - b);
		after_l[i * 2] = pos(fastfood_restaurant[i] + b);
	}
	x = 2100000000;
	y = -2100000000;
	for (lli j = 1; j <= n * 2; j++) {
		l = pos(after_l[j] - sp1);
		temp = m / gcd(l, m);
		x = min_(temp, x);
		y = max_(temp, y);
		l = pos(after_l[j] - sp2);
		temp = m / gcd(l, m);
		x = min_(temp, x);
		y = max_(temp, y);
	}
	printf("%lld %lld\n", x, y);
	return 0;
}
#include<stdio.h>
int n, k, mn, res, temp;
int product(int a) {
	int re = 1;
	while (a > 0) {
		re *= (a % 10);
		a /= 10;
	}
	return re;
}
int max_(int a, int b) {
	return a > b ? a : b;
}
int main() {
	scanf("%d", &n);
	res = product(n);
	k = 10;
	for (int i = 1; i <= 10; i++) {
		if (n > k) {
			n = n / k;
			n *= k;
			n--;
		}
		res = max_(res, product(n));
		k *= 10;
	}
	printf("%d\n", res);
}
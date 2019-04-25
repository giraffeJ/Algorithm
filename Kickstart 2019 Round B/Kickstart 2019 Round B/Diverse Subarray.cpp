#include<stdio.h>
int tcn, n, h, a[1010], res=-1;
int max(int a, int b) {
	return a > b ? a : b;
}
void get_input() {
	scanf("%d %d", &n, &h);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
}
int cx(int l, int r) {
	int c[100010] = { 0, }, ret = 0;
	for (int i = l; i <= r; i++) {
		if (c[a[i]] < h) {
			ret++;
			c[a[i]]++;
		}
		else if(c[a[i]]==h) {
			ret -= h;
			c[a[i]]++;
		}
	}
	return ret;
}
void find_solution() {
	res = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j - i + 1 <= res) continue;
			res = max(cx(i, j), res);
		}
	}
}
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		get_input();
		find_solution();
		printf("Case #%d: %d\n", tc, res);
	}
}
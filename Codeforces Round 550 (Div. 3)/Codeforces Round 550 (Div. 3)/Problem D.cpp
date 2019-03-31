#include<stdio.h>
int a[200010], cnt[200010];
int n, max, max_pos;
int main() {
	scanf("%d", &n);
	max = -1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
		if (cnt[a[i]] > max) {
			max = cnt[a[i]];
			max_pos = i;
		}
	}
	printf("%d\n", n - max);
	for (int i = max_pos+1; i <= n; i++) {
		if (a[i] > a[i - 1]) {
			printf("2 %d %d\n", i, i - 1);
			a[i] = a[i - 1];
		}
		else if (a[i] < a[i - 1]) {
			printf("1 %d %d\n", i, i - 1);
			a[i] = a[i - 1];
		}
	}
	for (int i = max_pos - 1; i >= 1; i--) {
		if (a[i] > a[i + 1]) {
			printf("2 %d %d\n", i, i + 1);
			a[i] = a[i + 1];
		}
		else if (a[i] < a[i + 1]) {
			printf("1 %d %d\n", i, i + 1);
			a[i] = a[i + 1];
		}
	}
	return 0;	
}
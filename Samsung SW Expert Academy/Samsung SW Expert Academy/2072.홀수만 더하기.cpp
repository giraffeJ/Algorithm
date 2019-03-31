#include<stdio.h>
int tcn, sum, k;
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		sum = 0;
		for (int i = 1; i <= 10; i++) {
			scanf("%d", &k);
			if (k % 2 == 1) {
				sum += k;
			}
		}
		printf("#%d %d\n", tc, sum);
	}
}
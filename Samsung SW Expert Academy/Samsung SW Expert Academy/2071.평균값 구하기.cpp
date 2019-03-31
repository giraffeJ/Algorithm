#include<stdio.h>
int tcn, k;
double sum, avg;
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		sum = 0;
		for (int i = 1; i <= 10; i++) {
			scanf("%d", &k);
			sum += k;
		}
		avg = sum / 10;
		avg += 0.5;
		k = avg;
		printf("#%d %d\n", tc, k);
	}
}
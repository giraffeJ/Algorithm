#include<stdio.h>
int tcn, n, q, res;
char alp[27][100010];
void get_input() {
	scanf("%d %d", &n, &q);
	char temp;
	getchar();
	for (int i = 1; i <= n; i++) {
		scanf("%c", &temp);
		alp[temp - 64][i]++;
	}
}
void sum_alp() {
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= 26; i++) {
			alp[i][j] = alp[i][j - 1] + alp[i][j];
		}
	}
}
void qna() {
	res = 0;
	int x, y;
	for (int k = 1; k <= q; k++) {
		scanf("%d %d", &x, &y);
		int ch = 0;
		for (int i = 1; i <= 26; i++) {
			if ((alp[i][y] - alp[i][x - 1]) % 2 == 1) {
				ch++;
			}
			if (ch == 2) break;
		}
		if (ch <= 1) res++;
	}
}
void init() {
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= 26; i++) {
			alp[i][j] = 0;
		}
	}
}
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		get_input();
		sum_alp();
		qna();
		printf("Case #%d: %d\n", tc, res);
		init();
	}
}
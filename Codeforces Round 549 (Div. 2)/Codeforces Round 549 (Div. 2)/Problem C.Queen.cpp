#include<stdio.h>

int n, p, sw;
int check[100010], respect_child[100010];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &p, &check[i]);
		if (check[i] == 0) respect_child[p] = 1;
	}
	sw = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i] == 1 && respect_child[i] == 0) {
			printf("%d ", i);
			sw = 1;
		}
	}
	if (sw == 1) printf("\n");
	else printf("-1\n");

}
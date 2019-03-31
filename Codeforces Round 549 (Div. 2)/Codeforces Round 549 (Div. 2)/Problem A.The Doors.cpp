#include<stdio.h>
int n, k, pos[2];
int min_(int a, int b) {
	return a < b ? a : b;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		if (k == 0) pos[0] = i;
		if (k == 1) pos[1] = i;
	}
	printf("%d\n", min_(pos[0], pos[1]));	
}
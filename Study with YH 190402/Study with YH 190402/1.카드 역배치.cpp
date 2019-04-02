#include<stdio.h>
int x, y;
int a[21] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
void reverse(int x, int y) {
	int temp[21];
	for (int i = 1; i <= y-x+1; i++) {
		temp[x + i - 1] = a[y - i + 1];
	}
	for (int i = x; i <= y; i++) {
		a[i] = temp[i];
	}
}
int main() {
	for (int i = 1; i <= 10; i++) {
		scanf("%d %d", &x, &y);
		reverse(x, y);
	}
	for (int i = 1; i <= 20; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
#include<stdio.h>
struct stone {
	int si;
	int ei;
	int li;
} stones[110];

int tcn, n, res;
int d[10500];

int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}
void get_input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &stones[i].si, &stones[i].ei, &stones[i].li);
	}
}
void greedy() {
	res = 0;
	int max_val, max_stone_ind;
	int ti = 0, c[110] = { 0, };
	for(int k=1; k<=n; k++){
		max_val = -2100000000;
		max_stone_ind = 0;
		for (int i = 1; i <= n; i++) {
			if (c[i] == 1) continue;
			int val = stones[i].ei - (stones[i].li*ti);
			for (int j = 1; j <= n; j++) {
				if (c[j] == 1 || j == i) continue;
				val -= min(stones[j].li*(stones[i].si+ti), max(stones[j].ei-(stones[j].li*ti), 0));
			}
			if (val > max_val) {
				max_val = val;
				max_stone_ind = i;
			}
		}
		c[max_stone_ind] = 1;
		res += max(stones[max_stone_ind].ei - (stones[max_stone_ind].li*ti), 0);
		ti += stones[max_stone_ind].si;
	}
}
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		get_input();
		greedy();
		printf("Case #%d: %d\n", tc, res);
	}
}
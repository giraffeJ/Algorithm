#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
vector<int> adj[100010];
int n, m, res_n, level_count;
int level[100010], c[100010];
int res[200010][3];
int min(int a, int b) {
	return a < b ? a : b;
}
void get_graph() {
	int x, y;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
void sort_degrees() {
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
}
int find_lines(int pos, int prev) {
	level[pos] = ++level_count;
	int min_level = level[pos], x, k;
	for (int i = 0; i < adj[pos].size(); i++) {
		x = adj[pos][i];
		if (x == prev) continue;
		if (c[x] == 1) {
			min_level = min(min_level, level[x]);
		}
		else {
			c[x] = 1;
			k = find_lines(x, pos);
			min_level = min(min_level, k);
			if (k > level[pos] && (i==0 || adj[pos][i - 1] != x) && (i==adj[pos].size()-1 || adj[pos][i + 1] != x)) {
				res[++res_n][1] = pos;
				res[res_n][2] = x;
			}
		}
	}
	return min_level;
}
void print_res() {
	printf("%d\n", res_n);
	for (int i = 1; i <= res_n; i++) {
		printf("%d %d\n", res[i][1], res[i][2]);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	get_graph();
	sort_degrees();
	find_lines(1, -1);
	print_res();
	return 0;
}
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, cnt, temp, res, x, y;
int di[200010], re[200010], c[200010], q[1000010];
struct ed {
	int x;
	int y;
} edge[200010];
struct inf {
	int to;
	int ind;
	int dir;
};
vector<inf> adj[200010];
void go(int start) {
	int r, f, x, y;
	r = f = 0;
	q[++r] = start;
	c[start] = 1;
	di[start] = 1;
	while (r > f) {
		x = q[++f];
		for (int i = 0; i < adj[x].size(); i++) {
			y = adj[x][i].to;
			if (c[y] == 0) {
				q[++r] = y;
				c[y] = 1;
				di[y] = 1 - di[x];
				if (edge[adj[x][i].ind].x == x) re[adj[x][i].ind] = 1;
			}
			else if (c[y] == 1) {
				if (di[y] + di[x] != 1) {
					res = -1;
					break;
				}
				else if (di[x]==1 && edge[adj[x][i].ind].x == x) re[adj[x][i].ind] = 1;
			}
		}
		if (res == -1) break;
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		edge[i].x = x;
		edge[i].y = y;
		adj[x].push_back({ y, i });
		adj[y].push_back({ x, i });
	}
	go(1);
	if (res == -1) printf("NO\n");
	else {
		printf("YES\n");
		for (int i = 1; i <= m; i++) {
			printf("%d", re[i]);
		}
		printf("\n");
	}
	return 0;
}
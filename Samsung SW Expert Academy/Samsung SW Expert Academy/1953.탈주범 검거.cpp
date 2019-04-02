#include<stdio.h>
int avail_dir[8][5] = { { 0, 0, 0, 0, 0 },{ 0, 1, 1, 1, 1 },{ 0, 1, 0, 1, 0 },{ 0, 0, 1, 0, 1 },{ 0, 1, 1, 0, 0 },{ 0, 0, 1, 1, 0 },{ 0, 0, 0, 1, 1 },{ 0, 1, 0, 0, 1 } };
int ch[60][60], t[60][60], q[2][100001], r, f;
int tcn, n, m, sx, sy, l, res;
int map[60][60];
void get_map() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
int opposite_dir[5] = { 0, 3, 4, 1, 2 };
void bfs(int sx, int sy) {
	int x, y, nx, ny;
	r = f = 0;
	q[0][++r] = sx;
	q[1][r] = sy;
	ch[sx][sy] = 1;
	t[sx][sy] = 1;
	while (r > f) {
		x = q[0][++f];
		y = q[1][f];
		if (t[x][y] >= l) continue;
		for (int i = 1; i <= 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || map[nx][ny] == 0) continue;
			if (ch[nx][ny] == 0 && avail_dir[map[x][y]][i] == 1 && avail_dir[map[nx][ny]][opposite_dir[i]] == 1) {
				ch[nx][ny] = 1;
				q[0][++r] = nx;
				q[1][r] = ny;
				t[nx][ny] = t[x][y] + 1;
			}
		}
	}
}
int count_loc() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (ch[i][j] == 1)
				cnt++;
		}
	}
	return cnt;
}
void ini() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			t[i][j] = ch[i][j] = 0;
		}
	}
}
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%d %d", &n, &m);
		scanf("%d %d %d", &sx, &sy, &l);
		ini();
		sx++;
		sy++;
		get_map();
		bfs(sx, sy);
		res = count_loc();
		printf("#%d %d\n", tc, res);
	}
}
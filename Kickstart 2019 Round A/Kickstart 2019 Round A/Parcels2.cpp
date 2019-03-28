#include<stdio.h>
int n, m, tcn, res, cnt;
int a[251][251], d[251][251], c[251][251], q[2][1000000];
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
void init() {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			a[i][j] = c[i][j] = d[i][j] = 0;
		}
	}
}
void get_map() {
	int i, j;
	char k;
	for (i = 1; i <= n; i++) {
		getchar();
		for (j = 1; j <= m; j++) {
			scanf("%c", &k);
			a[i][j] = k - 48;
		}
	}
}
void bfs(int sx, int sy) {
	int i, r, f, x, y, nx, ny;
	r = f = 0;
	q[0][++r] = sx;
	q[1][r] = sy;
	c[sx][sy] = 1;
	d[sx][sy] = 0;
	while (r > f) {
		x = q[0][++f];
		y = q[1][f];
		for (i = 1; i <= 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
				if (c[nx][ny] == 0 || c[nx][ny] == 1 && d[nx][ny] > d[x][y] + 1) {
					q[0][++r] = nx;
					q[1][r] = ny;
					c[nx][ny] = 1;
					d[nx][ny] = d[x][y] + 1;
				}

			}
		}
	}
}
void get_distance() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 1) {
				bfs(i, j);
				cnt++;
			}
		}
	}
}
int findmax(int a[][251]) {
	int max = -210000;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] > max) max = a[i][j];
		}
	}
	return max;
}
int bfsnfmx(int sx, int sy, int d[][251], int st) {
	int i, q[2][70000], r, f, x, y, nx, ny;
	r = f = 0;
	q[0][++r] = sx;
	q[1][r] = sy;
	d[sx][sy] = 0;
	while (r > f) {
		x = q[0][++f];
		y = q[1][f];
		if (d[x][y] >= st) break;
		for (i = 1; i <= 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
				if (d[nx][ny] > d[x][y] + 1) {
					q[0][++r] = nx;
					q[1][r] = ny;
					c[nx][ny] = 1;
					d[nx][ny] = d[x][y] + 1;
				}

			}
		}
	}
	return findmax(d);
}
int testall() {
	int st, k, temp[251][251];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temp[i][j] = d[i][j];
		}
	}
	st = findmax(temp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] != 1) {
				k = bfsnfmx(i, j, temp, st);
				if (k < st) st = k;
				for (int g = 1; g <= n; g++) {
					for (int l = 1; l <= m; l++) {
						temp[g][l] = d[g][l];
					}
				}
			}
		}
	}
	return st;
}
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%d %d", &n, &m); // n=R, m=C
		init();
		get_map();
		cnt = 0;
		get_distance();
		if (cnt == 0) {
			bfs((n + 1) / 2, (m + 1) / 2);
			res = findmax(d);
		}
		else res = testall();
		printf("Case #%d: %d\n", tc, res);
	}
	return 0;
}
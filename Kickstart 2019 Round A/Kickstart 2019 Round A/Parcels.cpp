#include<stdio.h>
int n, m, tcn, res;
int a[251][251], d[251][251], c[251][251];
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
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
	int i, q[2][70000], r, f, x, y, nx, ny;
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
int abs(int a) {
	return a < 0 ? a * (-1) : a;
}
bool farcheck(int fx, int fy, int a, int b, int c, int d) {
	return (abs(fx - a) + abs(fy - b) < abs(fx - c) + abs(fy - d));
}
int findmax() {
	int max = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (d[i][j] > max) max = d[i][j];
		}
	}
	return max;
}
int find_pos() {
	int i, j, k, l, max_=-2100000000, fx, fy, temp[251][251], mx, my, nx, ny, res=100000, cnt=0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (a[i][j] == 1) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	if (cnt == 0) {
		bfs((n + 1) / 2, (m + 1) / 2);
		return findmax();
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (d[i][j] > max_) {
				max_ = d[i][j];
				fx = i;
				fy = j;
			}
			temp[i][j] = d[i][j];
		}
	}
	bfs(fx, fy);
	max_ = -2100000000;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (d[i][j] > max_) {
				max_ = d[i][j];
				mx = i;
				my = j;
			}
			else if (d[i][j] == max_) {
				if (farcheck(fx, fy, mx, my, i, j)) {
					mx = i;
					my = j;
				}
			}
			d[i][j] = temp[i][j];
		}
	}
	nx = (mx + fx) / 2;
	ny = (my + fy) / 2;
	bfs(nx, ny);
	k = findmax();
	if (k < res) res = k;
	for (i = 1; i <= 4; i++) {
		if (nx + dx[i] >= 1 && nx + dx[i] <= n && ny + dy[i] >= 1 && ny + dy[i] <= m) {
			for (j = 1; j <= n; j++) {
				for (l = 1; l <= m; l++) {
					d[j][l] = temp[j][l];
				}
			}
			bfs(nx + dx[i], ny + dy[i]);
			k = findmax();
			if (k < res) res = k;
		}
	}
	return res;
}
void init() {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			a[i][j] = c[i][j] = d[i][j] = 0;
		}
	}
}
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%d %d", &n, &m); // n=R, m=C
		init();
		get_map();
		res=find_pos();
		printf("Case #%d: %d\n", tc, res);
	}
	return 0;
}



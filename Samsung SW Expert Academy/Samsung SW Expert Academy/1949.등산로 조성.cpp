#include<stdio.h>
int n, m, k, tcn, res;
int map[10][10], starting_point[6][3];
int max_height;
int max(int a, int b) {
	return a > b ? a : b;
}
void get_map() {
	max_height = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j]>max_height)
				max_height = map[i][j];
		}
	}
}
void find_starting_point() {
	m = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (max_height == map[i][j]) {
				starting_point[++m][1] = i;
				starting_point[m][2] = j;
			}
		}
	}
}
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
int check[10][10];
int dfs(int x, int y, int distance, int k_use) {
	int max_dist = distance, nx, ny, temp;
	for (int i = 1; i <= 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && check[nx][ny] == 0) {
			if (map[nx][ny]<map[x][y]) {
				check[nx][ny] = 1;
				max_dist = max(dfs(nx, ny, distance + 1, k_use), max_dist);
				check[nx][ny] = 0;
			}
			else if (k_use == 0 && map[nx][ny] - k <map[x][y]) {
				temp = map[nx][ny];
				if (map[nx][ny] >= map[x][y])
					map[nx][ny] = map[x][y] - 1;
				check[nx][ny] = 1;
				max_dist = max(dfs(nx, ny, distance + 1, 1), max_dist);
				check[nx][ny] = 0;
				map[nx][ny] = temp;
			}
		}
	}
	return max_dist;
}
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%d %d", &n, &k);
		get_map();
		m = 0;
		find_starting_point();
		res = -1;
		for (int i = 1; i <= m; i++) {
			check[starting_point[i][1]][starting_point[i][2]] = 1;
			res = max(dfs(starting_point[i][1], starting_point[i][2], 1, 0), res);
			check[starting_point[i][1]][starting_point[i][2]] = 0;
		}
		printf("#%d %d\n", tc, res);
	}
}
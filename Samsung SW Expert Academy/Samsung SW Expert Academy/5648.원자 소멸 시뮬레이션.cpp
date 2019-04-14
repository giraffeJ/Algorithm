#include<stdio.h>
struct atom {
	int x;
	int y;
	int dir;
	int energy;
	int status; // 1=alive, 2=dead, 3=out of range
} at[1010];
int tcn, n;
int change_dir[4] = { 1, 3, 4, 2 };
int map[2020][2020];
void get_input() {
	scanf("%d", &n);
	int x, y, dir, energy;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d %d", &x, &y, &dir, &energy);
		at[i] = { x+1001, y+1001, change_dir[dir], energy, 1 };
		map[x + 1001][y + 1001] = i;
	}
}
int dx[5] = { 0, 0, 1, 0, -1 };
int dy[5] = { 0, 1, 0, -1, 0 };
int opposite_dir[5] = { 0, 3, 4, 1, 2 }, check[2020][2020];
int move() {
	int nx, ny, count = 0;
	for (int i = 1; i <= n; i++) {
		if (at[i].status != 1) continue;
		count++;
		nx = at[i].x + dx[at[i].dir];
		ny = at[i].y + dy[at[i].dir];
		if (nx == 0 || nx == 2002 || ny == 0 || ny == 2002) {
			at[i].status = 3;
			continue;
		}
		if (map[nx][ny] != 0 && at[map[nx][ny]].dir == opposite_dir[at[i].dir]) {
			at[map[nx][ny]].status = at[i].status = 2;
			continue;
		}
		at[i] = { nx, ny, at[i].dir, at[i].energy, 1 };
		check[nx][ny]++;
	}
	for (int i = 1; i <= n; i++) {
		if (check[at[i].x][at[i].y] > 1) {
			at[i].status = 2;
		}
	}
	for (int i = 1; i <= n; i++) {
		check[at[i].x][at[i].y] = 0;
	}
	return count;
}
void clear_map(int x, int y) {
	map[x][y] = map[x - 1][y] = map[x + 1][y] = map[x][y - 1] = map[x][y + 1] = 0;
}
int calc() {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (at[i].status == 2)
			sum += at[i].energy;
	}
	return sum;
}
void map_set() {
	for (int i = 1; i <= n; i++) {
		clear_map(at[i].x, at[i].y);
		if (at[i].status == 1) {
			map[at[i].x][at[i].y] = i;
		}
	}
}
int solution() {
	int count;
	while (1) {
		count = move();
		map_set();
		if (count == 0) break;
	}
	return calc();
}
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		get_input();
		printf("#%d %d\n", tc, solution());
	}
}
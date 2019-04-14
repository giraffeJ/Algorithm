#include<vector>
#include<stdio.h>
using namespace std;

int n, m, k, map[110][110][3], map2[110][110][3];
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
struct bio {
	int x;
	int y;
	int num;
	int dir;
};
vector<bio> arr;
void map_clear() {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			map[i][j][0] = 0;
			map[i][j][1] = 0;
		}
	}
}
int change_dir[5] = { 0, 1, 3, 4, 2 };
void get_input() {
	int x, y, num, dir;
	scanf("%d %d %d", &n, &m, &k);
	arr.clear();
	map_clear();
	for (int i = 1; i <= k; i++) {
		scanf("%d %d %d %d", &x, &y, &num, &dir);
		arr.push_back({ x, y, num, change_dir[dir] });
		map[x][y][0] = num; //해당 위치 미생물 수의 총합
		map[x][y][1] = change_dir[dir]; //해당 위치 미생물들이 합쳐진 후 진행할 방향
	}
}
void setting() {
	arr.clear();
	k = 0;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			map[i][j][0] = map2[i][j][0];
			map[i][j][1] = map2[i][j][1];
			map2[i][j][0] = map2[i][j][1] = map2[i][j][2] = 0;
			if (map[i][j][0] == 0) continue;
			arr.push_back({ i, j, map[i][j][0], map[i][j][1] });
			k++;
		}
	}
}
int dir_opposite[5] = { 0, 3, 4, 1, 2 };
void time_goes() {
	int nx, ny;
	for (int t = 1; t <= m; t++) {
		for (int i = 0; i<k; i++) {
			nx = arr[i].x + dx[arr[i].dir];
			ny = arr[i].y + dy[arr[i].dir];
			if (nx == 0 || nx == n - 1 || ny == 0 || ny == n - 1) {
				map2[nx][ny][0] = arr[i].num / 2;
				map2[nx][ny][1] = dir_opposite[arr[i].dir];
				map2[nx][ny][2] = arr[i].num / 2;
				continue;
			}
			if (map2[nx][ny][0] != 0) {
				if (map2[nx][ny][2]<arr[i].num) {
					map2[nx][ny][1] = arr[i].dir;
					map2[nx][ny][2] = arr[i].num;
				}
				map2[nx][ny][0] += arr[i].num;
			}
			else {
				map2[nx][ny][0] = arr[i].num;
				map2[nx][ny][1] = arr[i].dir;
				map2[nx][ny][2] = arr[i].num;
			}
		}
		setting();
	}
}
int find_sum() {
	int sum = 0;
	for (int i = 0; i<k; i++) {
		sum += arr[i].num;
	}
	return sum;
}
int main() {
	int tcn;
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		get_input();
		time_goes();
		printf("#%d %d\n", tc, find_sum());
	}
}
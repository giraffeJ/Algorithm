#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
struct ball {
	int color;
	int size;
	int index;
	bool operator <(const ball &a) {
		return size == a.size ? color<a.color : size<a.size;
	}
} balls[200010];
int size_count[2010], ball_sum[2010], color_sum[200010], color_sum_temp[200010], res[200010];
void get_input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &balls[i].color, &balls[i].size);
		balls[i].index = i;
		size_count[balls[i].size]++;
	}
}
void make_ball_sum() {
	for (int i = 1; i <= 2000; i++) {
		ball_sum[i] = ball_sum[i - 1] + (size_count[i] * i);
	}
}
void solution() {
	sort(balls + 1, balls + n + 1);
	for (int i = 1; i <= n; i++) {
		res[balls[i].index] = ball_sum[balls[i].size - 1] - color_sum[balls[i].color];
		color_sum_temp[balls[i].color] += balls[i].size;
		if (balls[i].size!=balls[i+1].size || balls[i].color != balls[i + 1].color) {
			color_sum[balls[i].color] = color_sum_temp[balls[i].color];
		}
	}
}
void print_res() {
	for (int i = 1; i <= n; i++) {
		printf("%d\n", res[i]);
	}
}
int main() {
	get_input();
	make_ball_sum();
	solution();
	print_res();
	return 0;
}
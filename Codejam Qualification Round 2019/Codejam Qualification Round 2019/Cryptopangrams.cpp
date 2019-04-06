#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int check[10010], cypertext[110], result[110];
int tcn, n, l, k;
vector<int> prime_number, answer_prime_number;
void find_prime_number() {
	int a[10010];
	for (int i = 2; i <= 10000; i++) {
		if (a[i] != 1) {
			prime_number.push_back(i);
			for (int j = i + i; j <= 10000; j += i) {
				a[j] = 1;
			}
		}
	}
}
void get_input() {
	scanf("%d %d", &n, &l);
	for (int i = 1; i <= l; i++) {
		scanf("%d", &cypertext[i]);
	}
}
int find_prime_divider(int a) {
	for (int i = 0; i < prime_number.size(); i++) {
		if (a%prime_number[i] == 0) {
			return prime_number[i];
		}
	}
	return 3;
}
int find_same_value(int a, int b, int c, int d) {
	if (a == c || a == d) return a;
	return b;
}
void answer_add(int a) {
	if (check[a] == 0) {
		answer_prime_number.push_back(a);
		check[a] = 1;
	}
}
void find_plaintext() {
	int x = find_prime_divider(cypertext[1]);
	int y = cypertext[1] / x;
	int k;
	answer_add(x);
	answer_add(y);
	for (int i = 2; i <= l; i++) {
		k = find_prime_divider(cypertext[i]);
		result[i] = find_same_value(x, y, k, cypertext[i]/k);
		if (i == 2) result[1] = x + y - result[i];
		x = k;
		y = cypertext[i] / k;
		answer_add(x);
		answer_add(y);
	}
	result[l + 1] = x + y - result[l];
}
void print_to_char() {
	for (int i = 1; i <= l + 1; i++) {
		for (int j = 0; j < answer_prime_number.size(); j++) {
			if (result[i] == answer_prime_number[j]) {
				printf("%c", j + 65);
				break;
			}
		}
	}
	printf("\n");
}
void init() {
	answer_prime_number.clear();
	for (int i = 3; i <= 10000; i += 2) check[i] = 0;
}
int main() {
	find_prime_number();
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		get_input();
		find_plaintext();
		sort(answer_prime_number.begin(), answer_prime_number.end());
		printf("Case #%d: ", tc);
		print_to_char();
		init();
	}
}

/*
3
103 31
217 1891 4819 2291 2987 3811 1739 2491 4717 445 65 1079 8383 5353 901 187 649 1003 697 3239 7663 291 123 779 1007 3551 1943 2117 1679 989 3053
10000 25
3292937 175597 18779 50429 375469 1651121 2102 3722 2376497 611683 489059 2328901 3150061 829981 421301 76409 38477 291931 730241 959821 1664197 3057407 4267589 4729181 5335543
103 33
217 1891 4819 2291 2987 3811 1739 2491 4717 445 65 1079 8383 5353 901 187 649 1003 697 3239 7663 291 123 779 1007 3551 1943 2117 1679 989 3053 923 169




Output

Case #1: CJQUIZKNOWBEVYOFDPFLUXALGORITHMS
Case #2: SUBDERMATOGLYPHICFJKNQVWXZ
A 3
B 5
C 7
D 11
E 13
F 17
G 19
H 23
I 29
J 31
K 37
L 41
M 43
N 47
O 53
P 59
Q 61
R 67
S 71
T 73
U 79
V 83
W 89
X 97
Y 101
Z 103
*/
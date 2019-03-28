#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
char temp[101];
string res;

int s, e, a, b, n, tcn, m;
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%d %d", &a, &b);
		scanf("%d", &n);
		s = a + 1;
		e = b;
		for (int i = 1; i <= n; i++) {
			m = (s + e) / 2;
			printf("%d\n", m);
			cin >> res;
			if (res == "CORRECT") break;
			else if (res == "TOO_SMALL") s = m + 1;
			else if (res == "TOO_BIG") e = m - 1;
			else if (res == "WRONG_ANSWER") break;
		}
		if (res == "WRONG_ANSWER") break;
	}
	return 0;
}
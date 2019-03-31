#include<stdio.h>
#include<string>
typedef long long int lli;
using namespace std;
char s[200010], t[200010], res[200010];
int n;
int main() {
	scanf("%d", &n);
	scanf(" %s %s", &s, &t);
	for (int i = n - 1; i >= 0; i--) {
		res[i] = s[i] + t[i] - 194;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (res[i - 1] % 2 == 1) {
			if (res[i] + 26 <= 50) {
				res[i - 1]--;
				res[i] += 26;
			}
			else if (res[i] - 26 >= 0) {
				res[i - 1]++;
				res[i] -= 26;
			}
		}
		res[i] /= 2;
		res[i] += 97;
	}
	printf("%s\n", res);
}
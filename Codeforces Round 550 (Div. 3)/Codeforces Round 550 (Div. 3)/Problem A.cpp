#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
int n, b[27], tcn, sw, i;
char a[1001];
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		string answer = "Yes";
		scanf("%s", &a);
		n = strlen(a);
		for (int i = 1; i <= 26; i++) b[i] = 0;
		for (int i = 0; i < n; i++) {
			b[a[i] - 96]++;
			if (b[a[i] - 96] == 2) {
				answer = "No";
				break;
			}
		}
		if (answer == "Yes") {
			sw = 0;
			for (i = 1; i <= 26; i++) {
				if (sw == 1 && b[i]==1 && b[i] + b[i - 1] != 2) break;
				if (sw == 0 && b[i] == 1) {
					sw = 1;
				}
			}
			if (i != 27) answer = "No";
		}
		cout << answer << endl;
	}
}
#include<map>
#include<set>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<functional>
using namespace std;
map<char, int> hex_to_dec = { {'0', 0},{ '1', 1 },{ '2', 2 },{ '3', 3 },{ '4', 4 },{ '5', 5 },{ '6', 6 },{ '7', 7 },{ '8', 8 },{ '9', 9 },{ 'A', 10 },{ 'B', 11 },{ 'C', 12 },{ 'D', 13 },{ 'E', 14 },{ 'F', 15 } };
set<int> check;
vector<int> passwords;
int password[40], n, k;
void get_input() {
	char val;
	scanf("%d %d", &n, &k);
	getchar();
	for (int i = 1; i <= n; i++) {
		scanf("%c", &val);
		password[i] = hex_to_dec[val];
	}
	for (int i = n + 1; i <= n + n / 4; i++) {
		password[i] = password[i - n];
	}
}
void find_passwords() {
	check.clear();
	passwords.clear();
	int m = n / 4, sum, x;
	for (int i = 1; i <= n; i++) {
		sum = 0;
		x = 1;
		for (int j = i + m - 1; j >= i; j--) {
			sum += (x*password[j]);
			x *= 16;
		}
		if (check.find(sum) == check.end()) {
			passwords.push_back(sum);
			check.insert(sum);
		}
	}
}
int main() {
	int tcn;
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		get_input();
		find_passwords();
		sort(passwords.begin(), passwords.end(), greater<int>());
		printf("#%d %d\n", tc, passwords[k - 1]);
	}
}
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int tcn, n, k, sw_a, sw_b;
int a[110], b[110], divideinto[13][2] = { {0, 0}, {0, 1}, {1, 1}, {1, 2}, {2, 2}, {2, 3}, {3, 3}, {2, 5}, {3, 5}, {3, 6}, {5, 5}, {5, 6}, {6, 6} };
string s, res_a, res_b;
int main() {
	cin >> tcn;
	for (int tc = 1; tc <= tcn; tc++) {
		cin >> s;
		n = s.length();
		for (int i = n - 1; i >= 0; i--) {
			k = s[i] - 48;
			if (k <= 0 && i == 0) break;
			if (k <= 1 && i != 0) {
				s[i - 1]--;
				k += 10;
			}
			a[i] = divideinto[k][0];
			b[i] = divideinto[k][1];
		}
		res_a.clear();
		res_b.clear();
		sw_a = sw_b = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] != 0) sw_a = 1;
			if (sw_a == 1) res_a += (a[i] + 48);
			if (b[i] != 0) sw_b = 1;
			if (sw_b == 1) res_b += (b[i] + 48);
			a[i] = b[i] = 0;
		}
		cout<<"Case #"<<tc<<": "<<res_a<<" "<<res_b<<endl;
	}
}
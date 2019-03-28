#include<iostream>
using namespace std;
int tcn, n, wall[5000010], m, sum, mx;
int main() {
	cin >> tcn;
	for (int tc = 1; tc <= tcn; tc++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			char temp;
			cin >> temp;
			wall[i] = temp-48;
		}
		m = (n + 1) / 2;
		sum = 0;
		mx = -1;
		for (int i = 1; i <= n; i++) {
			if(i<=m) sum += wall[i];
			else {
				if (sum > mx) mx = sum;
				sum -= wall[i - m];
				sum += wall[i];
			}
		}
		if (sum > mx) mx = sum;
		cout << "Case #" << tc << ": " << mx << endl;
	}
	return 0;
}
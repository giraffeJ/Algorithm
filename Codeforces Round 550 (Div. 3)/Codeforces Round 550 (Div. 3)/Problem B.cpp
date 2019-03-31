#include<stdio.h>
#include<algorithm>
using namespace std;
int n, a[2010], odd[2010], even[2010], oddn, evenn, res, k;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] % 2 == 1) odd[++oddn] = a[i];
		else even[++evenn] = a[i];
	}
	sort(odd + 1, odd + oddn + 1);
	sort(even + 1, even + evenn + 1);
	res = 0;
	if (oddn > evenn) {
		k = oddn - evenn - 1;
		for (int i = 1; i <= k; i++) {
			res += odd[i];
		}
	}
	else if (evenn > oddn) {
		k = evenn - oddn - 1;
		for (int i = 1; i <= k; i++) {
			res += even[i];
		}
	}
	printf("%d\n", res);

}
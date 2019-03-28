#include<map>
#include<string>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char a[1001];
map<string, int> str_check;
string arr[90000];
int tcn, m, n, an;
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%d", &m);
		scanf(" %s", &a);
		n = strlen(a);
		an = 0;
		for (int i = 0; i < n; i++) {
			string temp = "";
			for (int j = i; j < n; j++) {
				temp += a[j];
				if (str_check.find(temp) == str_check.end()) {
					str_check[temp] = 1;
					arr[++an] = temp;
				}
			}
		}
		if (m > an) printf("#%d none\n", tc);
		else {
			sort(arr + 1, arr + an + 1);
			printf("#%d ", tc);
			for (int i = 0; i < arr[m].size(); i++)
				printf("%c", arr[m][i]);
			printf("\n");
		}
		str_check.clear();
	}
	return 0;
}
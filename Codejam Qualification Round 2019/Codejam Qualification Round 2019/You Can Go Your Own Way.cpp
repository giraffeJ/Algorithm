#include<string>
#include<iostream>
using namespace std;
int tcn, n;
string l_path, m_path;
int main() {
	cin >> tcn;
	for (int tc = 1; tc <= tcn; tc++) {
		cin >> n >> l_path;
		m_path.clear();
		for (int i = 0; i < n * 2 - 2; i++) {
			if (l_path[i] == 'S') m_path += 'E';
			if (l_path[i] == 'E') m_path += 'S';
		}
		cout << "Case #" << tc << ": " << m_path << endl;
	}
}
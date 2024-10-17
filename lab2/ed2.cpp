#include <bits/stdc++.h>

using namespace std;
 
int main () {
	//ios::sync_with_stdio(0); cin.tie(0);
	int n, len = 0;
	int count[100] = {0};

	cin >> n;
	cin.ignore();

	while (n--) {

		string s;
		getline(cin, s);
		for (int i = 0; i < s.length(); ++i) {
			if (isalpha(s[i])) {
				len++;
				count[toupper(s[i])]++;
			}
		}

	}
	
	for (int j = len; j >= 1; --j) {
		for (char i = 'A'; i <= 'Z'; ++i) {
			if (count[i] == j) {
				cout << i << " " << count[i] << endl;
			}
		}
	}
}
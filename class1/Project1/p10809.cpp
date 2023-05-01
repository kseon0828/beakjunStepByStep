#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string s;
	int charCnt[26] = { -1 };
	fill(charCnt, charCnt + 26, -1);

	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (charCnt[(int)s[i] - 'a'] == -1) {
			charCnt[(int)s[i] - 'a'] = i;
		}

		/*
		if (charCnt[s.at(i) - 'a'] == -1) {
			charCnt[s.at(i) - 'a'] = i;
		}
		*/
		else continue;
	}

	for (int i : charCnt) cout << i << ' ';


	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, result = 0;
	string s;

	cin >> n >> m >> s;

	for (int i = 1; i < s.length(); i++) {
		int cnt = 0;

		if (s[i - 1] == 'I') {
			while (s[i] = 'O' && s[i + 1] == 'I') {
				i += 2;
				cnt++;
				if (cnt == n) {
					cnt--;
					result++;
				}
			}
		}
	}

	cout << result << "\n";
}

/*
* 50Á¡ Ç®ÀÌ
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, cnt=0;
	string s, target = "I";

	cin >> n >> m >> s;

	for (int i = 0; i < n; i++) {
		target += "OI";
	}

	if (s.find(target) == string::npos) {
		cout << 0;
		return 0;
	}

	int idx;
	while (s.find(target) != string::npos) {
		cnt++;
		idx = s.find(target);
		s = s.substr(idx + 1);
	}

	cout << cnt;

	return 0;
}
*/
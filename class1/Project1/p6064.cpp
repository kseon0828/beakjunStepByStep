#include <bits/stdc++.h>
using namespace std;

int minMul(int x, int y) {
	int minValue = min(x, y);
	int minMul=1;
	for (int i = 2; i <= minValue; i++) {
		if (x % i == 0 && y % i == 0) {
			minMul = i;
		}
	}

	return minMul;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testCase, m, n, x, y;

	cin >> testCase;

	while (testCase--) {
		cin >> m >> n >> x >> y;

		int kMaxRnage = (m*n)/minMul(m, n);

		for (; x <= kMaxRnage; x += m) {
			if ((x - 1) % n + 1 == y || x > kMaxRnage) break;
		}
		if (x > kMaxRnage) cout << -1 << "\n";
		else cout << x << "\n";
	}

	return 0;
}
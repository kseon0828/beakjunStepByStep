#include <bits/stdc++.h>
using namespace std;

int dp[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	int i, j;

	cin >> n >> m;

	int inputNum;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> inputNum;
		dp[i] = dp[i - 1] + inputNum;
	}

	while (m--) {
		cin >> i >> j;
		cout << dp[j] - dp[i-1] << '\n';
	}

	return 0;
}
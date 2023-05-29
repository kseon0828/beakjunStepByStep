#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first)
		return true;
	else if (a.first == b.first) {
		if (b.second < b.second)
			return true;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, y;
	vector<pair<int, int>> v;

	cin >> n;

	while (n--) {
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end());

	for (auto i : v) {
		cout << i.first << ' ' << i.second << '\n';
	}

	return 0;
}
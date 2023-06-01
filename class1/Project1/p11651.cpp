#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int>b) {
	//오름차순
	if (a.second < b.second)
		return true;
	else if (a.second == b.second) {
		if (a.first < b.first)
			return true;
	}
	return false;
}

int main() {
	int n, x, y;
	vector<pair<int, int>> v;

	cin >> n;

	while (n--)
	{
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end(), compare);

	for (auto i: v) {
		cout << i.first << " " << i.second << '\n';
	}

	return 0;
}
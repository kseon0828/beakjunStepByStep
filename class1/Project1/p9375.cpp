#include <bits/stdc++.h>
using namespace std;

map <string, int> _map;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testCase, n;
	string inputClothes, clothesType;

	cin >> testCase;
	while (testCase--) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> inputClothes >> clothesType;

			if (_map.find(clothesType) != _map.end()) {
				_map[clothesType]++;
			}
			else {
				_map.insert({ clothesType, 1 });
			}
		}

		int result = 1;

		for (auto i : _map) {
			result *= (i.second + 1);
		}

		cout << result - 1 << "\n";

		_map.clear();
	}

	return 0;
}